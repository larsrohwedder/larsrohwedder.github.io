---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 2

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 3
1. Using the program shown below, explain what the output will be at `LINE A`.
    ```
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int value = 5;
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        /* child process */
        value += 15;
        return 0;
    }
    else if (pid > 0) {
        /* parent process */
        wait(NULL);
        printf("PARENT: value = %d",value); /* LINE A */
        return 0;
    }
}

    ```
2. Including the initial parent process, how many processes are created by the program shown below?
    ```
#include <stdio.h>
#include <unistd.h>
int main()
{
    /* fork a child process */
    fork();
    /* fork another child process */
    fork();
    /* and fork another */
    fork();
    return 0;
}
    ```
3. Using the program below, identify the values of pid at lines `A` , `B` , `C` , and `D`. (Assume that the actual pids of the parent and child are `2600` and `2603`, respectively.)
    ```
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid, pid1;
    /* fork a child process */
    pid = fork();
    if (pid < 0) {
        /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) {
        /* child process */
        pid1 = getpid();
        printf("child: pid = %d\n",pid);   /* A */
        printf("child: pid1 = %d\n",pid1); /* B */
    }
    else {
        /* parent process */
        pid1 = getpid();
        printf("parent: pid = %d\n",pid);   /* C */
        printf("parent: pid1 = %d\n",pid1); /* D */
        wait(NULL);
    }
    return 0;
}
    ```
4. Using the program shown below, explain what the output will be at lines `X` and `Y`.
    ```
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#define SIZE 5
int nums[SIZE] = {0,1,2,3,4};
int main()
{
    int i;
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        for (i = 0; i < SIZE; i++) {
            nums[i] *= -i;
            printf("CHILD: %d \n",nums[i]); /* LINE X */
        }
    }
    else if (pid > 0) {
        wait(NULL);
        for (i = 0; i < SIZE; i++)
            printf("PARENT: %d \n",nums[i]); /* LINE Y */
    }
    return 0;
}

    ```
4. Some computer systems provide multiple register sets. Describe what happens when a context switch occurs if the new context is already loaded into one of the register sets. What happens if the new context is in memory rather than in a register set and all the register sets are in use?
5. When a process creates a new process using the fork() operation, which of the following states is shared between the parent process and the child process?
    * Stack
    * Heap
    * Shared memory segments
6. Describe the actions taken by a kernel to context-switch between processes.
7. Give an example of a situation in which ordinary pipes are more suitable than named pipes and an example of a situation in which named pipes are more suitable than ordinary pipes.

### Related to Chapter 4
1. Provide three examples in which multithreading provides better performance than a single-threaded solution.
2. Using Amdahl’s Law, calculate the speedup gain of an application that has a 60 percent parallel component for
    * two processing cores
    * four processing cores
3. Using Amdahl’s Law, calculate the speedup gain for the following applications:
    * 40 percent parallel with (a) eight processing cores and (b) sixteen processing cores
    * 67 percent parallel with (a) two processing cores and (b) four processing cores
    * 90 percent parallel with (a) four processing cores and (b) eight processing cores
3. Consider a web server that for each incoming request creates a new thread to service that request (see also Section 4.1). Does this process exhibit task or data parallelism?
4. Determine if the following problems exhibit task or data parallelism:
    * Using a separate thread to generate a thumbnail for each photo in a collection
    * Transposing a matrix in parallel
    * A networked application where one thread reads from the network
4. What are two differences between user-level threads and kernel-level threads? Under what circumstances is one type better than the other?
5. Describe the actions taken by a kernel to context-switch between kernellevel threads.
6. What resources are used when a thread is created? How do they differ from those used when a process is created?
7. Assume that an operating system maps user-level threads to the kernel using the many-to-many model and that the mapping is done through LWPs. Furthermore, the system allows developers to create real-time threads for use in real-time systems. Is it necessary to bind a real-time thread to an LWP? Explain.
8. Under what circumstances does a multithreaded solution using multiple kernel threads provide better performance than a single-threaded solution on a single-processor system?
9. Which of the following components of process state are shared across threads in a multithreaded process?
    * Register values
    * Heap memory
    * Global variables
    * Stack memory
10. Consider the following code segment.
    * How many unique processes are created?
    * How many unique threads are created?
    ```
pid_t pid;
pid = fork();
if (pid == 0) { /* child process */
    fork();
    thread create( . . .);
}
fork();
    ```
11. The following program uses the Pthreads API. What would be the output from the program at `LINE C` and `LINE P`?
    ```
#include <pthread.h>
#include <stdio.h>
int value = 0;
void *runner(void *param); /* the thread */
int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;

    pid = fork();

    if (pid == 0) { /* child process */
        pthread_attr_init(&attr);
        pthread_create(&tid,&attr,runner,NULL);
        pthread_join(tid,NULL);
        printf("CHILD: value = %d \n",value); /* LINE C */
    } else if (pid > 0) { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d \n",value); /* LINE P */
    }
}

void *runner(void *param) {
    value = 5;
    pthread_exit(0);
}
    ```
12. Consider a multicore system and a multithreaded program written using the many-to-many threading model. Let the number of user-level threads in the program be greater than the number of processing cores in the system. Discuss the performance implications of the following scenarios.
    * The number of kernel threads allocated to the program is less than the number of processing cores.
    * The number of kernel threads allocated to the program is equal to the number of processing cores.
    * The number of kernel threads allocated to the program is greater than the number of processing cores but less than the number of user-level threads.

### C Programming
1. Analyze the following C program(s), and discuss the code given below wrt. correctness, readability and efficiency of the code. Is the first version more efficient than the naïve recursive approach (2nd version) to compute the power of a number?
    ** Version 1 **
    ```
#include <stdio.h>
#include <inttypes.h>
float power(float x, uint32_t exp);

float power(float x, uint32_t exp)
{
  float result;
  /* base case */
  if (exp == 0)
    return 1.0;

  result = power(x, exp >> 1);
  result = result * result;

  if (exp & 1)
    result = result * x;
  return result;
}

int main(int argc, char **argv)
{
  float p;
  p = power(10.0, 5);
  printf("p = %f\n", p);
  return 0;
}
    ```
    ** Version 2 **
    ```
#include <stdio.h>
#include <inttypes.h>


float power(float x, uint32_t exp)
{
  /* base case */
  if (exp == 0) {
    return 1.0;
  }
  /* recursive case */
  return x*power(x, exp - 1);
}

int main(int argc, char **argv)
{
  float p;
  p = power(10.0, 5);
  printf("p = %f\n", p);
  return 0;
}
    ```
### In class
Discuss the exercises prepared at home
