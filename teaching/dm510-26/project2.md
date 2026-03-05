---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

# Project 2: Kernel Module

In this assignment your task is to create driver for the Raspberry Pi that exposes a character device `/dev/morse` to the user. When a user writes into `/dev/morse`, the message should be transmitted via Morse code
on the LED. Morse code is an old standard for transmitting text via a series of short and long signals. You can find all the necessary information on Morse encoding in the image below. 

![Morse](img/morse.png)

### Drivers in Linux

To add a new driver to Linux you do not need to recompile the kernel. You do not even need to reboot the system. A driver is typically implemented in a kernel module, which is a piece of code that can be dynamically loaded or unloaded
into the kernel. Simply put, the kernel module you need for this project implements a number of functions that will be invoked when the module is loaded, when the device is opened, when something is written into the device, etc.
To get started simply download [project2.zip](project2.zip) onto your Raspberry Pi home directory and unzip it:

```
cd ~
wget https://larsrohwedder.com/teaching/dm510-25/project2.zip
unzip project2
cd project2
```

The folder you just downloaded contains all function stubs needed for the driver, just without their implementation. Indeed, you can build and load the driver already:

```
make
sudo sh morse_load
```

You can check that `/dev/morse` is now visible. However, it does not do anything yet. Unload it again using `sudo sh morse_unload`.
To bring your driver to life, you need to first learn more about programming drivers for Linux.

Almost everything you need to know for this can be found in the [Linux Device Drivers (LDD)](https://lwn.net/Kernel/LDD3/) book.
The first chapters of the book explain in detail how a character driver `scull` is written. Unlike your driver, `scull` does not do anything useful, but you should understand its code in detail, since
it uses almost all tools that you will also need. The full code of the `scull` driver (updated for recent kernel versions) can be found [here](https://github.com/duxing2007/ldd3-examples-3.x).

### A first prototype

Before diving into advanced features, it is good to start simple. Your first goal is to allow `/dev/morse` to be opened for writing and to dump everything that is written to it into the kernel log using `printk`.
The log messages can be viewed using the `dmesg` command line program.
For this, read Chapter 3 of LDD, implement the code to register your device and a write method that simply logs messages with `printk`.
Use a major number of 255 and minor number of 0 when registering the device.

Next, transfer your code for controlling the LED from the first project to your driver. Note that you are **not** supposed to make a system call from your drive). Instead,
simply copy the relevant source code into the driver.
Using this code and the `msleep` function, you can already implement a basic Morse transmitter in the write function and test it.

### The advanced driver

Your final driver should satisfy the following requirements

- There must be an output buffer to which messages are first written instead of directly transmitting them within the write function. Asynchronously, a kernel thread (kthread) should transmit the contents of the buffer over the LED whenever the buffer is non-empty. For the API of kthreads, read [this](https://c-pointers.com/LinuxDeviceDriver/basic_ldd/chapter2_kthreads/p1_createKthread.html).
- Synchronization mechanisms should be used to prevent race conditions (see Chapter 5 of LDD).
- Blocking and non-blocking I/O must be supported (see Chapter 6 of LDD, page 147ff).
- Only one process at a time should be able to open the device for writing.
- Simple device control has to be possible via the `ioctl` system call (see Chapter 6 of LDD). Implement at least a way to set the unit duration of the Morse transmission and the size of the output buffer.

The following is not required:
- udev and devfs support.
- Poll, select and asynchronous notification support (see Chapter 6 of LDD).

### Submission

Submit via itslearning the following:
- Source code of the driver: `morse_dev.c` and other source files in case you added any
- Source code of the user program(s) that test the functionality, including writing to the device and `ioctl`.
- A video recording from your phone that shows how you write the last names of your group members into the device on your terminal. Move the camera between screen and Pi to demonstrate how the LED transmits the Morse code.
- A pdf with answers to the questionaire below and possibly appendices.

**Questionaire:**

- Did you manage to compile the driver and load it?
- Did you manage to implement a driver that prints messages to the log?
- Did you manage to implement a Morse transmittion on the LED?
- Did you manage to implement an output buffer from which a seperate thread reads and transmits the data via Morse code?
- Did you manage to implement blocking and non-blocking I/O?
- Did you manage to allow only one process to open the device at a time?
- Did you manage to implement device control via `ioctl`?

If your answer is no to some of these questions, you may include explanation on which problems you ran into.
It is intentional that there is no excessive report on the project. All design decisions that you made should be documented in the source code itself.  

**Assessment:**

The project will be graded based on the following:

- **Functionality:** Did you implement the required functionality and is the implementation correct?
- **Style:** Is the programming style appropriate and is the code well documented?
- **Tests:** Are you testing all aspects of the driver?

