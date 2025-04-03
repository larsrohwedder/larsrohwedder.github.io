---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 9

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 13 (first lecture)
1. Could you simulate a tree directory structure with a directory in which arbitrarily long names can be used? If your answer is yes, explain how you can do so, and contrast this scheme with the tree directory scheme. If your answer is no, explain what prevents your simulation’s success. How would your answer change if file names were limited to seven characters?
2. Consider a system that supports 5,000 users. Suppose that you want to allow 4,990 of these users to be able to access one file. How would you specify this protection scheme in Unix?
5. Can you suggest another protection scheme that can be used more effectively for this purpose than the scheme provided by Unix?
6. Explain the following Unix protection settings and translate them into the other (decimal or rwx) notation
    - rwxr--r--
    - 755
    - rwxr-x---
7. (**important**) Provide examples of applications that typically access files according to the following methods:
    - Sequential
    - Random
    - Index
8. If the operating system knew that a certain application was going to access file data in a sequential manner, how could it exploit this information to improve performance?

### Related to Chapter 15 (first lecture)
1. Explain how the VFS layer allows an operating system to support multiple types of file systems easily.
2. (**important**) Discuss why it may be necessary to have more than one file system type on a given system.
3. Why do operating systems mount the root file system automatically at boot time?

### Related to Chapter 14 (second lecture)
1. Consider a file currently consisting of 100 blocks. Assume that the file-control block (and the index block, in the case of indexed allocation) is already in memory. Calculate how many disk I/O operations are required for contiguous, linked, and indexed (single-level) allocation strategies, if, for one block, the following conditions hold. In the contiguous-allocation case, assume that there is no room to grow at the beginning but there is room to grow at the end. Also assume that the block information to be added is stored in memory.
    - The block is added at the beginning.
    - The block is added in the middle.
    - The block is added at the end.
    - The block is removed from the beginning.
    - The block is removed from the middle.
    - The block is removed from the end.
2. (**important**) Why must the bit map for file allocation be kept on mass storage, rather than in main memory?
3. Consider a system that supports the strategies of contiguous, linked, and indexed allocation. What criteria should be used in deciding which strategy is best utilized for a particular file?
4. Consider a file system that uses a modified contiguous-allocation scheme with support for extents. A file is a collection of extents, with each extent corresponding to a contiguous set of blocks. A key issue in such systems is the degree of variability in the size of the extents. What are the advantages and disadvantages of the following schemes?
    - All extents are of the same size, and the size is predetermined.
    - Extents can be of any size and are allocated dynamically.
    - Extents can be of a few fixed sizes, and these sizes are predetermined.
5. Contrast the performance of the three techniques for allocating disk blocks (contiguous, linked, and indexed) for both sequential and random file access.
6. Discuss how performance optimizations for file systems might result in difficulties in maintaining the consistency of the systems in the event of computer crashes.
7. (**important**)Consider a file system on a disk that has both logical and physical block sizes of 512 bytes. Assume that the information about each file is already in memory. For each of the three allocation strategies (contiguous, linked, and indexed), answer these questions:
    - How is the logical-to-physical address mapping accomplished in this system? (For the indexed allocation, assume that a file is always less than 512 blocks long.)
    - If we are currently at logical block 10 (the last block accessed was block 10) and want to access logical block 4, how many physical blocks must be read from the disk?
8. Consider a file system that uses inodes to represent files. Disk blocks are 8 KB in size, and a pointer to a disk block requires 4 bytes. This file system has 12 direct disk blocks, as well as single, double, and triple indirect disk blocks. What is the maximum size of a file that can be stored in this file system?


### In class
Discuss the exercises prepared at home
