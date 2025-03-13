---
title: DM510 Operating Systems
layout: teaching
course_id: dm510-25
---

The information on this page may be subject to changes during the run of the semester.
### Lectures

{% include table.html content="
| Week |   Date     |              Topic              | Material                 |
| ---- | ---------- | ------------------------------- | ------------------------ |
| 6    | 03-02-2025 | Introduction, Overview          | Chapter 1, [slides](lecture1.pdf) |
| 6    | 06-02-2025 | Operating Systems Structures    | Chapter 2, [slides](lecture2.pdf) |
| 7    | 11-02-2025 | Processes                       | Chapter 3, [slides](lecture3.pdf) |
| 8    | 18-02-2025 | Threads and Concurrency         | Chapter 4, [slides](lecture4.pdf) |
| 8    | 19-02-2025 | CPU Scheduling                  | Chapter 5, [slides](lecture5.pdf) |
| 9    | 25-02-2025 | Synchronization                 | Chapter 6+7, [slides](lecture6.pdf) |
| 10   | 04-03-2025 | Deadlocks                       | Chapter 8, [slides](lecture7.pdf) |
| 10   | 06-03-2025 | Main Memory & Virtual Memory    | Chapter 9+10 [slides](lecture8.pdf) |
| 11   | 13-03-2025 | Main Memory & Virtual Memory    | Chapter 9+10 [slides](lecture9.pdf) |
| 11   | 25-03-2025 | Mass Storage Media              | Chapter 11               |
| 13   | 27-03-2025 | I/O                             | Chapter 12               |
| 13   | 01-04-2025 | File Systems                    | Chapter 13               |
| 14   | 08-04-2025 | File Systems                    | Chapter 14+15            |
| 15   | 10-04-2025 | Security and Protection         | Chapter 16+17            |
| 15   | 22-04-2025 | Virtual Machines                | Chapter 18               |
| 17   | 05-05-2025 | Networks                        | Chapter 19               |
| 19   | 15-05-2025 | Exam Preparation                |                          |
" %}


### Tutorials
Please see your individual calendar for the exact date.


{% include table.html content="
| Week  |              Topic           | Exercises        |
| ----- | ---------------------------- | ---------------- |
| 7     | Chapter 1+2                  | [Sheet1](sheet1) |
| 8     | Chapter 3+4                  | [Sheet2](sheet2) |
| 9     | Chapter 5                    | [Sheet3](sheet3) |
| 10    | Chapter 6+7                  | [Sheet4](sheet4) |
| 11    | Chapter 8                    | [Sheet5](sheet5) |
| 12    | Chapter 9+10                 | [Sheet6](sheet6) |
| 13    | Chapter 11+12                | TBD              |
| 14    | Chapter 13+14+15             | TBD              |
| 15    | Chapter 16+17                | TBD              |
| 17    | Chapter 18+19                | TBD              |
" %}

### Programming Projects

{% include table.html content="
|   Release  |  Deadline  |             Topic           | Resit Deadline |
| ---------- | ---------- | --------------------------- | -------------- |
| 06-02-2025 | 04-03-2025 |  [System Call](project1)    | TBD            |
| 06-03-2025 | 08-04-2025 |  [Kernel Module](project2)  | TBD            |
| 08-04-2025 | 20-05-2025 |  File System                | TBD            |
" %}

The projects are submitted in teams of two students (in exceptions: three). Each submission consists of **source code**, **report**, and **screen recording**. A zip-archive with the following structure (replacing X by the appropriate number) should be submitted to itslearning:
{% highlight terminal %}
projectX/
projectX/report/
projectX/sources/
projectX/video/
{% endhighlight %}

- source code: submit the source code of the project. If the project requires you to start with a codebase, for example the linux kernel, then only include the files you have changed (using the original directory structure).
- report: submit a pdf (5-10 pages) describing your solution and decisions **in English language**, if applicable explain what problems have occurred and possible limitations of solution. Should not contain full source code. Can be written for example in LaTeX, OpenOffice, or Microsoft Word. The report must include at least: a small introduction; a description of the design decisions you have made; a description of your implementation (here, it is fine to use snippets of interesting code, where you explain what you have done); a description and motivation of the tests you have made to verify that your solution works in both valid and invalid usage; a small conclusion.
- screen recording: in this recording you show that your implementation is working correctly. During the session you should also perform all or some of the tests that you described in your report. In your report you should refer to the tests you performed by giving the precise time in the video file. The recorded session should be maximally 5 minutes long and have a maximal size of 50MB. 
For recording the desktop session you can e.g. use Zoom (which is probably easiest) or the tool gtk-recordmydesktop. The video does not need to include any audio, and if the text in the command line you are using is readable, the quality is good enough. Make sure that the video format is a standard video format (such that mplayer or VLC can play it).

If the submission deviates significantly from these requirements, it will be considered as not submitted.

Grading is done according to the following rubric. Different criteria are weighted differently. If one or more criteria are graded with *needs improvement*, a resit (second try) has to be done for the project. 
{% include table.html collapse="show rubric" content="
| Criterion     | Excellent         |  Good                | Satisfactory        | Needs improvement        |
| ------------- | ----------------- | -------------------- | ------------------- | ------------------------ |
| **Functionality**: Are the required features implemented, correct, and tested? | All features implemented correctly, if applicable optional/additional features | Major features implemented, no bugs or only minor bugs | Project can be run and some functionality visible | Project does not compile or does not run or does not behave in a sensible way |
| **Source code documentation and style** | Naming, indentation, comments consistent and according to industry standards | Code is easy to understand and contains solid documentation | Not enough documentation, but with some effort code is understandable | Code is very hard/impossible to understand |
| **Structure of report**: Are the contents of the report presented in logical order? Are the contents broken into reasonably small pieces/sections? | According to standards of scientific papers | Contents are structured in a sensible way | Some structure visible, but not enough for convenient readability | Contents are arranged in a highly confusing way |
| **Language, typesetting, and formatting of report** | Typesetting and formatting comparable to scientific papers, little or no typos and grammar mistakes, writing is compact and precise | Careful writing, solid formatting and typesetting | Understandable, but contains many typos and grammar mistakes | Not understandable or AI generated |
| **Contents of report** | Several possible design options are stated, design decisions are justified properly, results and tests are discussed carefully | Design decisions clearly documented, some amount of justification and discussion | It is understandable what was done in the project | It is not understandable how the goals of the project were addressed |   
" %}


### Exam, grading, and repeat students

There is a written exam at the end of the course (June 13th for first try and August 6th for second try).
The exam counts as 80% of the final grade with
the remaining 20% coming from the the programming projects. Both parts have to be passed.

The topics of the exam are the following:
- The book chapters mentioned in the lecture list restricted to content discussed in lectures and exercise sessions (see slides and exercise sheets).
- Exam exercises comparable to those on exercise sheets
- One exercise to test rudimentary knowledge of topics from programming projects

Repeat students who have participated in the course in previous years will need to submit the projects again.
In case they want to reuse their own submissions from the previous year (adapted to the changes if necessary), they should submit it alone.
