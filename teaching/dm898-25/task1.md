---
title: DM898 - Parameterized Algorithms
layout: teaching
course_id: dm898-25
---

### Project - Task 1

You and your team were given one of the settings from [here](project).

# Task 1.1: Formalize problem

Your first task is to formalize your problem setting. This includes a definition
of the input and solution.
Since you are going to work with this problem in the entire project, it is important
to do this carefully. A clean and intuitive problem statement makes it much easier to develop algorithms.

**General guidelines:**
- mathematical precision: from your definitions it should be possible to unambiguously defer whether some input or solution is valid for your problem. Some of the problems settings are formulated in an intentionally vague way. In such cases, you need to make a decision on how you want to define it. Make decisions that result in natural problems.
- intuition/readability: give intuitive explanations next to the mathematical statements. Think about good notation to use in your problem.
- good level of abstraction: much like in programming, you should unnecessarily not ``hardcode'' details of the problem. For example, if in your problem contains the resources brick, grain, and wool, but this background plays no role in the actual rules, then it is better to introduce them as m resources R1,R2,...,Rm
and omit the details. A higher level of abstraction makes it possible to apply ideas also to closely related problems, but also generally leads to cleaner and more fundamental ideas. In some cases, where a generalization/abstraction hides central properties of the problem and prevents you from exploiting them algorithmically, you might not want to use the more general formulation.

**Further requirements:**
- All problem settings have an underlying graph structure. In line with the abstraction guideline, your problem definition should contain a graph and not specific terminology (e.g. do not use ``street'' and ``crossing'' if you can use the terminology edge and vertex). This makes it easier to transfer ideas developed for other graph problems to your problem.
- Specify possible parameters of interest in your problem. You do not want to restrict the overal input size, specifically the size of the underlying graph in your problem. The parameters should be natural, perhaps even be ``small'' in the board game. Natural parameters include: size of the solution, some input number, size of some input set. Ideally, we want to be able to efficiently solve the problem if your parameter (or a combination of several) is small. Perhaps you can already see an XP algorithm by naive enumeration?
- Depending on your setting, it may be a very complicated problem. In that case, think about restrictions of the problem that make it easier to start. You might even identify a natural restriction and develop a specialised algorithm for it. If on the other hand your problem is very simple, think about generalizations that could be of interest.

# Task 1.2: ILP formulation

Write an integer linear programming formulation that is equivalent to your previously formalized problem
definition.
- What are the variables of the problem?
- What is the objective?
- What are the constraints?

Describe clearly each of the formulars that you give.
Look at other examples of related ILP formulations to get ideas for how to write the ILP.
If it is too hard, start with a less complicated/restricted variant of your problem.
