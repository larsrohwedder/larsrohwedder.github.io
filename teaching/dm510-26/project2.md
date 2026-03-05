---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

# Project 2: Kernel Module

![Morse](img/morse.png)

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

