---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

{% assign open="{%" %}
{% assign close="%}" %}
{% assign swap1="
{{ open }} highlight C {{ close }}
static inline void swap(int *m, int *n)
{
  int temp = *m;
  *m = *n;
  *n = temp;
}

int main(int argc, char **argv)
{
  int x,y;

  x=42;
  y=100;

  swap(&x, &y);
}
{{ open }} endhighlight {{ close }}
" | markdownify %}

# Exercise Sheet for Tutorial 1

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 1
1. Name three central purposes of an operating system.
2. What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?
3. Consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answers.
4. How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security)?
5. Which of the following instructions should be privileged?
    - Set value of timer.
    - Read the clock.
    - Clear memory.
    - Issue a trap instruction.
    - Turn off interrupts.
    - Modify entries in device-status table.
    - Switch from user to kernel mode.
    - Access I/O device.
6. Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?
7. Give two reasons why caches are useful. What problems do they solve? What problems do they cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device?
8. How do clustered systems differ from multiprocessor systems? What is required for two machines belonging to a cluster to cooperate to provide a highly available service?
9. **(important)** What is the purpose of interrupts? How does an interrupt differ from a trap? Can traps be generated intentionally by a user program? If so, for what purpose?
10. Direct memory access is used for high-speed I/O devices in order to avoid increasing the CPU’s execution load.
    - How does the CPU interface with the device to coordinate the transfer?
    - How does the CPU know when the memory operations are complete?
    - The CPU is allowed to execute other programs while the DMA controller is transferring data. Does this process interfere with the execution of the user programs? If so, describe what forms of interference are caused.
11. **(important)** Rank the following storage systems from slowest to fastest:
    - Hard-disk drives
    - Registers
    - Optical disk
    - Main memory
    - Nonvolatile memory
    - Magnetic tapes
    - Cache
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
    - `int *x;`
25. Which of the following gives the memory address of integer variable `a`?
    - `*a;`
    - `a;`
    - `&a;`
    - `address(a);`
26. Which of the following gives the memory address of a variable pointed to by pointer `a`?
    - `a;`
    - `*a;`
    - `&a;`
    - `address(a);`
27. Which of the following gives the value stored at the address pointed to by pointer `a`?
    - `a;`
    - `val(a);`
    - `*a;`
    - `&a;`
28. Which of the following is the proper keyword or function to allocate memory in C?
    - `new`
    - `malloc`
    - `create`
    - `value`
29. Which of the following is the proper keyword or function to deallocate memory?
    - `free`
    - `delete`
    - `clear`
    - `remove`
30. Repeat the discussion of the four following examples to swap the content of two variables. Which of the examples are correct, which are wrong?
    - version 1
        {{ swap1 }}
    - version 2
        {{ swap1 }}
    - version 2
        {% highlight C %}
        #include <stdlib.h>

        static inline void swap(int *m, int *n)
        {
          int temp = *m;
          *m = *n;
          *n = temp;
        }

        int main(int argc, char **argv)
        {
          int * x;
          int * y;

          x = calloc(1,sizeof(int));
          y = calloc(1,sizeof(int));

          *x = 42;
          *y = 100;

          swap(x, y);
        }
        {% endhighlight %}
    - version 3
        ```
        #include <stdlib.h>

        static inline void swap(int *m, int *n)
        {
          int * temp = m;
          m = n;
          n = temp;
        }

        int main(int argc, char **argv)
        {
          int * x;
          int * y;

          x = calloc(1,sizeof(int));
          y = calloc(1,sizeof(int));

          *x = 42;
          *y = 100;

          swap(x, y);
        }
        ```
    - version 4
        ```
        #include <stdlib.h>

        static inline void swap(int **m, int **n)
        {
          int * temp = *m;
          *m = *n;
          *n = temp;
        }

        int main(int argc, char **argv)
        {
          int * x;
          int * y;

          x = calloc(1,sizeof(int));
          y = calloc(1,sizeof(int));

          *x = 42;
          *y = 100;

          swap(&x, &y);
        }
        ```
31. Analyze the following C source code. Discuss what it does (this prepares you for the 1st programming projecct).

