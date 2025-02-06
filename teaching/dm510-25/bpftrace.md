---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# BPFTrace

[bpftrace](https://github.com/bpftrace/bpftrace/) is a high-level tracing language for Linux enhanced Berkeley Packet Filter (eBPF) available in recent Linux kernels (4.x). bpftrace uses LLVM as a backend to compile scripts to BPF-bytecode and makes use of BCC for interacting with the Linux BPF system, as well as existing Linux tracing capabilities: kernel dynamic tracing (kprobes), user-level dynamic tracing (uprobes), and tracepoints.

The bpftrace language is inspired by awk and C, and predecessor tracers such as DTrace and SystemTap.

### Installation

bpftrace is available on most package repositories of Linux distributions. On Linux Mint for example it can be installed with:
{% highlight terminal %}
$ sudo apt install bpftrace
{% endhighlight %}
You can verify that it is correctly installed using the following command.
{% highlight terminal %}
$ sudo bpftrace -e 'BEGIN { printf("hello world\n"); }'
Attaching 1 probe...
hello world
^C
{% endhighlight %}

### Listing available probes

A probe is an instrumentation point for capturing event data.

The argument `-l` lists all probes that match the search term. Below we search for all system calls entry calls.

{% highlight terminal %}
bpftrace -l 'tracepoint:syscalls:sys_enter_*'
{% endhighlight %}

### Examples
The following examples can be executed with `sudo bpftrace <scriptname>`. A script is terminated by pressing control-C.

The following script counts the number of system calls per process.
**syscalls.bt**
{% highlight bpftrace %}
tracepoint:raw_syscalls:sys_enter {
	@[comm] = count(); 
}
{% endhighlight %}
The following script outputs the number of context switches every second

**switches.bt**
{% highlight bpftrace %}
tracepoint:sched:sched_switch {
	 @ = count();
} 

interval:s:1 { 
	print(@); 
	clear(@); 
}
{% endhighlight %}

Larger example demonstrating how to interact with a kernel structure. This replicates the output of `uptime` every second.
{% highlight bpftrace %}
#!/usr/bin/env bpftrace
/*
 * loads	Prints load averages.
 *		For Linux, uses bpftrace and eBPF.
 *
 * These are the same load averages printed by "uptime", but to three decimal
 * places instead of two (not that it really matters). This is really a
 * demonstration of fetching and processing a kernel structure from bpftrace.
 *
 * USAGE: loads.bt
 *
 * This is a bpftrace version of a DTraceToolkit tool.
 *
 * Copyright 2018 Netflix, Inc.
 * Licensed under the Apache License, Version 2.0 (the "License")
 *
 * 10-Sep-2018	Brendan Gregg	Created this.
 */

BEGIN
{
	printf("Reading load averages... Hit Ctrl-C to end.\n");
}

interval:s:1
{
	/*
	 * See fs/proc/loadavg.c and include/linux/sched/loadavg.h for the
	 * following calculations.
	 */
	$avenrun = kaddr("avenrun");
	$load1 = *$avenrun;
	$load5 = *($avenrun + 8);
	$load15 = *($avenrun + 16);
	time("%H:%M:%S ");
	printf("load averages: %d.%03d %d.%03d %d.%03d\n",
	    ($load1 >> 11), (($load1 & ((1 << 11) - 1)) * 1000) >> 11,
	    ($load5 >> 11), (($load5 & ((1 << 11) - 1)) * 1000) >> 11,
	    ($load15 >> 11), (($load15 & ((1 << 11) - 1)) * 1000) >> 11
	);
}
{% endhighlight %}
