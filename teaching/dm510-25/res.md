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

### Command-line tools, programs, and examples used in course
Below is a (growing) overview of Linux tools (mostly command-line) used throughout the lectures.

- file tree navigation and modification in command line: `cd` to change the current directory, `ls` to list contents of current directory, `mv` to move a file, `mkdir` to create a new directory, `rm` to remove a file or directory.
- more navigation: `pushd <dir>` works like `cd`, but it saves previous directory and we can go back using `popd`.
- links: create a hard link with `ln` and soft link with `ln -s`.
- file access and modification: `cat` prints out contents of file, `vi` (advanced) and `nano` (simple) are useful command line text editors. `>` can be used to write into a file, e.g. `echo "hello" > samplefile`. 
- system status: `top` monitors resource usage of various processes (CPU, memory, etc.)
- processes: `ps -e` lists current processes. `pstree` displays the parent-child relationships of processes as a tree. `cat /proc/<pid>/status` displays status information about a process (for example, number of context swithes)
- pipes: using the `|` symbol we can forward the output of one process to the input of the other. For example, `cat test.txt | grep "42"` prints all lines of the file test.txt that contain 42. `mkfifo <name>` creates a named pipe in the filesystem into which processes can read and write
- `time <command>`: executes command and outputs time used for it
- processor information: `cat /proc/cpuinfo` outputs various information about CPU architecture
- [bpftrace](bpftrace): tracing tool for Unix/Linux systems
- scheduling/priority: `renice -n <niceness> <pid>` changes the niceness of a process (which affects directly the scheduling priority). `nice -n <niceness> <command>` runs `<command>` with the specified niceness.
- network: `nc <ipaddress> <port>` establishes tcp connection. `ifconfig` shows network card status, e.g. ip address and MAC address.
- communication:
    - Producer-consumer with shared memory: [shm-producer.c](shm-producer.c), [shm-consumer.c](shm-consumer.c)
    - Producer-consumer with named pipe (create pipe first with `mkfifo dm510_fifo`): [np-producer.c](np-producer.c), [np-consumer.c](np-consumer.c)
    - Producer-consumer with ordinary pipe: [op-producer-consumer.c](op-producer-consumer.c)
- parallelization:
    - sequential matrix multiplication: [mat-mult.c](mat-mult.c)
    - two separate matrix multiplications in two separate threads [pthread.c](pthread.c)
    - OpenMP parallelization of matrix multiplication (compile with `gcc -fopenmp`) [openmp.c](openmp.c)
    - Using SIMD instructions for matrix multiplication [sse.c](sse.c)
- synchronization:
    - via OpenMP: [crit-section.c](crit-section.c)
    - via pthread mutex: [mutex.c](mutex.c)
    - via atomic instructions (compare-and-exchange): [atomic.c](atomic.c)
- device access:
    - Random access via lseek: [seek.c](seek.c)
    - Random access via mmap: [mmap.c](mmap.c)
