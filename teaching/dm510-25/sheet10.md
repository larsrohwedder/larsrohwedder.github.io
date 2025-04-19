---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

# Exercise Sheet for Tutorial 10

**Before** the tutorial session, try your best to solve problems below and be prepared to discuss them at the tutorial session.

### Related to Chapter 16
1. Buffer-overflow attacks can be avoided by adopting a better programming methodology or by using special hardware support. Discuss these
2. What is the purpose of using a "salt" along with a user-provided password? Where should the salt be stored, and how should it be used?
3. An experimental addition to UNIX allows a user to connect a watchdog program to a file. The watchdog is invoked whenever a program requests access to the file. The watchdog then either grants or denies access to the file. Discuss two pros and two cons of using watchdogs for security.
4. To protect against buffer overflows, some compilers writes "canary words" after the end of a buffer. These are specific values that should not be modified by a correctly working program. Describe how canary words can be useful in protecting against buffer overflows.
4. Make a list of six security concerns for a bank's computer system. For each item on your list, state whether this concern relates to physical, human, or operating-system security.
5. What commonly used computer programs are prone to man-in-the-middle attacks? Discuss solutions for preventing this form of attack.
6. **(important)** For an encrypted TCP/IP connection, one typically uses symmetric encryption, but asymmetric encryption is required for the initial key exchange.
    - Explain how this key exchange can be performed 
    - Suppose you connect to a website via HTTPs (HTTP inside an encrypted TCP connection) for the first time and your computer does not have a copy of the website's public key. If you would simply download the public key from this website before establishing the secure connection, what kind of security problems might occur?
    - The previous problem is usually solved using trusted authorities. Imagine there is an authority and every computer is delivered with this authority's public key. Websites can request from the authority to confirm (using digital signature) that their public keys belongs to their host name (e.g. that key 123 is the correct public key for `larsrohwedder.com`). Explain the procedure in detail and how it resolves the previous problem.

### Related to Chapter 17
1. A Burroughs B7000/B6000 MCP file can be tagged as sensitive data. When such a file is deleted, its storage area is overwritten by some random bits. For what purpose would such a scheme be useful?
2. In a ring-protection system, level 0 has the greatest access to objects, and level n (where n > 0) has fewer access rights. The access rights of a program at a particular level in the ring structure are considered a set of capabilities. What is the relationship between the capabilities of a domain at level j and a domain at level i to an object (for j > i)?
3. The RC 4000 system, among others, has defined a tree of processes (called a process tree) such that all the descendants of a process can be given resources (objects) and access rights by their ancestors only. Thus, a descendant can never have the ability to do anything that its ancestors cannot do. The root of the tree is the operating system, which has the ability to do anything. Assume that the set of access rights is represented by an access matrix, A. A(x,y) defines the access rights of process x to object y. If x is a descendant of z, what is the relationship between A(x,y) and A(z,y) for an arbitrary object y?
4. What protection problems may arise if a shared stack is used for parameter passing?
5. Consider a computing environment where a unique number is associated with each process and each object in the system. Suppose that we allow a process with number n to access an object with number m only if n > m. What type of protection structure do we have?
6. Consider a computing environment where a process is given the privilege of accessing an object only n times. Suggest a scheme for implementing this policy.
7. Why is it difficult to protect a system in which users are allowed to do their own I/O?
8. Capability lists are usually kept within the address space of the user. How does the system ensure that the user cannot modify the contents of the list?
9. The access-control matrix can be used to determine whether a process can switch from, say, domain A to domain B and enjoy the access privileges of domain B. Is this approach equivalent to including the access privileges of domain B in those of domain A?
10. What hardware features does a computer system need for efficient capability manipulation? Can these features be used for memory protection?
11. Discuss the strengths and weaknesses of implementing an access matrix using capabilities that are associated with domains.
12. What is the need-to-know principle? Why is it important for a protection system to adhere to this principle?
13. Describe how the Java protection model would be compromised if a Java program were allowed to directly alter the annotations of its stack frame.
14. How does the principle of least privilege aid in the creation of protection systems?



### In class
Discuss the exercises prepared at home
