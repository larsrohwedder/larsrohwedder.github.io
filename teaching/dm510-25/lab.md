---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# IMADA Virtual Computer Lab

The Computer Lab is a collection of servers available for students and employees at IMADA to conduct ordinary course teaching and small-scale experiments. The system should not be used for backup or very long-running experiments, as it does not it self have backup and may be completely reinstalled when needed. Any important data generated on the system should therefore be transferred elsewhere.

### Access
The IMADA Virtual Computer Lab consists of 4 servers accessible via SSH by students and employees at IMADA. Their hostnames are
* imada0.stud-srv.sdu.dk
* imada1.stud-srv.sdu.dk
* imada2.stud-srv.sdu.dk
* imada3.stud-srv.sdu.dk

The servers are only accessible internally at SDU, e.g., being on the SDU network. This can be achieved by either being physically at SDU using the eduroam network or enabling the (SDU VPN)[https://any.sdu.dk/].

If you have a student account, your username is simply your ordinary username, e.g., `john42`. If you have an employee account your username is either your ordinary username or your ordinary username with domain prefix, e.g., either `john42` or `nat-sdu\john42`. Whether you need to prefix with domain as employee depends on when your account was created. If it is later than approximately 2019 then the prefix should not be needed.

{% include box.html style="bg-warning" text="If you need to prefix with domain, and type the username on the command line, then the backslash needs to be escaped. For example `ssh nat-sdu\\john@imada0.stud-srv.sdu.dk`" %}

Instead of typing your password each time you establish an ssh connection, you can also authenticate
more conveniently by installing ssh keys on the server and your computer, see 
https://help.ubuntu.com/community/SSH/OpenSSH/Keys.

### Graphical Interface
While the servers are only remotely accessible it is possible to forward GUIs to your computer. This can be done either using classical X-forwarding, i.e., passing `-X` to `ssh`, or using (X2Go)[https://wiki.x2go.org/doku.php/start] to get a remote desktop experience. An X2Go client is available for both Windows, macOS, and Linux.

{% include box.html style="bg-warning" text="When creating an X2Go session, it is important that you change the session type to `XFCE`, which is the desktop environment installed on the servers." %}

