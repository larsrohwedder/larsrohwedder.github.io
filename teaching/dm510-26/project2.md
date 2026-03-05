---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

# Project 2: Kernel Module

In this assignment your task is to create driver for the Raspberry Pi that exposes a character device `/dev/morse` to the user. When a user writes into `/dev/morse`, the message should be transmitted via Morse code
on the LED. Morse code is an old standard for transmitting text via a series of short and long signals. You can find all necessary instructions on this encoding in the image below. 

![Morse](img/morse.png)

### Drivers in Linux



### Requirements

- You should either use a major number of 255 and minor number of 0.
- There must be an output buffer.
- Blocking and non-blocking I/O must be supported (see Chapter 6 of LDD, page 147ff).
- Only one process at the time should be able to open the device for writing.
- Simple device control has to be possible via the ioctl system call. Implement at least a way to set the unit duration of the Morse transmission and the size of the output buffer.

The following is not required:
- udev and devfs support.
- Poll, select and asynchronous notification support (see Chapter 6 of LDD).

### Submission

Submit via itslearning the following:
- Source code of the implementation of your system calls: all files with `SYSCALL_DEFINE...` in it. You do not need to include header files, etc.
- Source code of the user program(s) that test your system calls.  
- A video recording from your phone that shows how you invoke `uname -r` on your terminal and then how you execute your user program(s). Move the camera between screen and Pi to demonstrate how the LED changes.
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

- **Functionality:** Did you implement the required functionality and is the implementation correct?
- **Style:** Is the programming style appropriate and is the code well documented?
- **Tests:** Are you testing all aspects of the newly implemented system calls?

