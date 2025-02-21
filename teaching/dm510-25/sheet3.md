---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 3

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 5
1. A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given n processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of n.
2. Explain the difference between preemptive and nonpreemptive scheduling.
3. Suppose that the following processes arrive for execution at the times indicated. Each process will run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made. 

    {: .table .table-striped}
    | Process |	Arrival Time | Burst Time |
    | ------- | ------------ | ---------- |
    | P1      | 0.0          | 8          |
    | P2      | 0.4          | 4          |
    | P3      | 1.0          | 1          |

    - What is the average response time for these processes with the FCFS scheduling algorithm?
    - What is the average response time for these processes with the SJF scheduling algorithm?
    - The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average response time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be known as future-knowledge scheduling.
4. Consider the following set of processes, with the length of the CPU burst time given in milliseconds:

    {: .table .table-striped}
    | Process |	Burst Time | Priority |
    | ------- | ---------- | -------- |
    | P1      | 2          | 3        |
    | P2      | 1          | 4        |
    | P3      | 8          | 1        |
    | P4      | 4          | 3        |
    | P5      | 5          | 2        |

    The processes are assumed to have arrived in the order P1, P2, P3, P4 , P5, all at time 0. Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, nonpreemptive priority (a lower number implies a higher priority), and RR (quantum = 2).
    - What is the response time of each process for each of the scheduling algorithms in part a?
    - What is the waiting time of each process for each of these scheduling algorithms?
    - Which of the algorithms results in the minimum average waiting time (over all processes)?
5. The following processes are being scheduled using a preemptive, round-robin scheduling algorithm.

    {: .table .table-striped}
    | Process |	Arrival | Burst Time | Priority |
    | ------- | ------- | ---------- | -------- |
    | P1      | 0       | 20         | 5        |
    | P2      | 25      | 25         | 30       |
    | P3      | 30      | 25         | 30       |
    | P4      | 60      | 15         | 10       |
    | P5      | 100     | 10         | 40       |
    | P6      | 105     | 10         | 35       |

    Each process is assigned a numerical priority, with a lower number indicating a higher priority. In addition to the processes listed below, the system also has an idle task (which consumes no CPU resources and is identified as Pidle). This task has priority 0 and is scheduled whenever the system has no other available processes to run. The length of a time quantum is 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.
    - Show the scheduling order of the processes using a Gantt chart.
    - What is the response time for each process?
    - What is the waiting time for each process?
    - What is the CPU utilization rate?
6. What advantage is there in having different time-quantum sizes at different levels of a multilevel queueing system?
7. Many CPU-scheduling algorithms are parameterized. For example, the RR algorithm requires a parameter to indicate the time slice. Multilevel feedback queues require parameters to define the number of queues, the scheduling algorithms for each queue, the criteria used to move processes between queues, and so on. These algorithms are thus really sets of algorithms (for example, the set of RR algorithms for all time slices, and so on). One set of algorithms may include another (for example, the FCFS algorithm is the RR algorithm with an infinite time quantum). What (if any) relation holds between the following pairs of algorithm sets?
    - Priority and SJF
    - Multilevel feedback queues and FCFS
    - Priority and FCFS
    - RR and SJF
8. Suppose that a CPU scheduling algorithm favors those processes that have used the least processor time in the recent past. Why will this algorithm favor I/O-bound programs and yet not permanently starve CPU-bound programs?
10. The traditional UNIX scheduler enforces an inverse relationship between priority numbers and priorities: the higher the number, the lower the priority. The scheduler recalculates process priorities once per second using the following function:

    Priority = (recent CPU usage / 2) + base

    where base = 60 and recent CPU usage refers to a value indicating how often a process has used the CPU since priorities were last recalculated. Assume that recent CPU usage for process P1 is 40, for process P2 is 18, and for process P3 is 10. What will be the new priorities for these three processes when priorities are recalculated? Based on this information, does the traditional UNIX scheduler raise or lower the relative priority of a CPU-bound process?
11. Of these two types of programs:
    - I/O-bound
    - CPU-bound

    which is more likely to have voluntary context switches, and which is more likely to have nonvoluntary context switches? Explain your answer.
12. One technique for implementing **lottery scheduling** works by assigning processes lottery tickets, which are used for allocating CPU time. Whenever a scheduling decision has to be made, a lottery ticket is chosen at random, and the process holding that ticket gets the CPU. The BTV operating system implements lottery scheduling by holding a lottery 50 times each second, with each lottery winner getting 20 milliseconds of CPU time (20 milliseconds × 50 = 1 second). Describe how the BTV scheduler can ensure that higher-priority threads receive more attention from the CPU than lower-priority threads.
13. Consider the exponential average formula used to predict the length of the next CPU burst. What are the implications of assigning the following values to the parameters used by the algorithm?
    α = 0 and τ0 = 100 milliseconds
    α = 0.99 and τ0 = 10 milliseconds
14. A variation of the round-robin scheduler is the **regressive round-robin** scheduler. This scheduler assigns each process a time quantum and a priority. The initial value of a time quantum is 50 milliseconds. However, every time a process has been allocated the CPU and uses its entire time quantum (does not block for I/O), 10 milliseconds is added to its time quantum, and its priority level is boosted. (The time quantum for a process can be increased to a maximum of 100 milliseconds.) When a process blocks before using its entire time quantum, its time quantum is reduced by 5 milliseconds, but its priority remains the same. What type of process (CPU-bound or I/O-bound) does the regressive round-robin scheduler favor? Explain.
15. The following processes are being scheduled using a preemptive, priority-based, round-robin scheduling algorithm.

    {: .table .table-striped}
    | Process |	Arrival | Burst Time | Priority |
    | ------- | ------- | ---------- | -------- |
    | P1      | 0       | 15         | 1        |
    | P2      | 0       | 20         | 8        |
    | P3      | 20      | 20         | 5        |
    | P4      | 25      | 20         | 5        |
    | P5      | 45      | 5          | 4        |
    | P6      | 55      | 15         | 4        |

    Each process is assigned a numerical priority, with a lower number indicating a higher relative priority. The scheduler will execute the highest priority process. For processes with the same priority, a round-robin scheduler will be used with a time quantum of 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.
    - Show the scheduling order of the processes using a Gantt chart.
    - What is the response time for each process?
    - What is the waiting time for each process?
16. Which of the following scheduling algorithms could result in starvation?
    - First-come, first-served
    - Shortest job first
    - Round robin
    - Priority
17. Consider a system running ten I/O-bound tasks and one CPU-bound task. Assume that the I/O-bound tasks issue an I/O operation once for every millisecond of CPU computing and that each I/O operation takes 10 milliseconds to complete. Also assume that the context-switching overhead is 0.1 millisecond and that all processes are long-running tasks. Describe the CPU utilization for a round-robin scheduler when:
    - The time quantum is 1 millisecond
    - The time quantum is 10 milliseconds
18. Explain the how the following scheduling algorithms discriminate either in favor of or against short processes:
    - FCFS
    - RR
    - Multilevel feedback queues
19. Assume that a multicore system has private, per-processor run queues. When a new process is created, it can be placed in either the same queue as the parent process or a separate queue.
    - What are the benefits of placing the new process in the same queue as its parent?
    - What are the benefits of placing the new process in a different queue?
20. Explain why interrupt and dispatch latency times must be bounded in a hard real-time system.

### In class
Discuss the exercises prepared at home
