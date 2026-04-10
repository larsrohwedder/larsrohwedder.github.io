---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Project 3: File System

## Introduction

The goal for this assignment is to design and implement a completely new file system PiFS.
This file system will live in a new partition that you create on the Raspberry Pi's SD card.
To implement the file system, we will use FUSE, a tool that allows us to run file system code as a regular program (in userspace). When a FUSE program is run, it creates a file system at a mount point provided by the user, and then makes its virtual file system appear within that mount point. All operations performed within the subdirectories and files within that mount point are passed, by the kernel, onto the FUSE program to handle.

### Creating a partition for your file system

The program `parted` allows you to modify partitions of storage devices in linux. Start it from the command line
on the Raspberry Pi using:

```
sudo parted
```

To see information about the current partitions, within parted type:

```
print
```

If you configured the SD card with the Raspberry Pi Imager, you should see two partitions, one in with a fat32 file system, which contains your boot partition, and one with a ext4 file system, which contains your root filesystem.
You can see the start and end positions of each partition and you will see that
the first roughly 8 MB of the SD card are unused.
Create a new partition in the free space by typing the following in parted:

```
mkpart primary 1MB 5MB
```

This will create a new raw partition (no file system) of 4MB size.
Exit parted by typing

```
quit
```

The new partition should appear in your devices. To verify, run:

```
ls /dev | grep mmcblk0
```

You should see `mmcblk0` (the SD card) and `...p1`, `...p2`, `...p3` for the three partitions.
Reading and writing to your new partition requires superuser priviledges. For simplicity, we will allow everyone
to read and write to it:

```
sudo chmod a+rw /dev/mmcblk0p3
```

### FUSE
FUSE (Filesystem in USErspace) is an easy way to create a file system running in userspace for Linux. It is a software interface for Unix and Unix-like computer operating systems that lets non-privileged users create their own file systems without editing kernel code.

There are many difficulties in writing a file system, two of the biggest are:

1. A large, complex API
2. File system lives in kernel space (hard to debug, easy to crash the machine)

FUSE fixes #1 by providing a simpler, more uniform API. For example, in FUSE all operations take a full, absolute path (a path is absolute if it starts with "/"). There is no notion of relative paths. FUSE fixes #2 by running your file system code in user space rather than in kernel space. The architecture of FUSE is found in the figure below.

![FUSE](Fuse.png)

- A program, such as ls or mkdir makes a system call to a file system routine. For example, open("/test/fuse/file1.txt"). This call is handled by the kernel.
- If this file is in a FUSE volume, the kernel passes it on to the FUSE kernel module, which then passes it on to the implementation of that file system (this is the portion you are to implement in this project).
- The implementation of open then refers to the actual data structures that represent the file system and returns a file handle. It is open's job to take a concrete view of data (bits stored on a hard drive) and present an abstract view (a hierarchically organized file system).
- The kernel returns the result of the open function to the program that originally made the call.

### FUSE API

