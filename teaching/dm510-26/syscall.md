---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

# Adding a new system call to Linux on the Raspberry Pi

In `include/linux/syscalls.h` before the last line with `#endif` insert
```
asmlinkage long sys_hellokernel(long param);
```
Open `include/uapi/asm-generic/unistd.h` and find the line with `#define __NR_syscalls ...`.
Increase the number here by one and before it add
```
#define __NR_hellokernel 463
__SYSCALL(__NR_hellokernel, sys_hellokernel)

```
Replace here 463 by one less than what you entered as the number of system calls.

Open `kernel/sys_ni.c` and add the line
```
COND_SYSCALL(hellokernel);
```

Open `arch/arm64/tools/syscall_64.tbl`
and add the line
```
463     common  hellokernel                     sys_hellokernel
```
where you replace 463 by the number.

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
Open `arch/arm64/Makefile`. You find `obj-y := ...` with a long list of object files. Add `hellokernel.o` to it.

You can now compile the kernel with the new system call.
Compiling the kernel after these changes takes a long time, since many source files depend on the system calls that were changed. However,

To test the system call, create a user program where you include the header `arch/arm64/include/generated/uapi/asm/unistd_64.h`
and call
```
    int code = syscall(__NR_hellokernel, 42);
```
It will return `-1` on failure. Otherwise it will print a message to the kernel log that you can see using `dmesg` in the terminal.
