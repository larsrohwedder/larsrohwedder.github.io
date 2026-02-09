---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

### Course Textbook

Abraham Silberschatz, Peter Baer Galvin, Greg Gagne: [Operating System Concepts 10th edition](https://codex.cs.yale.edu/avi/os-book/OS10/index.html), Wiley, 2018.

Note, that there is an International and a US version of the book. It is not important if you use the US or the international version.

### Course-Specific Instructions

- [Getting started with Raspberry Pi](pi)

### Command-line tools, programs, and examples used in course
Below is a (growing) overview of Linux tools (mostly command-line) used throughout the lectures.

Communication
- `command1 | command2` (pipe) redirects output of command1 into input of command2
- `echo <out>` outputs `<out>`

File system browsing and manipulation.
The command line has a working directory in which you currently are.
- `pwd` outputs the working directory 
- `ls` outputs all files in the working directory (or another directory using `ls <dir>`)
- `cd <dir>` changes the working directory
- `mv <file> <directory/filename>` moves file `<file>` to different directory or renames to different name
- `rm <file>` removes `<file>`

File I/O
- `cat <file>` outputs content of file
- `command > file` redirects the output of command into the file `file` (overwriting). For example `echo content > file` writes `content` into file `file`
- `command >> file` redirects the output of command into the file `file` (appending) 

Searching
- `grep <pattern>` searches input for pattern and outputs only lines containing the pattern. Example usage: `cat <file> | grep <pattern>` (searches for `<pattern>` in `<file>`; `ls | grep <filename>` (searches for `<filename>` in working directory)

Text editors
- `nano <file>` is a simple command line text editor
- `vi <file>` is a more advanced command line text editor

### Exams

TBA