{% include table.html content="
|        |   File                |   Directory  |
| ------ | --------------------- | ------------ |
| create | mknod                 | mkdir        |
| remove | unlink                | rmdir        |
| read   | read                  | readdir      |
| write  | write                 |              |
| misc   | open, close, truncate |              |
" %}

Also, there is a `getattr` function, which applies to both files and directories. `getattr` returns various statistics, such as file size, or the number of files in a directory. This is heavily used, and should be one of the first things to implement.

You can find more information about the data structures of FUSE in the file **/usr/include/fuse/fuse_common.h** and the interface of the functions in **/usr/include/fuse/fuse.h**. The latest version of fuse.h have some usefull documentation as well: [fuse.h](https://github.com/libfuse/libfuse/blob/master/include/fuse.h). But keep in mind it may be a newer version than in your packet repository.

### Taking FUSE for a test run

FUSE is already installed in the Raspberry Pi, but to build a project with it, you need to install the headers by running:

```
sudo apt install libfuse-dev
```

Create a new folder for your project:

```
mkdir ~/project3
cd ~/project3
```

Now download the following files:

```
wget https://larsrohwedder.com/teaching/dm510-25/FUSE/pifs.c
wget https://larsrohwedder.com/teaching/dm510-25/FUSE/Makefile
```

Create the executable pifs by running `make`. The following sample session shows how this very simple sample file system is mounted (via the program pifs) and unmounted (via the command fusermount -u).

```
mkdir mountpoint
chmod 755 mountpoint
./dm510fs mountpoint
cd mountpoint
ls
cd ..
fusermount -u mountpoint
```

You should use the sample file system as a base for your implementation of your filesystem.

If you see the code of `pifs.c` you see several printf statements, that in the previous session was not shown in the terminal session (and not found in any of the logs under `/var/log/`). To see these, use the `-f` flag (i.e. `./pifs -f mountpoint`), which keeps FUSE in the foreground. You then need another terminal to interact with your filesystem.

## The Task and Requirements

The filesystem you will implement is simplified and makes many shortcuts, compared to a real usable filesystem.
In the description below, a lot of details are left out. You have to decide for yourself what is appropriate and what to do, and document the choices in the comments of your source code.

To get started quickly, it is recommended to first allocate a section of memory with `malloc` and store the filesystem in there. You will later adapt your code to keep the filesystem in the SD card partition.

### The inode

The first thing you should do is to consider what your inode should contain.

You are allowed to restrict the length of the filesystem path and the name of the file, and can keep this in an array of a fixed length. The same goes for the data of the files, where you can restrict the max length of a file to what can be in a fixed length array in the inode.

With these limitations, your inode can have a fixed size, which makes it easy to use a `struct` for it. You can consider your filesystem as an array of inodes, with both data and metadata of the directories and files.

### Requirements for Functionality

Your file system should implement the following parts of a file system using appropriate APIs from FUSE.

- **Directories:** List, create, and delete files. Create and delete directories. You can omit rename and link. You are as mentioned above allowed to restrict the length of filenames.
- **Files:** Open, close. Sequential read/write of streams of bytes.
- **Inodes:** Size, access and modification time stamps. You can omit owner, permissions, reference count, etc.
- **Persistence:** Once the filesystem is mounted, you should restore a previous version (if one exists), and unmounting should save to disk.

Remember to document your choices using comments in the source code.

### Persistance

The actual file system should be on the new partition on your SD card, not just in main memory. 
It is ok if you read the data from the partition into memory when the filesystem is mounted, and write it back when unmounted. Reading and writing to the partition works in the same way as reading and writing to files.
For this, open `/dev/mmcblk0p3`.
You could also map the data on `/dev/mmcblk0p3` to your address space with `mmap` and directly work on it, but this is not a requirement.

## Common problems
There are several common problems that plague programmers new to FUSE. This is a partial list:

- **Error: Transport endpoint not connected**: You need to do the fusermount even if your program crashes or you abort it. Otherwise you’ll get a confusing "Transport endpoint not connected" message the next time you try to mount the test system.
- **Multithreading**: By default, Fuse is multithreaded. That’s handy for production filesystems, because it lets client (or file access) A proceed even if client B is hung up. But multithreading introduces the possibility of race conditions, and makes debugging harder. You can run FUSE with the -s switch to avoid this problem.
- **getattr**: Fuse calls getattr like crazy. Implement it first, or nothing will work.
- **Truncate**: Unless you’re writing a read-only filesystem, you need to implement the truncate system call to make writes work correctly.
- **Working directory**: When it starts, Fuse changes its working directory to "/". That will probably break any code that uses relative pathnames. To make matters worse, the `chdir` is suppressed when you run with the `-f` switch, so your code might appear to work fine under the debugger. To avoid the problem, either (a) use absolute pathnames, or (b) record your current working directory by calling `get_current_dir_name` before you invoke `fuse_main`, and then convert relative pathnames into corresponding absolute ones. Obviously, (b) is the preferred approach.
- **Printf**: Your printf/fprintf debugging code will only work if you run with the `-f` switch. Otherwise, Fuse disconnects stdout and stderr.
- **Unimplemented functions**: It is very tempting to just leave functions undefined if your filesystem doesn’t need them, or if you just haven’t gotten around to writing them yet. Don’t. If a function isn’t listed in your fuse_operations struct, Fuse will silently generate a failure when it is called, and you’ll never find out that you need to write it. Instead, write every unimplemented function as a stub that prints a message to stderr and returns an error code. When you see the message, you’ll know what extra functions you need to write.
