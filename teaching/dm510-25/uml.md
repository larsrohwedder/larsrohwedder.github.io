---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# User Mode Linux
In the following we describe how to install and use User-mode Linux (UML) for DM510 at IMADA based on the Linux kernel 6.6.9, released on Jan 1, 2024.

Everything was tested on the virtual IMADA Computer Lab machines that run Ubuntu 20.04 LTS.

**The version of the IMADA lab (as of January 13th. 2025)**
{% highlight terminal %}
No LSB modules are available.
Distributor ID:	Ubuntu
Description:	Ubuntu 20.04.6 LTS
Release:	20.04
Codename:	focal
{% endhighlight %}

You can login to the Computer Lab machines via the ssh command, see here how to access the Computer Lab machines, please choose randomly one of the four machines (the only directory shared among the machines is the directory /shared/ (which is slower). Note, that your home directory is not shared among the four different machines. You are of course welcome to use any other solution (e.g., running UML on your own Linux system, running it in a virtual environment like VirtualBox or vmware, using SDU’s ucloud, etc) but we might, in that case, just not be able to help you if you run into technical issues. There are instructions for installing a Virtual Machine in VirtualBox that can be used for the assignment.

### How to install User-mode Linux at IMADA
Login at any IMADA machine and write
{% highlight terminal %}
mkdir dm510
cd dm510
{% endhighlight %}

Next, get the source code for the Linux kernel 6.6.9 and unpack it (specifically the tar command will take a while!)
{% highlight terminal %}
wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.6.9.tar.xz
unxz linux-6.6.9.tar.xz
tar -xvf linux-6.6.9.tar
rm linux-6.6.9.tar
{% endhighlight %}

Enter the directory containing the kernel source files:
{% highlight terminal %}
cd linux-6.6.9
{% endhighlight %}

To make this a working copy of UML you also need a root filesystem, that you can copy to your directory. The filesystem is based on a Fedora 21. Note, that the root filesystem has a size of approx. 200MB, and that the uncompressed compiled kernel uses approx. 2.1GB.
{% highlight terminal %}
wget https://fs.devloop.org.uk/filesystems/Fedora21/Fedora21-AMD64-root_fs.bz2
bzip2 -d Fedora21-AMD64-root_fs.bz2
mv Fedora21-AMD64-root_fs root_fs
{% endhighlight %}

You are now ready to start compiling the kernel and using UML.

### How to compile User-mode Linux
We need a configuration file for compiling the linux kernel. Create it with
{% highlight terminal %}
make defconfig ARCH=um
{% endhighlight %}

Now we’re ready to compile the kernel. Do it with

{% highlight terminal %}
make ARCH=um linux
{% endhighlight %}

and have a cup of coffee or tea, because this will take a while. When the compilation is finished, you will find a file called linux in your directory. Everything is set to start UML.

### How to run User-mode Linux
User mode linux is started with
{% highlight terminal %}
./linux
{% endhighlight %}

Note that the boot process ends with messages similar to
{% highlight terminal %}
Virtual console 1 assigned device '/dev/pts/2'
Virtual console 2 assigned device '/dev/pts/3'
{% endhighlight %}

This allows you to get additional interactive shells using the command
{% highlight terminal %}
screen /dev/pts/2
{% endhighlight %}
(see FAQ below).

When running UML, you can login using the user name root with no password. If you want to access data from your home directory inside UML, you have to mount the corresponding directory. This is done with
{% highlight terminal %}
mkdir /mnt/tmp
mount none /mnt/tmp -t hostfs -o /home/your_imada_login/dm510
{% endhighlight %}

Of course your_imada_login has to be replaced by your IMADA login. The corresponding directory will be mounted as a subdirectory of /mnt/tmp inside UML. To stop the UML system you can run the command halt.

### UML Frequently asked questions (FAQ)
- My kernel panics, if I start User Mode Linux. What is the reason?
> There can be many reasons for that. But if you stopped UML by just closing the window where UML was running in, there will be still two processes named linux left, and UML will start with a kernel panic next time. You have to kill these processes, for example with killall -9 linux. After that, UML should start again. It is a good idea to stop UML always with the command halt.`
- Where can I get more information on UML?
> The (rather outdated) User-mode Linux Kernel Home Page can be found here.
- How do I get another window for login to this UML?
> UML supports two extra virtual consoles that you can login (in addition to the main console). The system informs you when booted (Virtual console 2 assigned device `/dev/pts/2`). You can see this information as well can be found using `dmesg`
```
# dmesg
[    0.000000] Linux version 6.6.9 (jamik@imada0.c.sdu.dk) (gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0, GNU ld (GNU Binutils for Ubuntu) 2.34) #2 Sat Jan 13 17:24:09 CET 2024
...
[    8.180000] Virtual console 2 assigned device '/dev/pts/2'
[    8.190000] Virtual console 1 assigned device '/dev/pts/3'
```
You can then use screen `/dev/pts/2` in a new ssh session or alternatively (if using `-X` with ssh) `xterm -e screen /dev/pts/2`
- My linux kernel does not start anymore! Help!
> In case you messed up the attached file system, this might just happen. It is always good to have a copy of that, i.e., the file root_fs. Furthermore, sometimes it helps to kill all hanging kernels with `killall -9 linux` and/or to remove the directory where UML stores temporary data with `rm -Rf ~/.uml/`. Very often it also a memory issue, and your virtual linux does not have enough main memory. You can for example assign 128M main memory to your virtual system by starting the kernel with `./linux mem=128M`.