**dm510_msgbox.c**
{% highlight C %}
#include "dm510_msgbox.h"
#include <stdlib.h>
#include <string.h>

typedef struct _msg_t msg_t;

struct _msg_t{
  msg_t* previous;
  int length;
  char* message;
};

static msg_t *bottom = NULL;
static msg_t *top = NULL;

int dm510_msgbox_put( char *buffer, int length ) {
  msg_t* msg = malloc(sizeof(msg_t));
  msg->previous = NULL;
  msg->length = length;
  msg->message = malloc(length);
  memcpy(msg->message, buffer, length);

  if (bottom == NULL) {
    bottom = msg;
    top = msg;
  } else {
    /* not empty stack */
    msg->previous = top;
    top = msg;
  }
  return 0;
}

int dm510_msgbox_get( char* buffer, int length ) {
  if (top != NULL) {
    msg_t* msg = top;
    int mlength = msg->length;
    top = msg->previous;

    /* copy message */
    memcpy(buffer, msg->message, mlength);

    /* free memory */
    free(msg->message);
    free(msg);

    return mlength;
  }
  return -1;
}

int main(int argc, char** argv) {
  char *in = "This is a stupid message.";
  char msg[50];
  int msglen;

  /* Send a message containing 'in' */
  dm510_msgbox_put(in, strlen(in)+1);

  /* Read a message */
  msglen = dm510_msgbox_get(msg, 50);

  return 0;
}
{% endhighlight %}

32. The following is the code to allocate memory for a 2-dimensional array of fixed size 8×8.

{% highlight C %}
#include <stdio.h>
int main() {
  int x;
  int y;
  int array[8][8];
  for ( x = 0; x < 8; x++ ) {
    for ( y = 0; y < 8; y++ ) {
      array[x][y] = x * y;
    }
  }
}
{% endhighlight %}

    - Where in the memory is the matrix stored?
    - Provide the code for a variant of the code that allocated the memory dynamically.
    - Where is your dynamically allocated memory stored?

33. What is the output of the following C program?

{% highlight C %}
#include <stdio.h>

int main(int argc, char** argv)
{
  stupid();
  stupid();
  return 0;
}

int stupid()
{
  static int i=17;
  printf("i is %d\n", i);
  i++;
}
{% endhighlight %}

35. Discuss the following C program, and put it in relation to the function declaration as found by the man page of the library function for sorting an array: `void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));`

{% highlight C %}
#include <stdio.h>
#include <stdlib.h>

static int comp(const void * x, const void * y)
{
  int a = (int)(*(int*)x);
  int b = (int)(*(int*)y);

  if (a==b)
    return 0;
  else
    if (a < b)
        return -1;
    else
        return 1;
}

int main(int argc, char* argv[])
{
   int numbers[10]={1892,45,200,-98,4087,5,-12345,1087,88,-100000};
   int i;

  /* Sort the array */
  qsort(numbers,10,sizeof(int),comp) ;
  for (i=0;i<9;i++)
    printf("Number = %d\n",numbers[ i ]) ;
  return 0;
}
{% endhighlight %}

36. Discuss the result of the following C program. If possible, try it on different machines. In order to understand the results, find out what a sequence point is.

{% highlight C %}
#include <stdio.h>

#define SQR(a)((a)*(a))
#define CUB(a)((a)*(a)*(a))


inline static int cub(int x) { return x*x*x; }

int main()
{
    int x;

    x=3;
    printf("square? :%d\n",SQR(x));
    printf("x:       %d\n",x);

    x=3;
    printf("square? :%d\n",SQR(++x));
    printf("x:       %d\n",x);

    x=3;
    printf("cub?    :%d\n",CUB(x++));
    printf("x:       %d\n",x);

    x=3;
    printf("cub?    :%d\n",CUB(++x));
    printf("x:       %d\n",x);

    x=3;
    printf("cub?    :%d\n",cub(++x));
    printf("x:       %d\n",x);

    return 0;
}
{% endhighlight %}

36. Follow the C-tutorial for FILE I/O on [cprogramming](https://www.cprogramming.com/tutorial/cfileio.html) and answer the quiz questions.

### In class
Discuss the exercises prepared at home, form teams (2 students) for programming projects.

