---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 8

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 12
1. State three advantages of placing functionality in a device controller, rather than in the kernel. State three disadvantages. For example, a network card could implement part of the TCP/IP protocol or it could only expose the physical bit stream and the CPU implements the protocol.
2. Why might a system use interrupt-driven I/O to manage a single serial port (connecting for example to a keyboard) and polling I/O to manage incoming network traffic
3. How does DMA increase system concurrency? How does it complicate hardware design?
4. Why is it important to scale up system-bus and device speeds as CPU speed increases?
6. **(important)** Describe three circumstances under which blocking I/O should be used. Describe three circumstances under which nonblocking I/O should be used. Why not just implement nonblocking I/O and have processes busy-wait until their devices are ready?

### Related to Chapter 19
1. Why would it be a bad idea for routers to pass broadcast packets between networks?
2. The original HTTP protocol used TCP/IP as the underlying protocol. For each page, graphic, or applet, a separate TCP session was constructed, used, and torn down. Because of the overhead of building and destroying TCP/IP connections, performance problems resulted from this implementation method. Would using UDP rather than TCP be a good alternative? What other changes could you make to improve HTTP performance?
3. **(important)**Name three advantages/applications of using UDP over TCP.
4. **(important)**Name three advantages/applications of using TCP over UDP.
5. Communication between two processes on the same computer can be done for example using message passing system calls provided by the operating system. Alternatively, one could open a TCP connection between the two processes by connecting to the special "localhost" IP address (127.0.0.1 in IPv4 or ::1 in IPv6). Discuss advantages and disadvantages of either approach.
6. HTTP servers that host websites typically use port 80 (in the TCP protocol). Suppose we want to use a single computer to host two different websites. Explain the problem and two possible solutions for it.
7. An Ethernet packet with incorrect checksum is discarded, which means that higher protocol layers usually retransmit the packet. One could implement error-correcting codes / redundancy (similar to RAID) to repair the message in case of a bit error. What would be advantages and disadvantages of such a hypothetical approach?
8. The IPv4 (Internet Protocol version 4) has been in widespread use for decades and still is. An IP address in IPv4 is of the form x.x.x.x where each x ranges from 0 to 255. In IPv6 an address is given as 8 blocks of 4 hexadecimal digits each, i.e., xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx where each x ranges from 0 to F. Calculate the theoretical number of different addresses in IPv4 and IPv6 and interpret them.
9. Even when only a single message needs to be transmitted, TCP is used much more often than UDP. What is the difference (in functionality) of sending a single UDP package to opening a TCP connection, sending the package, and then closing it?

### In class
Discuss the exercises prepared at home
