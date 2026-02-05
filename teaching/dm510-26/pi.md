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
Unpack the Pi and the case and put them together using the screws. Keep the plastic bag of the case so that you can later put the assembled Pi and the SD card (including adapter) inside it. The assembled Pi should look as below:
![Pi](img/pi_assembled.jpg){: width="250" }

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
