---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---
Note that you need internet connection

Change to home directory and download the source code of the Raspberry Pi branch of the Linux kernel.
This download may take a while.

```
cd ~
git clone --depth=1 https://github.com/raspberrypi/linux
```

The following instructions change the version of the source code to one specific snapshot on which the project has been tested.

```
cd linux
git reset --hard 8057c4a5107b5daaa075c646a1ccc313c456d779
git pull
```

We first install some tools required to build the kernel.
```
sudo apt install bc bison flex libssl-dev make
```
Press `Y` when asked to confirm.

We set the default configuration for the kernel. This is assuming you are still in the directory with the source code. Otherwise change into it using `cd ~/linux`.
```
KERNEL=kernel8
make bcm2711_defconfig
```
Open the file `.config` for example using `nano .config`. Find the line `CONFIG_LOCALVERSION=-v8". For each team member add to it `-XYZ` where `XYZ` are the first three letters of your last name. For example, if your team members are Rohwedder and Larsen, change the line to:
```
CONFIG_LOCALVERSION="-v8-ROH-LAR"
```
**Important:** Replace `ROH-LAR` with the correct letters in the line above.

Compile the kernel. Note that this will take several hours.
The direct way is to type:
```
make Image.gz modules dtbs
```
You can also speed it up using parallelism by running
```
make -j2 Image.gz modules dtbs
```
where the number in `-j2` defines how much parallelism to use. I do not recommend this because the Pi has very limited main memory (512 MB) it may run out of memory, which can crash or slow down the compilation (up to the point where the Pi is not responsible at all). Use at your own risk.

It may also be a good idea to compile over night. Note that when the SSH connection breaks, the compilation will also stop. You can avoid this by using the `nohup` command. Run
```
nohup make Image.gz modules dtbs &
```
to run building process in the background. This will continue even if you disconnect the SSH connection. The output of the building process will be written into a file called `nohup.out`. You can check with `top` whether build process is still active. If so the CPU utilization should be high.

Generally, it should be safe to interrupt the building process by pressing `Ctrl+C` (or `killall make` if it is running in the background). and restart it by running the corresponding make command again.
```
sudo make modules_install
```

Next we need to install the newly compiled kernel.
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

Reboot the Pi using

```
sudo reboot
```

Once the Pi is back running, check that the correct kernel is used by

```
uname -r
```

