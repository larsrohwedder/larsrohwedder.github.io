---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

# Building a custom Linux kernel and setting it up on the Pi

Please follow first the [instructions](pi) on how to set up the Raspberry Pi and establish an SSH connection. Make sure that the Pi has connection to the internet.
In the following we will download the source code of the Linux kernel, compile it *on the Pi itself* and update the kernel with the newly compiled one.

First change to home directory of the Pi and download the source code of the Raspberry Pi branch of the Linux kernel.
This download may take a while.

```
cd ~
git clone --depth=1 https://github.com/raspberrypi/linux
```

Using the package manager, we install developer tools required to build the kernel.
```
sudo apt install bc bison flex libssl-dev make
```
Press `Y` when asked to confirm.

We use the default configuration for the kernel. This is assuming you are still in the directory with the source code. Otherwise change into it using `cd ~/linux`.
```
KERNEL=kernel8
make bcm2711_defconfig
```
Open the file `.config` for example using `nano .config`. Find the line `CONFIG_LOCALVERSION="-v8"`. For each team member add to it `-XYZ` where `XYZ` are the first three letters of your last name. For example, if your team members are Rohwedder and Larsen, change the line to:
```
CONFIG_LOCALVERSION="-v8-ROH-LAR"
```
**Important:** Replace `ROH-LAR` with the correct letters in the line above.

### Building the kernel

Please read this section completely before proceeding. Building Linux will take several hours, so you may need to make some careful preparations.
The direct way to build the kernel is to type:
```
make Image.gz modules dtbs
```
You can also speed it up using parallelism by running
```
make -j2 Image.gz modules dtbs
```
where the number in `-j2` defines how much parallelism to use, which may help because the Pi has 4 CPU cores. I do not recommend this, however, because the Pi has very limited main memory (512 MB) and when it runs out of memory, this may crash or slow down the compilation up to the point where the Pi is not responsive at all. Use at your own risk.

It may also be a good idea to plug the Pi into a wall charger and let it work over night. Note that when the SSH connection breaks, the compilation will also stop. You can avoid this by using the `nohup` command. You could run
```
nohup make Image.gz modules dtbs &
```
to start the building process in the background. This will continue even if you disconnect the SSH connection. The output of the building process will be written into a file called `nohup.out`. You can check with `top` whether the build process is still active. If so the CPU utilization should be high.

Generally, it should be safe to interrupt the building process by pressing `Ctrl+C` (or `killall make` if it is running in the background) and restart it by running the corresponding make command again.

### Installing and running the new kernel
First run the following from the `~/linux` directory. This will take a few minutes, but not nearly as long as building the kernel.
```
sudo make modules_install
```

Next you need to copy the kernel and some associated files to the boot partition.
```
sudo cp arch/arm64/boot/Image.gz /boot/firmware/kernel8-custom.img
sudo cp arch/arm64/boot/dts/broadcom/*.dtb /boot/firmware/
sudo cp arch/arm64/boot/dts/overlays/*.dtb* /boot/firmware/overlays/
sudo cp arch/arm64/boot/dts/overlays/README /boot/firmware/overlays/
```

open the boot configuration with `sudo nano /boot/firmware/config.txt` and add to the end the line

```
kernel=kernel8-custom.img

```
You are now fully set up to boot the new kernel.
Reboot the Pi using

```
sudo reboot
```

Once the Pi is back running, check that the correct kernel is used by

```
uname -r
```

