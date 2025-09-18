---
title: DM898 - Parameterized Algorithms
layout: teaching
course_id: dm898-25
---

### Ticket-to-Ride

The map consists of different cities. You are given some pairs of cities that you should pairwise
connect with a train network (e.g. Amsterdam to Copenhagen and Madrid to Marseille). Making a connection between two cities requires a certain number of resources of different kinds, marked in color on the map, sometimes
direct connection may not be possible, but you could connect them also indirectly. 

For example, connecting Copenhagen with Cologne might cost 3 gray resources, connecting Copenhagen to Stockholm might cost 3 yellow and 3 white resources. Connecting Copenhagen directly to Amsterdam might not be possible, but Amsterdam-Cologne-Copenhagen may be.

Of each resource you only have a limited budget. How do you connect all pairs?

![Ticket-to-Ride](ticket-to-ride.jpg)

### Risk (possibly difficult)

The game map consists of different regions. Your enemy has placed their troops on some of the regions. 
You now want to occupy a set of regions and that you can also defend by placing your own troops on
strategically good regions. 

We assume that after your decision, the enemy will freely move their troops between adjacent regions and
try to attack you.
The enemy can gather troops on a region where you also have troops, which leads to a battle. When this happens, the number of troops of both you and the enemy reduces at the same rate until either you or the enemy has no troops left on this region (and the other one wins). If the enemy wins, they can move on from there.
 
You want to select a set of regions to occupy and place your troops on some regions (without enemy troops) such that no matter their sequence of moves, the enemy cannot capture any of your occupied regions.
Note that you cannot move your troops after the initial placement.
Each occupied region gives you a specific profit that you want to maximize.
In some variant, also fully occupied continents (Europe, Africa, etc.) give you a profit.

![Risk](risk.jpg)


