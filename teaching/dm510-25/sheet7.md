---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 7

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 11

1. Explain why SSTF (Shortest Seek Time First) scheduling tends to favor middle cylinders over the innermost and outermost cylinders.

2. Why is it important to balance file-system I/O among the disks and controllers on a system in a multitasking environment?

3. What are the tradeoffs involved in rereading code pages from the file system versus using swap space to store them?

4. RAID can be used to protect against data loss. Give two examples where data loss may happen despite using RAID.

5.  **(important)** It is sometimes said that tape is a sequential-access medium, whereas a hard disk is a random-access medium. In fact, the suitability of a storage device for random access depends on the transfer size. The term streaming transfer rate denotes the rate for a data transfer that is underway, excluding the effect of access latency. In contrast, the effective transfer rate is the ratio of total bytes to total seconds, including overhead time such as access latency. Suppose we have a computer with the following characteristics: the level-2 cache has an access latency of 8 nanoseconds and a streaming transfer rate of 800 megabytes per second, the main memory has an access latency of 60 nanoseconds and a streaming transfer rate of 80 megabytes per second, the hard disk has an access latency of 15 milliseconds and a streaming transfer rate of 5 megabytes per second, and a tape drive has an access latency of 60 seconds and a streaming transfer rate of 2 megabytes per second.
    - Random access causes the effective transfer rate of a device to decrease, because no data are transferred during the access time. For the disk described, what is the effective transfer rate if an average access is followed by a streaming transfer of (1) 512 bytes, (2) 8 kilobytes, (3) 1 megabyte, and (4) 16 megabytes?
    - The utilization of a device is the ratio of effective transfer rate to streaming transfer rate. Calculate the utilization of the disk drive for each of the four transfer sizes given in part 1.
    - Suppose that a utilization of 25 percent (or higher) is considered acceptable. Using the performance figures given, compute the smallest transfer size for a disk that gives acceptable utilization.
    - Complete the following sentence: A disk is a random access device for transfers larger than ... bytes and is a sequential-access device for smaller transfers.
    - Compute the minimum transfer sizes that give acceptable utilization for cache, memory, and tape.
    - When is a tape a random-access device, and when is it a sequential-access device?

6. Could a RAID level 1 organization achieve better performance for read requests than a RAID level 0 organization (with nonredundant striping of data)? If so, how?

7. Give three advantages (can be specific applications) of HDDs as secondary storage.

8. Give three advantages (can be specific applications) of NVM devices as secondary storage.

9. None of the disk-scheduling disciplines, except FCFS, is truly fair (starvation may occur).
    - Explain why this assertion is true.
    - Describe a way to modify algorithms such as SCAN to ensure fairness.
    - Explain why fairness is an important goal in a multi-user systems.

10. Give three or more examples of circumstances in which it is important that the operating system is unfair in serving I/O requests.

11. Suppose that a disk drive has 5,000 cylinders, numbered 0 to 4,999. The drive is currently serving a request at cylinder 2,150, and the previous request was at cylinder 1,805. The queue of pending requests, in FIFO order, is: 2,069; 1,212; 2,296; 2,800; 544; 1,618; 356; 1,523; 4,965; 3,681 Starting from the current head position, what is the total distance (in cylinders) that the disk arm moves to satisfy all the pending requests for each of the following disk-scheduling algorithms?
    - FCFS
    - SCAN
    - C-SCAN

13. Consider a RAID level 5 organization comprising five disks, with the parity for sets of four blocks on four disks stored on the fifth disk. How many blocks are accessed in order to perform the following?
    - A write of one block of data
    - A write of seven continuous blocks of data

14. Assume that you have a mixed configuration comprising disks organized as RAID level 1 and RAID level 5 disks. Assume that the system has flexibility in deciding which disk organization to use for storing a particular file. Which files should be stored in the RAID level 1 disks and which in the RAID level 5 disks in order to optimize performance?

15. The reliability of a storage device is typically described in terms of mean time between failures (MTBF). Although this quantity is called a "time", the MTBF actually is measured in drive-hours per failure.
    - If a system contains 1,000 disk drives, each of which has a 750,000hour MTBF, which of the following best describes how often a drive failure will occur in that disk farm: once per thousand years, once per century, once per decade, once per year, once per month, once per week, once per day, once per hour, once per minute, or once per second?
    - (far-going camparison) Mortality statistics indicate that, on the average, a U.S. resident has about 1 chance in 1,000 of dying between the ages of 20 and 21. Deduce the MTBF hours for 20-year-olds. Convert this figure from hours to years. What does this MTBF tell you about the expected lifetime of a 20-year-old?
    - The manufacturer guarantees a 1-million-hour MTBF for a certain model of disk drive. What can you conclude about the number of years for which one of these drives is under warranty?

16. Discuss the reasons why the operating system might require accurate information on how blocks are stored on a HDD disk. How could the operating system improve file-system performance with this knowledge?

### In class
Discuss the exercises prepared at home
