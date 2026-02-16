---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

# Project 1: System Call

In this project you will learn hands-on how system calls work and how the kernel interacts with hardware via memory-mapped I/O. Concretely, you will add new system calls to the kernel, which control the on-board LED of the Pi.
Note that the Pi already has drivers for this purpose that could easily be used. It is not the point of the project
to control the LED with existing drivers, but rather to build it up from scratch.

Follow first the instructions to [set up the Pi](pi). Turn off the LED as described there.

{% include box.html style="bg-warning" text="This project cannot be done in one day. The building process itself takes a significant amount of time. You need to plan in enough time for it." %}

### User mode hack

To understand how we can access devices via memory-mapped I/O, read [this article](https://www.codeembedded.com/blog/raspberry_pi_gpio/). It describes how the GPIO pins of the Pi are controlled, but the same is true for the LED, which in fact is wired into the CPU as one of the GPIO pins. Its pin number is 29. You can find [here](projects/leds.c) an adapted version of the source code, which is ready to be used with the Pi.
On the Pi download the source file with
```
wget https://larsrohwedder.com/teaching/dm510-26/projects/leds.c
```
Make sure the LED is turned off as described above.
Compile and execute the program:
```
gcc -o leds leds.c
sudo ./leds
```
You should see the led blinking. Stop the process using Ctrl+C.
For many reasons it is not a good idea to directly write to raw physical memory in user programs. We will implement a similar control in the kernel.

### Kernel mode implementation

Follow the instructions [here](kernel) to download, build and run your own custom version of the Linux kernel.
Then follow the instructions [here](syscall) to understand how to add new system calls. Design a system call
interface for controlling the LED (turning it on or off) and add the corresponding function stubs to the kernel,
first without the implementation.

On a high level, you will control the LED in a similar way to the user mode hack: by writing to the physical memory addresses. When kernel code executes, it does not run in the raw physical memory space. That means for example that dereferencing pointer `10` will not read/write to the physical address `10`, but to some other address that you have no control over. In the user mode hack the workaround was to map `/dev/mem` to some memory section via `mmap`.
This is not the safe way to do it and in particular is not feasible to do from kernel code.
Instead, use the functions `ioremap()`, `iowrite32()`, and `iounmap()` as described in the [hardware chapter](https://static.lwn.net/images/pdf/LDD3/ch09.pdf) of the Linux driver manual.

### Testing your system calls

Write a user program that rigorously tests the functionality of your system calls, including for example invalid
inputs (if appropriate).

### Submission

Submit via itslearning the following:
- Source code of the implementation of your system calls: all files with `SYSCALL_DEFINE` in it. You do not need to include header files, etc.
- Source code of the user program(s) that test your system calls.  
- A video recording from your phone that shows how you invoke `uname -r` on your terminal and then how you execute your user program(s). Move the camera between screen and Pi to show how the LED changes.
- A pdf with answers to the questionaire below and possibly appendices.

**Questionaire:**

- Did you manage to get the Pi to run and log into it using SSH?
- Did you manage to run the user mode hack?
- Did you manage to recompile the kernel and boot it?
- Did you manage to add system calls to the kernel and invoke them?
- Did you manage to turn the LED on and off via your own system calls?

If your answer is no to some of these questions, you may include explanation on which problems you ran into.
It is intentional that there is no excessive report on the project. All design decisions that you made should be documented in the source code itself.  

**Assessment:**

The project will be graded based on the following:

- **Functionality:** How much of the required functionality did you manage to implement?
- **Style:** Is the programming style appropriate and is the code well documented?
- **Tests:** Are you testing all aspects of the newly implemented system calls?

