---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 11

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 18
1. Describe the three types of traditional hypervisors.
2. Dual-/Multi-booting refers to the mechanism that a computer has several operating systems installed on different partitions of the hard drive and the user can choose the operating system in the bootloader. Name situations where dual-booting or VMMs are better suited.
2. Describe four virtualization-like execution environments, and explain how they differ from "true" virtualization.
3. Why are VMMs unable to implement trap-and-emulate-based virtualization on some CPUs? Lacking the ability to trap and emulate, what method can a VMM use to implement virtualization?
4. What hardware assistance for virtualization can be provided by modern CPUs?
5. What is Docker? What is a Docker image? What is a Docker container?
6. **(important)** Consider the following environments:
    - A traditional computer without virtualization
    - A type-1 VMM
    - A type-2 VMM
    - A Docker container
    Explain for each of the following use cases, how well each of the four environments are suited for it:
    - A scientific simulation (CPU bound high-performance application)
    - Testing the effects of a program suspected to be malicious 
    - A video game
    - Testing your modifications to the Linux kernel
    - A webserver for a sporadically visited website
7. Suppose that for load balancing reasons a cloud application should be moved from an overloaded server to another less busy server. Consider the following approach:
    - The application is asked gracefully to save its data on the hard drive and to terminate. This data is copied to the other server and the application is started again there.
    - Live migration
    Compare the two approaches.
9. In the programming projects you have been introduced to User-Mode Linux. Compare it to the different hypervisor types and virtualization-like execution environments and argue which one it is most similar to.
10. Imagine a hypothetical "container-based" operating system, where each application (web browser, text editor, etc.) is distributed as a Docker container. Of such an operating system concept,
    name two advantages and name two disadvantages. Judge whether this would be a feasible concept.

### In class
Discuss the exercises prepared at home
