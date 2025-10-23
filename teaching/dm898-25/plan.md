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

{% include collapse.html collapse="Week 41" content="

In the lecture on October 6th, we discussed an kernel for Vertex Cover based on the LP relaxation, see [slides](lecture7.pdf),
which follows Chapter 2.5 of the textbook.

In the lectures on October 7th and October 9th, we looked at FPT algorithms for integer linear programs, specifically the Eisenbrand-Weismantel algorithm, see [slides](lecture8.pdf) and [more slides](lecture9.pdf). We also looked at an application for Closest String, see [exercises](exer5.pdf). This is based on relatively new research that came out after the textbook appeared. As additional material see the [lecture notes](EW-notes.pdf).

" %}

{% include collapse.html collapse="Week 43" content="

In the lecture on October 21th, we discussed the Exponential Time Hypothesis and a reduction from Clique to 3-SAT. The reduction appears indirectly in the textbook (via the 3-colorability problem). For the direct proof, see [lecture notes](ETH-notes.pdf).

In the lectures on October 23th, we have seen the proof of the Sparsification Lemma (for 3-SAT). The proof is omitted in the textbook, but you can find them in the [lecture notes](ETH-notes.pdf).

" %}


<br>

### Materials by topics

<br>

{% include table.html content="
| Topic         | Lecture/Exercise          |  Material covered    |
| ------------- | ----------------- | -------------------- |
| Introduction  | [Introduction and Overview](lecture1.pdf) | Motivation, examples of FPT algorithms |
|               | [Introduction (cont'd)](lecture2.pdf) | Dynamic Programming |
|               | [Exercise Sheet 1](exer1.pdf) |  |
|               | [Exercise Sheet 2](exer2.pdf) |  |
| Preprocessing | [Preprocessing and Kernelization I](lecture3.pdf) | Formalism of Kernelization, kernels for Vertex Cover and Edge Clique Cover |
|               | [Preprocessing and Kernelization II](lecture4.pdf) | Sunflower Lemma, Preprocessing in practice (ILPs) |
|               | [Exercise Sheet 3](exer3.pdf) |  |
| Branching     | [Branching I](lecture5.pdf) | Formalism of branching, Vertex Cover, Closest String |
|               | [Branching II: Branch-and-Bound](lecture6.pdf) | Combinatorial Branch-and-Bound, LP-based Branch-and-Bound |
|               | [Exercise Sheet 4](exer4.pdf) | |
| FPT via LP    | [FPT via Linear Programming I](lecture7.pdf) | LP based kernel for Vertex Cover |
|               | [FPT via Linear Programming II](lecture8.pdf) | Eisenbrand-Weismantel algorithm for ILP |
|               | [FPT via Linear Programming III](lecture9.pdf) | Proof of proximity theorem and Steinitz Lemma |
|               | [Lecture notes](EW-notes.pdf) | |
|               | [Exercise Sheet 5](exer5.pdf) | |
| Complexity Theory| [Parameterized Complexity Theory I](lecture10.pdf) | Exponential Time Hypothesis, Clique |
|               | [Parameterized Complexity Theory II](lecture11.pdf) | Proof of Sparsification Lemma |
|               | [Lecture notes](ETH-notes.pdf) | |
"
%}
