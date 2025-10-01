---
title: DM898 - Parameterized Algorithms
layout: teaching
course_id: dm898-25
---

# Course notes

Weekly summary and slides, exercises from class

{% include collapse.html collapse="Week 36" content="
In the lecture on September 1st (see [slides](lecture1.pdf)), we discussed motivation for parameterized algorithms
and relation to Operation Research. Then we looked at the preprocessing rules for Vertex Cover as in Chapter 1 of the textbook.

In the lecture on September 3rd (see [slides](lecture2.pdf)), we discussed dynamic programming and in particular the algorithm for Steiner tree, see also Chapter~6.1.2 from the textbook.

The first [exercise sheet](exer1.pdf) was given out. Please prepare solutions until Wednesday next week.
" %}

{% include collapse.html collapse="Week 37" content="
In the lecture on September 10th, we discussed solutions to the first exercise set.
For the dynamic programming exercise, see also [Dynamic Program for Vertex Coloring](solution-coloring-dp.pdf).

In the lecture on September 11rd, we recalled basics from complexity theory by discussing the complexity questions from the first exercise sheet.

The second [exercise sheet](exer2.pdf) was given out. Please prepare solutions until Wednesday next week.
" %}

{% include collapse.html collapse="Week 38" content="
The lecture on September 17th unexpectedly did not happen.

In the lecture on September 18th, we started with the topic Kernelization and Preprocessing (see [slides](lecture3.pdf)). We covered Chapters 2.1 (formal definitions), 2.2.1 (Vertex Cover), and 2.2.3 (Edge Clique Cover) from the textbook. In the second half, we discussed solutions to exercise sheet 2.

The third [exercise sheet](exer3.pdf) was given out. Please prepare solutions until Friday next week.
" %}

{% include collapse.html collapse="Week 39" content="

In the lecture on September 23rd, we had the second part of topic Kernelization and Preprocessing (see [slides](lecture4.pdf)). We covered Chapter 2.6 (Sunflower Lemma) from the textbook and the role of preprocessing in practice on integer linear programming, based on Wolsey Chapter 7.6.

Please note the annoncement regarding the project on ItsLearning.

In the lecture on September 26th, we discussed exercise sheet 3. Then started with the topic branching (see [slides](lecture5.pdf)). We covered Chapter 3.0 (formalism of branching) and Chapter 3.1 (Vertex Cover) from the textbook. We didn't get to the algorithm for Closest String yet.
" %}

{% include collapse.html collapse="Week 40" content="

In the lecture on September 30rd, we finished the example on Closest String, see [slides](lecture5.pdf)),
from Chapter 3.5 of the textbook.

We practiced ILP modelling on examples from the [second exercise sheet](exer2.pdf).

Topic of the lecture on October 1st was Branch-and-Bound, see [slides](lecture6.pdf). This does not appear in the main textbook. For reference, see Chapter 7 in Wolseley's book.
" %}


Materials by topics

{% include table.html content="
| Topic         | Lecture/Exercise          |  Material covered    |
| ------------- | ----------------- | -------------------- |
| Introduction  | [Introduction and Overview](lecture1.pdf) | Motivation, examples of FPT algorithms |
|               | [Introduction (cont'd)](lecture2.pdf) | Dynamic Programming |
|               | [Exercise Sheet 1](exer1.pdf) |  |
|               | [Exercise Sheet 2](exer2.pdf) |  |
| Preprocessing and Kernelization  | [Preprocessing and Kernelization I](lecture3.pdf) | Formalism of Kernelization, kernels for Vertex Cover and Edge Clique Cover |
|               | [Preprocessing and Kernelization II](lecture4.pdf) | Sunflower Lemma, Preprocessing in practice (ILPs) |
|               | [Exercise Sheet 3](exer3.pdf) |  |
| Branching     | [Branching I](lecture5.pdf) | Formalism of branching, Vertex Cover, Closest String |
|               | [Branching II: Branch-and-Bound](lecture6.pdf) | Combinatorial Branch-and-Bound, LP-based Branch-and-Bound |
|               | [Exercise Sheet 4](exer4.pdf) | |
"
%}


# Project

In the project, you will work together in teams of 2 on a board game inspired problem.
The possible settings can be found [here](project). Each team will be given a different setting based on preferences they submit (details to follow).
Your tasks are:

1. Formally define your problem and possibly variants (including parameterizations) of it and write an ILP model for it. See [here](task1) for details.
2. Develop an initial algorithm based on reduction rules, branching strategies, or dynamic programming.
It should be a correct and sensible algorithm, but formal guarantees on running time, etc. are not required.
3. Evaluate the complexity of your problem and variants, by showing NP-hardness and possibly hardness with respect to some parameters. 
4. Choice between: (a) Establish some non-trivial theoretical result for your problem, for example FPT algorithm with respect to some parameters (b) implement an algorithmic idea and run experiments

Remarks:
- some of the problems are more complicated than others. You are free to make simplifying assumptions, for example, removing some constraints from the problem.
- start with the easiest, not the most complicated techniques from the course. Similarly, start by simplifying the problem as much as you can, to obtain initial ideas that might transfer to more general variants.
- Goals: nice ideas, efficiency, generality of the algorithm (priority in this order) 
- These are difficult projects. I do not know the outcome of them. It is expected that you run into obstacles or get stuck at some point. Do not give up easily!
- More to come
