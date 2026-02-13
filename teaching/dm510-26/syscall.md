---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

# Adding a new system call to Linux on the Raspberry Pi
The following instructions explain how to add a simple system call that prints a message into the kernel log. This assumes that you understand how to compile the Linux kernel, see [instructions](kernel). 
All of the following file locations are relative to the directory where your Linux source files are: `~/linux` if you followed the previous instructions.

In `include/linux/syscalls.h` before the last line with `#endif` insert the function definition, we will use:
```
asmlinkage long sys_hellokernel(long param);
```
Open `include/uapi/asm-generic/unistd.h` and find the line with `#define __NR_syscalls ...`.
The number here is the total number of system calls. Increase it by one.
Each system call is identified by a number and by increasing the total number of system calls you freed up one number.
Before the previous line add the following:
```
#define __NR_hellokernel 463
__SYSCALL(__NR_hellokernel, sys_hellokernel)

```
Possibly replace 463 by the number of the new system call (one less than what you entered as the number of system calls).

Open `kernel/sys_ni.c` and add the line
```
COND_SYSCALL(hellokernel);
```

Open `arch/arm64/tools/syscall_64.tbl`
and add the line
```
463     common  hellokernel                     sys_hellokernel
```
where you possibly replace 463 by the number of the system call.

To `arch/arm64/kernel/` add a file `hellokernel.c` with the content
```
#include "linux/kernel.h"
#include "linux/syscalls.h"

SYSCALL_DEFINE1(hellokernel, long, param) 
{
        printk(KERN_EMERG "Your kernel says hello %d times!", (int)param);
        return 0;
}
```
This is the actual implementation of your system call that will be called when it is invoked. The number in `SYSCALL_DEFINE1` stands for the number of parameters and can be changed.
Open `arch/arm64/Makefile`. You find `obj-y := ...` with a long list of object files. Add `hellokernel.o` to it.

You can now compile the kernel with the new system call.
Compiling the kernel after these changes takes a long time, since many source files depend on the system calls that were changed.
When later changing only the source file (`hellokernel.c`) it will not take a lot of time to rebuild the kernel. This means, it may be best to add all system calls
that you intend to use first and leave incomplete function stubs, which you then fill one after the other.

### Testing the system call

Create a user program where you include the header `arch/arm64/include/generated/uapi/asm/unistd_64.h`.
Call
```
    int code = syscall(__NR_hellokernel, 42);
```
It will return `-1` on failure. Otherwise it will print a message to the kernel log that you can see using `dmesg` in the terminal.
