---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 1

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 1
1. Name three central purposes of an operating system.
2. What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?
3. Consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answers.
4. How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security)?
5. Which of the following instructions should be privileged?
    a. Set value of timer.
    b. Read the clock.
    c. Clear memory.
    d. Issue a trap instruction.
    e. Turn off interrupts.
    f. Modify entries in device-status table.
    g. Switch from user to kernel mode.
    h. Access I/O device.
6. Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?
7. Give two reasons why caches are useful. What problems do they solve? What problems do they cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device?
8. How do clustered systems differ from multiprocessor systems? What is required for two machines belonging to a cluster to cooperate to provide a highly available service?
9. **(important)** What is the purpose of interrupts? How does an interrupt differ from a trap? Can traps be generated intentionally by a user program? If so, for what purpose?
10. Direct memory access is used for high-speed I/O devices in order to avoid increasing the CPU’s execution load.
    - How does the CPU interface with the device to coordinate the transfer?
    - How does the CPU know when the memory operations are complete?
    - The CPU is allowed to execute other programs while the DMA controller is transferring data. Does this process interfere with the execution of the user programs? If so, describe what forms of interference are caused.
11. **(important)** Rank the following storage systems from slowest to fastest:
    a. Hard-disk drives
    b. Registers
    c. Optical disk
    d. Main memory
    e. Nonvolatile memory
    f. Magnetic tapes
    g. Cache
12. Describe some of the challenges of designing operating systems for mobile devices compared with designing operating systems for traditional PCs.

### Related to Chapter 2
13. **(important)** What is the purpose of system calls?
14. What system calls have to be executed by a command interpreter or shell in order to start a new process on a UNIX system?
15. What is the purpose of system programs?
16. What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?
17. List three services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.
18. How could a system be designed to allow a choice of operating systems from which to boot? What would the bootstrap program need to do?
19. What are the advantages and disadvantages of using the same system-call interface for manipulating both files and devices?
20. Describe why Android uses ahead-of-time (AOT) rather than just-in-time (JIT) compilation.
21. How are iOS and Android similar? How are they different?
22. What are the two models of interprocess communication? What are the strengths and weaknesses of the two approaches?
23. What is the main advantage of the microkernel approach to system design? How do user programs and system services interact in a micro-kernel architecture? What are the disadvantages of using the microkernel approach?

### C Programming (refreshing skills)
24. Which of the following is the proper declaration of a pointer?
    - `int x;`
    - `int &x;`
    - `ptr x;`

int *x;

Which of the following gives the memory address of integer variable a?

*a;

a;

&a;

address(a);

Which of the following gives the memory address of a variable pointed to by pointer a?

a;

*a;

&a;

address(a);

Which of the following gives the value stored at the address pointed to by pointer a?

a;

val(a);

*a;

&a;

Which of the following is the proper keyword or function to allocate memory in C?

new

malloc

create

value

Which of the following is the proper keyword or function to deallocate memory?

free

delete

clear

remove
