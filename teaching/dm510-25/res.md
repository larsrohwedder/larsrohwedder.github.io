---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

### Course Textbook

Abraham Silberschatz, Peter Baer Galvin, Greg Gagne: [Operating System Concepts 10th edition](https://codex.cs.yale.edu/avi/os-book/OS10/index.html), Wiley, 2018.

Note, that there is an International and a US version of the book. It should not be important if you use the US or the international version.

### Course-Specific Instructions

For the programming projects you need access to a computer or virtual machine running Linux. If you have a computer that runs Linux, you can use that. Other options are to use remote access to the IMADA virtual computer lab or to install a virtual machine on your own computer (running a potentially different operating system).
- [IMADA virtual computer lab](lab)
- [Installing a virtual machine](vm)

In the projects we are using User-Mode Linux. A guide on getting started with it can be found below.
- [User-Mode Linux](uml)

For the projects you also need to get familiar with system calls in linux. Below is a guideline on implementing a trivial system call
- [System call in linux](syscall)

### Command-line Tools used in course
Below is a (growing) overview of Linux tools (mostly command-line) used throughout the lectures.

- file tree navigation and modification in command line: `cd` to change the current directory, `ls` to list contents of current directory, `mv` to move a file, `mkdir` to create a new directory, `rm` to remove a file or directory.
- file access and modification: `cat` prints out contents of file, `vi` (advanced) and `nano` (simple) are useful command line text editors.
- system status: `top` monitors resource usage of various processes (CPU, memory, etc.)
- pipes: using the `|` symbol we can forward the output of one process to the input of the other. For example, `cat test.txt | grep "42"` prints all lines of the file test.txt that contain 42.
- [bpftrace](bpftrace): tracing tool for Unix/Linux systems
