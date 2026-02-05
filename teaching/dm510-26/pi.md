---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-26
---

The purpose of these instructions is to assemble a Raspberry Pi Zero 2W, install and configure its operating system
so that you can access it via a SSH (remote terminal).

You should have:
- one Raspberry Pi Zero 2W
- A micro SD card and SD adapter
- a micro USB to USB cable
- a protection case

Please treat all hardware with great care so that future generations of students can enjoy them as well. 

# Preparation
Unpack the Pi and the case and put them together using the screws. Keep the plastic bag of the case so that you can later put the assembled Pi and the SD card (including adapter) inside it. The assembled Pi should look as follows:

![Pi](img/pi_assembled.jpg){: width="400" }

In order to connect a computer via SSH to the Pi, both need to be in the same network. The easiest way is to have both be in the same wireless LAN (WIFI). Since Eduroam (the WIFI at the University) requires complicated authentification with a certificate, either use your home WIFI or create a hotspot with your mobile phone, which you can enter with both your computer and the Pi.

# Setting up the operating system
The Pi uses an SD card instead of a hard drive. The SD card is currently empty and you need to install a Linux operating system on it and configure it.
Fortunately, there is a very tool that makes this very easy: On your regular computer download the [Raspberry Pi Imager tool](https://www.raspberrypi.com/software/), which is available for Linux, MacOS, and Windows.
Unpack and insert the micro SD card (possibly by plugging it into the SD adapter) into your computer and run the Imager tool.
- Under Raspberry Pi Device, choose `Raspberry Pi Zero 2W`
- Under OS, choose `Raspberry Pi OS (64-bit)`
- Under storage, choose the SD card
- Click `Next`

In the popup choose `edit settings`
- Check and choose a hostname, for example raspberry.local
- Check and select a username and password
- Check and configure a wireless LAN
- Under `Services` check `Enable SSH` and `Use password authentification`

Press `Save` and then `Yes`. Confirm to erase the contents of the SD card.
The Imager tool is now writing to the SD card, which will take a while.

# Taking the Pi for a test run
Remove the SD card from your computer and insert it into the Pi. Plug the micro USB cable into one of the two sockets of the Pi and the other side into some power source, which can be a USB socket of your computer or a USB wall charger.
The LED on the Pi should turn on. It can take a minute or so for the Pi to boot and to connect to the WIFI you specified.

On your computer open an SSH client and connect to raspberry.local (or whatever name you choose in the configuration). Log in with the username and password you configured. On a Unix command line this would work as follows (assuming the username is pi):
```
ssh pi@raspberry.local
```
Accept the certificate if asked.
Now you should have terminal access to the Pi. Try the following:
```
    cd /sys/class/leds/
```
You are now in the directory corresponding to the onboard LED.
Change the permission of the LED so that any user can write to it:
```
    chmod a+w 
```
Turn it off using
```
    echo 0 > 
```
Turn it on again using
```
    echo 0 > 
```
If this worked, congratulations, you have access to the Pi!

# Connecting to the Pi via USB
Instead of WIFI, it is also possible to make a network connection to the Pi via the USB cable.
This requires slightly more effort and may be more prone to errors. If you would like to try it, follow these
[instructions](https://www.raspberrypi.com/news/usb-gadget-mode-in-raspberry-pi-os-ssh-over-usb/).

I (Lars) have followed these instructions successfully himself, but experienced the following problem on Linux: the connection sometimes could not be established if the Pi has not finished booting at the time the USB cable is connected. I could fix this by first connecting the Pi to a power source using the outer micro USB socket and then only after the Pi has finished booting up, connect the other micro USB to the computer. This requires two micro USB cables. Make sure that the micro USB cable that connects the Pi to the computer is a data cable (for example the one that you got from the university). In contrast some USB cables are only for power.
