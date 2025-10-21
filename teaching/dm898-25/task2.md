---
title: DM898 - Parameterized Algorithms
layout: teaching
course_id: dm898-25
---

### Project - Task 2

You and your team were given one of the settings from [here](project) and you have formalized the problem
in the first task. Next, you will design an exact solver for it using Branch-and-Bound. Branch-and-Bound is a general framework for exact solvers for optimization problems with a lot potential for problem-specific tuning.
For the structure of a Branch-and-Bound algorithm see [lecture slides](https://larsrohwedder.com/teaching/dm898-25/lecture6.pdf). You are not expected to implement your algorithm.

**General guidelines:**
- In principle, an LP-based branch-and-bound algorithm (as briefly described in the lecture slides) combined with your ILP formulation from the first task would be a decent algorithm. The intention of this task is of course not to simply do this, but to be creative. You can base your algorithm on linear programming, but you do not have to. Similar to the examples of Vertex Coloring and Independent Set, you can also design a Branch-and-Bound algorithm entirely without linear programming. Either way, it should include substantial problem-specific ideas.
- Since you are not testing your algorithm in practice it may be hard to say what are the *right* design choices. Design the algorithm in a sensible way, so that it is plausible that it will perform well. Some specific guidelines also appear later.

**Requirements:**
- Your algorithm should be correct and exact, that is, it always returns the optimal solution, but it does not need to have guarantees regarding running time (apart from terminating in finite time).
- The algorithm must follow the Branch-and-Bound structure.
- Give a brief overview of the general structure of a Branch-and-Bound algorithm, repeating the main concepts of Branch-and-Bound. Then specify:
- *The branching strategy.* Each time you select subproblem to continue on, your algorithm needs to branch on some decision in this subproblem. Ideally, a branching decision leads to a lot of progress, so that you will avoid branching too often. For example, it would not be a good idea to branch on some decision that seems unimportant for the overall structure of the solution, like on the two endpoints of an isolated edge in a Vertex Cover instance.
- *Instance reduction / preprocessing.* Either before running Branch-and-Bound or before each branching, you can try to simplify an instance/subproblem. Come up with problem specific rules that may allow you to make the instance smaller without changing the result.
- *Bounding.* Find good heuristical bounds for your problem, for example by a Greedy algorithm. Good bounds can speed up a Branch-and-Bound algorithm significantly, since they help prune more subproblems. You can of course also use a linear programming relaxation to obtain bounds.
- Depending on your problem some of the parts are more and others are less relevant for tuning. Decide for yourself what to focus on.

# Submission

Your submission is a report in PDF format. An appropriate length is 5 pages. It is highly recommended to write this report using LaTeX.

You will submit a draft on ItsLearning. On this draft you will get feedback, which you can incorporate
afterwards. The final report will consist of revised versions of the drafts for each of the 4 tasks. 
Although you receive feedback for each draft, only the final report will be graded.
