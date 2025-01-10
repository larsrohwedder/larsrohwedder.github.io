---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

### Project 1: System Call

## Introduction
In this assignment, your task is to add system calls to User-mode Linux (UML), that implement a message box in kernel space.

{: .card .text-white .bg-warning .mb-3 }
Before staring working on this assignment, make sure you have a running user mode linux kernel, and that you followed the description of how to add a Linux system call. The system calls that you have to implement are more complex and useful.

## The System Calls
Message passing is a method of interprocess communication. Basically, the idea is that processes send small messages / byte arrays to each other using either the operating system or in some other way (e.g., MPI). Often this way of communication is used in distributed systems or in general when shared memory is not possible. Message-passing systems in general is covered in Section 3.6 in the Operating System Concepts book.

Your task is to make two system calls that give processes access to a small message box residing in kernel-space. The system calls must make it possible to retrieve messages from the message box into the address-space (user-space) of the calling process. Also, it must be possible to write a message from the calling process into the message box.

To make things simple the message box should be implemented as a stack, i.e., incoming messages are put at the top of the stack, and outgoing messages are also read from the top of the stack. Messages are only to be read once, i.e., they are removed from the stack immediately after retrieval.

## Simple user-space version
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

static msg_t *bottom = NULL;
static msg_t *top = NULL;

int dm510_msgbox_put( char *buffer, int length ) {
  msg_t* msg = malloc(sizeof(msg_t));
  msg->previous = NULL;
  msg->length = length;
  msg->message = malloc(length);
  memcpy(msg->message, buffer, length);

  if (bottom == NULL) {
    bottom = msg;
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

    /* copy message */
    memcpy(buffer, msg->message, mlength);

    /* free memory */
    free(msg->message);
    free(msg);

    return mlength;
  }
  return -1;


}

int main ( void ) {
  /* test code here */
  return 0;
}
{% endhighlight %}

Below is an example to illustrate the use of the function.

**example.c**
{% highlight C %}
int main(int argc, char** argv) {
  char *in = "This is a stupid message.";
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

## Approaching the Problem
You could try to insert the `dm510_msgbox_put` and `dm510_msgbox_get` function directly into the kernel, but this would not work. In order to make it work you must address the following issues.

Note: all the functions mentioned below, can be used in your own kernel source file, if you include **linux/slab.h** and **linux/uaccess.h**.






