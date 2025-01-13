---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---


# Adding a System Call
This document describes how to add a system call to User-mode Linux to the linux-6.6.9 kernel. Make sure you have a running UML kernel (see separate [instruction](uml)). Understanding this will be a prerequisite to solve the first mandatory assignment.

### Define the entry point
The first thing you need to do is modify the file `unistd_64.h` in the directory `arch/x86/include/generated/uapi/asm/unistd_64.h`. In this file, you need to add a line providing an id for your system call. Locate the bunch of lines of the form `#define NR_somename` (in this example `NR_hellokernel`), and add a new entry for your system call by adding/chaning the following (don’t forget to increase the value for `__NR_syscalls` from `454` to `455`)

{% highlight C %}
#define __NR_fchmodat2 452
#define __NR_map_shadow_stack 453
#define __NR_hellokernel 454

#ifdef __KERNEL__
#define __NR_syscalls 455
#endif
{% endhighlight %}

Next, you must add and entry refering to your call in the system calls table. To do this, modify `syscall_64.tbl` file in `./arch/x86/entry/syscalls/` and add the following (last) line:

{% highlight C %}
452     common  fchmodat2               sys_fchmodat2
453     64      map_shadow_stack        sys_map_shadow_stack
454     common  hellokernel             sys_hellokernel
{% endhighlight %}
Next we will implement a system call.

### Implementation code
First of all, create a header file `hellokernel.h` for your system call and place it in `arch/um/include/asm` as shown here:

**hellokernel.h**
{% highlight C %}
#ifndef __UML_HELLOKERNEL_H__
#define __UML_HELLOKERNEL_H__

extern int sys_hellokernel( int );

#endif
{% endhighlight %}

Then, write out the implementation `hellokernel.c` of your system call in `arch/um/kernel/` as shown here. (Note the use of the asmlinkage modifier. This macro tells the compiler to pass all function arguments on the stack.):

**hellokernel.c**
{% highlight C %}
#include "linux/kernel.h"
#include "linux/unistd.h"

asmlinkage
int sys_hellokernel( int flag ) {
    printk("Your kernel greets you %d times! \n", flag);
return 0;
}
{% endhighlight %}

Finally, modify the respective Makefile in `arch/um/kernel` and add `somename.o` (in this example: `hellokernel.o`) to the list of build targets.

{% highlight C %}
extra-y := vmlinux.lds

obj-y = config.o exec.o exitcode.o irq.o ksyms.o mem.o \
        physmem.o process.o ptrace.o reboot.o sigio.o \
        signal.o sysrq.o time.o tlb.o trap.o \
        um_arch.o umid.o maccess.o kmsg_dump.o capflags.o hellokernel.o skas/
obj-y += load_file.o
{% endhighlight %}

Now you have to recompile the kernel. Change to the kernel source root directory and recompile :

{% highlight C %}
cd ~/dm510/linux-6.6.9
make ARCH=um linux
{% endhighlight %}

The next step is to use the new system call from a user-space application.

### Creating a stub for your system call
You call the new functions as identified by their index through the `syscall` function. With the `syscall` function, you can call, what a surprise, a system call. For example, the short application shown below calls your `sys_hellokernel` using the index of the system call and 42 as argument. The program can be compiled with the command `gcc -o testsystemcall testsystemcall.c`.

**testsystemcall.c**
{% highlight C %}
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "arch/x86/include/generated/uapi/asm/unistd_64.h"

int main(int argc, char ** argv) {
    printf("Calling ... \n");
    syscall(__NR_hellokernel,42);
}
{% endhighlight %}

Run user mode linux
{% highlight terminal %}
./linux
{% endhighlight %}

Login, and mount your home directory, and change to the directory where your newly compiled program is stored:
{% highlight terminal %}
mount none /mnt/tmp -t hostfs -o /home/your_imada_login/dm510
cd /mnt/tmp/linux-6.6.9
{% endhighlight %}

Execute the program. The result should be similar to the following:
{% highlight terminal %}
root@dm510host:/mnt/tmp/linux-6.6.9# ./testsystemcall
Calling ...
Your kernel greets you 42 times!
{% endhighlight %}

If you have more terminals, the message could show up in another terminal. You can also see the statement from the kernel using `dmesg`.

### Further (partially very old) information
- Adding a System Call to UML [link](https://user-mode-linux.sourceforge.net/old/lksct/index.html) (partially outdated).
- Linux System Call Howto [link](https://tldp.org/HOWTO/html_single/Implement-Sys-Call-Linux-2.6-i386/). Note: this is for adding a system call to Linux in general, i.e., slightly different than what you have to do in UML.
- How System Calls Are Implemented on i386 Architecture: [link](https://mirrors.sunsite.dk/ldp/LDP/lki/lki-2.html#ss2.11).

