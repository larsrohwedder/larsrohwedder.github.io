---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Project 1: System Call

### Introduction
In this assignment, your task is to add system calls to the linux kernel that implement a message box in kernel space.
For convenience, you will work with *User-mode Linux (UML)*, which is a target architecture of Linux that let's you compile
the kernel into an executable that can be run in user-mode within another Linux host environment (similar to being run
inside a virtual machine, but simpler).

{% include box.html style="bg-warning" text="Before starting to work on this assignment, make sure you have access to a Linux system, in which you are running user-mode linux, and that you followed the description of how to add a simple system call. All of these requirements can be found on the [Resources page](resources)." %}

### The System Calls
Message passing is a method of interprocess communication. Basically, the idea is that processes send small messages / byte arrays to each other using either the operating system or in some other way (e.g., MPI). Often this way of communication is used in distributed systems or in general when shared memory is not possible. Message-passing systems in general are covered in Section 3.6 in the Operating System Concepts book.

Your task is to make two system calls that give processes access to a small message box residing in kernel-space. The system calls must make it possible to retrieve messages from the message box into the address-space (user-space) of the calling process. Also, it must be possible to write a message from the calling process into the message box.

To make things simple the message box should be implemented as a stack, i.e., incoming messages are put at the top of the stack, and outgoing messages are also read from the top of the stack. Messages are only to be read once, i.e., they are removed from the stack immediately after retrieval.

### Simple user-space version
The code below is a simple user-space version of the message box system call.

**dm510_msgbox.h**
{% highlight C %}
#ifndef __DM510_MSGBOX_H__
#define __DM510_MSGBOX_H__

int dm510_msgbox_put( char*, int );
int dm510_msgbox_get( char*, int );

#endif
{% endhighlight %}

**dm510_msgbox.c**
{% highlight C %}
#include "dm510_msgbox.h"
#include <stdlib.h>
#include <string.h>

typedef struct _msg_t msg_t;

struct _msg_t{
  msg_t* previous;
  int length;
  char* message;
};

static msg_t *top = NULL;

int dm510_msgbox_put( char *buffer, int length ) {
  msg_t* msg = malloc(sizeof(msg_t));
  msg->previous = NULL;
  msg->length = length;
  msg->message = malloc(length);
  memcpy(msg->message, buffer, length);

  if (top == NULL) {
    top = msg;
  } else {
    /* not empty stack */
    msg->previous = top;
    top = msg;
  }
  return 0;
}

int dm510_msgbox_get( char* buffer, int length ) {
  if (top != NULL) {
    msg_t* msg = top;
    int mlength = msg->length;
    top = msg->previous;

    if (length < mlength) {
      return -2;
    }

    /* copy message */
    memcpy(buffer, msg->message, mlength);

    /* free memory */
    free(msg->message);
    free(msg);

    return mlength;
  }
  return -1;


}
{% endhighlight %}

Below is an example to illustrate the use of the function.

**example.c**
{% highlight C %}
int main(int argc, char** argv) {
  char *in = "This is an example message.";
  char msg[50];
  int msglen;

  /* Send a message containing 'in' */
  dm510_msgbox_put(in, strlen(in)+1);

  /* Read a message */
  msglen = dm510_msgbox_get(msg, 50);

  return 0;
}
{% endhighlight %}

You have to implement two separate system calls:

Both, the `dm510_msgbox_put` and the `dm510_msgbox_get` system call shall have two parameters:
* `buffer`: In case of a message get, `buffer` is a pointer to the destination array, i.e., where to copy the message. In case of a putting a message, buffer is a pointer to the source array.
* `length`: An integer defining the length of the buffer.

The return value of the two system calls has to be implemented as follows:
* `dm510_msgbox_put`: If the message was appended to the queue without any problems, 0 should be returned. Otherwise some negative value should be returned (more about this later).
* `dm510_msgbox_get`: If a message was retrieved from the message box without any problems, the length of this message should be returned (note: this could be 0 in case of an empty message). Otherwise some negative value should be returned (more about this later).

### Approaching the Problem
You could try to insert the `dm510_msgbox_put` and `dm510_msgbox_get` function directly into the kernel, but this would not work. In order to make it work you must address the following issues.

Note: all the functions mentioned below, can be used in your own kernel source file, if you include **linux/slab.h** and **linux/uaccess.h**.

# Memory allocation
Memory allocation and deallocation in the Linux kernel is not done with the usual malloc and free. Instead you have to use kmalloc and kfree

For further information have a look at the corresponding linux kernel man pages for example here (or for more details here, potentially outdated).

# Address translation
An address from user-space does not map to the same physical address in kernel-space (cf. Operating System Concepts: Chapter 9). The Linux Kernel has special functions to translate user-space addresses in kernel-space. Three of these are particularly helpful for this assignment:

* `access_ok(char* addr, int n)`: Checks whether it is safe to read (or write) n bytes from the user space address addr.
* `copy_to_user(char* to, char* from, int n)`: Copies n bytes from the kernel address from to the user address to.
* `copy_from_user(char* to, char* from, int n)`: Copies n bytes from the user address from to the kernel address to.

For further information, have a look at the kernel API, for even more details look in Chapter 3 of the [Linux Device Driver book](https://lwn.net/Kernel/LDD3/) (pages 64-65).

# Parameter checking and error handling
The simple version above is not checking its parameters at all. This means that if you call the function with invalid parameters, e.g. a wrong `length < 0`, the function would fail or cause unpredictable results. A system call must not be able to fail uncontrolled, because it could bring the kernel down.

For example, a system call that does not check user addresses could unintentionally overwrite parts of the kernels memory, which would leave the kernel in an invalid state. The functions described in the previous section return a non-zero value if there are problems accessing user addresses. `kmalloc` returns a `NULL` pointer, if it is unable to allocate memory.

When a system call detects an error it has to return an error code to make the caller aware of what has happened. In case of an error the function that implements the system call must return the negative value of the code that defines the error. Error codes used by other system calls are defined in **include/uapi/asm-generic/errno.h** and **include/uapi/asm-generic/errno-base.h** and these will suffice for this assignment.

`man errno` and `man perror` describes how errors are handled in user-space.

# Concurrency
Unless special measures are taken any function in Linux including a system call may be interrupted. If the system call is in some critical region, this may cause problems. As an example of this, consider two processes that call the `dm510_msgbox` system call almost simultaneously. While the first process has partly updated the message box data structures with a new message, this process is interrupted, and the second process subsequently fails to update the data structures correctly.

To ensure that this does not happen, interrupts can be temporarily disabled using `local_irq_save` and `local_irq_restore`.
{% highlight C %}
unsigned long flags;

local_irq_save(flags);

/* critical region */

local_irq_restore(flags);
{% endhighlight %}
`local_irq_save` saves the current processor state and disables interrupts, `local_irq_restore` restores the processor state, including enabling interrupts. You can find the definition of these two macro’s (that is why it works with the flags parameter directly) in the file **include/linux/irqflags.h** and you can read a bit more (here)[https://litux.nl/mirror/kerneldevelopment/0672327201/ch06lev1sec7.html].

Later in the course you will learn how this could be done in a smarter way, e.g., by using semaphores. For more information, have a look at [Documentation/cli-sti-removal.txt](https://lwn.net/Articles/5512/).
