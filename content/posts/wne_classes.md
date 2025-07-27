+++
date = '2025-07-27T10:32:17-04:00'
draft = false
title = 'Computer Architecture Classes @ WNE'
tags = ["VHDL", "Embedded Systems"]
thumbnail = "img/20250727-wne/clogo.png"
+++

Many, many, many years ago, I took a small career detour and taught for one year at a regional college in MA. There, I was assigned to teach several introductory computer engineering courses. On this page, I’m sharing the slides from the most memorable ones: real-time kernels (a fancy term for embedded RTOS), VHDL simulation and synthesis, and an electronics summer camp for 8–12-year-olds. The other classes were more prosaic. In a fun twist, almost 15 years later I’m once again working with VHDL. Since my slides were all tucked away on a hard-disk drive, I figured—why not take this opportunity to put everything online for posterity? Enjoy!

---

## CPE 462 – VHDL: Simulation and Synthesis – Fall ’11

Syllabus [PDF](/img/20250727-wne/cpe462/fall_2011_cpe462_syllabus.pdf)

### Topic 1: Introduction to reconfigurable computing
- Introduction [PDF](/img/20250727-wne/cpe462/topic-01.pdf)

### Topic 2: Review
- a) Review of Combinational Logic [PDF](/img/20250727-wne/cpe462/topic-02a.pdf)
- b) Review of Sequential Logic [PDF](/img/20250727-wne/cpe462/topic-02b.pdf)

### Topic 3: Introducing Simulation and Prototype Tools
- a) Introduction to VHDL [Slides PDF](/img/20250727-wne/cpe462/topic-03a.pdf) Source code: [nand gate](/img/20250727-wne/cpe462/topic3a-nand.zip), [d-flip-flop](/img/20250727-wne/cpe462/topic3a-DFF.zip), [nand + d-flip-flop](/img/20250727-wne/cpe462/topic3a-n_dff.zip)
- b) Xilinx Development Environment [Slides PDF](/img/20250727-wne/cpe462/topic-03b.pdf) [Practice Solutions](/img/20250727-wne/cpe462/topic-03b-practice.pdf)
- c) Aldec Active HDL Environment [Slides PDF](/img/20250727-wne/cpe462/topic-03c.pdf) [Practice Solutions](/img/20250727-wne/cpe462/topic-03c-practice.pdf) Source code: [Practice #1: DFF + nand](/img/20250727-wne/cpe462/topic3c-ex1.zip), [Practice #2: SR latch](/img/20250727-wne/cpe462/topic3c-ex2.zip)
- d) Test-Benches [Slides PDF](/img/20250727-wne/cpe462/topic-03d.pdf) [Practice Solutions](/img/20250727-wne/cpe462/topic-03d-practice.pdf) [Template](/img/20250727-wne/cpe462/test-bench-template.txt) Source code: [4-to-1 MUX](/img/20250727-wne/cpe462/topic3d-4to1_testbench.zip), [Practice #1](/img/20250727-wne/cpe462/topic3d-ex1.zip), [Practice #2](/img/20250727-wne/cpe462/topic3d-ex2.zip)

### Topic 4: VHDL Foundations
- a) Basic Synthesizable Data Types [PDF](/img/20250727-wne/cpe462/topic-04a.pdf) [Practice Solutions](/img/20250727-wne/cpe462/topic-04a-practice.pdf)
- b) Types and Arrays [PDF](/img/20250727-wne/cpe462/topic-04b.pdf) [Exercise #4 Test-Bench](/img/20250727-wne/cpe462/topic4b-ex4.txt), [Exercise #5 Test-Bench](/img/20250727-wne/cpe462/topic4b-ex5.txt) [Practice Solutions](/img/20250727-wne/cpe462/topic-04b-practice.pdf)
- c) Operators and Attributes [PDF](/img/20250727-wne/cpe462/topic-04c.pdf)
- d) Generics [PDF](/img/20250727-wne/cpe462/topic-04d.pdf)

### Topic 5: Concurrent Code
- a) WHEN Statements [PDF](/img/20250727-wne/cpe462/topic-05a.pdf)
- b) GENERATE Statements [PDF](/img/20250727-wne/cpe462/topic-05b.pdf)
- c) BLOCK Statements [PDF](/img/20250727-wne/cpe462/topic-05c.pdf)

### Topic 6: Sequential Code
- a) Process, If, and Variables [PDF](/img/20250727-wne/cpe462/topic-06a.pdf)
- b) Sequential Code on Spartan-3 Boards [PDF](/img/20250727-wne/cpe462/topic-06b.pdf)
- c) Wait, Case, and Loop [PDF](/img/20250727-wne/cpe462/topic-06c.pdf)
- d) Final Topics in Sequential Code [PDF](/img/20250727-wne/cpe462/topic-06d.pdf)
- e) Variables vs Signals [PDF](/img/20250727-wne/cpe462/topic-06e.pdf)

### Topic 7: Finite State Machines (FSM)
- a) Introduction to Finite State Machines [PDF](/img/20250727-wne/cpe462/topic-07a.pdf)
- b) Practical VHDL Implementations [PDF](/img/20250727-wne/cpe462/topic-07b.pdf)
- c) FSM on Spartan-3E [PDF](/img/20250727-wne/cpe462/topic-07c.pdf)
- d) FSM with Delays [PDF](/img/20250727-wne/cpe462/topic-07d.pdf)

### Topic 8: System Design
- a) Components [PDF](/img/20250727-wne/cpe462/topic-08a.pdf)
- b) Packages & Generic Components [PDF](/img/20250727-wne/cpe462/topic-08b.pdf)
- c) Functions [PDF](/img/20250727-wne/cpe462/topic-08c.pdf)
- d) Procedures [PDF](/img/20250727-wne/cpe462/topic-08d.pdf)

### Topic 9: Circuit Designs
- a) Introduction to Random Numbers in Hardware [PDF](/img/20250727-wne/cpe462/topic-09a.pdf)

### Homework
- [HW #1](/img/20250727-wne/cpe462/hw/hw01.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw01-sol.pdf)
- [HW #2](/img/20250727-wne/cpe462/hw/hw02.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw02-sol.pdf)
- [HW #3](/img/20250727-wne/cpe462/hw/hw03.pdf) [exercise #3 testbench](/img/20250727-wne/cpe462/hw/hw03_ex3-testbench.vhd) [solutions](/img/20250727-wne/cpe462/hw/hw03-sol.pdf)
- [HW #4](/img/20250727-wne/cpe462/hw/hw04.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw04-sol.pdf)
- [HW #5](/img/20250727-wne/cpe462/hw/hw05.pdf) [exercise #3 testbench](/img/examples/topic4b-ex4.txt) [exercise #4 testbench](/img/examples/topic4b-ex5.txt) [solutions](/img/20250727-wne/cpe462/hw/hw05-sol.pdf)
- [HW #6](/img/20250727-wne/cpe462/hw/hw06.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw06-sol.pdf)
- [HW #7](/img/20250727-wne/cpe462/hw/hw07.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw07-sol.pdf)
- [HW #8](/img/20250727-wne/cpe462/hw/hw08.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw08-sol.pdf)
- [HW #9](/img/20250727-wne/cpe462/hw/hw09.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw09-sol.pdf)
- [EXAM #1 & HW #10](/img/20250727-wne/cpe462/hw/exam_01.pdf) [testbench](/img/20250727-wne/cpe462/hw/exam1_testbench_1.txt) [comments](/img/slides/exam_01_comments.pdf) [solutions](/img/20250727-wne/cpe462/hw/exam_01_sol.pdf)
- [HW #11](/img/20250727-wne/cpe462/hw/hw11.pdf) [testbench](/img/20250727-wne/cpe462/hw/hw11-testbench.txt) [waveform](/img/20250727-wne/cpe462/hw/hw11-waveform.png) [solutions](/img/20250727-wne/cpe462/hw/hw11-sol.pdf)
- [HW #12](/img/20250727-wne/cpe462/hw/hw12.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw12-sol.pdf)
- [HW #13](/img/20250727-wne/cpe462/hw/hw13.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw13-sol.pdf)
- [HW #14](/img/20250727-wne/cpe462/hw/hw14.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw14-sol.pdf)
- [HW #15](/img/20250727-wne/cpe462/hw/hw15.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw15-sol.pdf)
- [HW #16](/img/20250727-wne/cpe462/hw/hw16.pdf) [partial solution](/img/20250727-wne/cpe462/hw/exam_02_sol.txt) [solutions](/img/20250727-wne/cpe462/hw/hw16-sol.pdf)
- [HW #17](/img/20250727-wne/cpe462/hw/hw17.pdf) [partial solution](/img/20250727-wne/cpe462/hw/exam_01_sol.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw17-sol.pdf)
- [HW #18](/img/20250727-wne/cpe462/hw/hw18.pdf) [solutions](/img/20250727-wne/cpe462/hw/hw18-sol.pdf)

### Exams
- [Exam #1](/img/20250727-wne/cpe462/hw/exam_01.pdf) [solutions](/img/20250727-wne/cpe462/hw/exam_01_sol.pdf)
- [Exam #2](/img/20250727-wne/cpe462/hw/exam_02.pdf) [solutions](/img/20250727-wne/cpe462/hw/exam_02_sol.txt)
- [Final Exam](/img/20250727-wne/cpe462/hw/exam_03.pdf) [turn-in times](/img/20250727-wne/cpe462/hw/turn_in.png) [solutions](/img/20250727-wne/cpe462/hw/exam_03_sol.pdf)

---

## CPE 355 – Real Time Embedded Kernels – Spring ’12

Syllabus [PDF](/img/20250727-wne/cpe355/spring_2012_cpe355_syllabus.pdf)


### Topic 1: Background
- a) Digital logic and information representation review [PDF](/img/20250727-wne/cpe355/cpe355-01-a.pdf)  
- b) Hardware fundamentals for the software engineer [PDF](/img/20250727-wne/cpe355/cpe355-01-b.pdf)  
- c) Advanced hardware fundamentals [PDF](/img/20250727-wne/cpe355/cpe355-01-c.pdf)  
- d) Introduction to interrupts [PDF](/img/20250727-wne/cpe355/cpe355-01-d.pdf)  

### Topic 2: Programming foundations (Arduino & C)
- a) Arduino and basic C review [PDF](/img/20250727-wne/cpe355/cpe355-02-a.pdf)  
- b) Interrupts in Arduino [PDF](/img/20250727-wne/cpe355/cpe355-02-b.pdf)  
- c) Pointers, arrays and function pointers [PDF](/img/20250727-wne/cpe355/cpe355-02-c.pdf)  
- d) Structs, linked lists, stacks and queues [PDF](/img/20250727-wne/cpe355/cpe355-02-d.pdf) [source](/img/20250727-wne/cpe355/linked_list.c)  
- e) Bitwise operators, macros and enumeration [PDF](/img/20250727-wne/cpe355/cpe355-02-e.pdf)  
- f) Very basic introduction to Arduino timers [PDF](/img/20250727-wne/cpe355/cpe355-02-f.pdf)  
- g) Literal constants, extern, typedef, callback functions and macros [PDF](/img/20250727-wne/cpe355/cpe355-02-g.pdf)  

### Topic 3: Foundations of real-time systems
- a) Survey of software architectures: round-robin [PDF](/img/20250727-wne/cpe355/cpe355-03-a.pdf)  
- b) Survey of software architectures: queues and RTOS [PDF](/img/20250727-wne/cpe355/cpe355-03-b.pdf)  

### Topic 4: Features of real-time operating systems
- a) Tasks, task data and reentrant functions [PDF](/img/20250727-wne/cpe355/cpe355-04-a.pdf)  
- b) Semaphores and shared data [PDF](/img/20250727-wne/cpe355/cpe355-04-b.pdf)  
- c) Message queues, mailboxes and pipes [PDF](/img/20250727-wne/cpe355/cpe355-04-c.pdf)  
- d) Timer functions [PDF](/img/20250727-wne/cpe355/cpe355-04-d.pdf)  
- e) Events and memory management [PDF](/img/20250727-wne/cpe355/cpe355-04-e.pdf)  
- f) Basic design using a real-time operating system [PDF](/img/20250727-wne/cpe355/cpe355-04-f.pdf)  

### Homework
- [HW01](/img/20250727-wne/cpe355/hw01.pdf) [solutions](/img/20250727-wne/cpe355/hw01_sol.pdf)
- [HW02](/img/20250727-wne/cpe355/hw02.pdf) [solutions by Alexandra Carter](/img/20250727-wne/cpe355/hw02_sol.pdf)
- [HW03](/img/20250727-wne/cpe355/hw03.pdf) [solutions](/img/20250727-wne/cpe355/hw03_sol.pdf)
- [HW04](/img/20250727-wne/cpe355/hw04.pdf) [solutions](/img/20250727-wne/cpe355/hw04_sol.pdf)
- [HW05](/img/20250727-wne/cpe355/hw05.pdf) [solutions by William Ferguson](/img/20250727-wne/cpe355/hw05_sol.zip)
- [HW06](/img/20250727-wne/cpe355/hw06.pdf) [solutions by Scott Nette](/img/20250727-wne/cpe355/hw06_sol.ino)
- [HW07](/img/20250727-wne/cpe355/hw07.pdf) [solutions by Kyle Hunter](/img/20250727-wne/cpe355/hw07_sol.zip) [errata](/img/20250727-wne/cpe355/hw07_errata.txt)
- [HW08](/img/20250727-wne/cpe355/hw08.pdf) [solutions by William Ferguson](/img/20250727-wne/cpe355/hw08_sol.zip)
- [HW09](/img/20250727-wne/cpe355/hw09.pdf) [q1 solution by Jason T. John](/img/20250727-wne/cpe355/hw09_sol_q1.ino) [q2 solution](/img/20250727-wne/cpe355/hw09_sol_q2.txt) 
- [HW10](/img/20250727-wne/cpe355/hw10.pdf) [solutions](/img/20250727-wne/cpe355/hw10_sol.pdf) 
- [HW11](/img/20250727-wne/cpe355/hw11.pdf) [solutions](/img/20250727-wne/cpe355/hw11_sol.txt)  
- [HW12](/img/20250727-wne/cpe355/hw12.pdf) [solutions](/img/20250727-wne/cpe355/hw12_sol.pdf) 
- [HW13](/img/20250727-wne/cpe355/hw13.pdf) [solutions](/img/20250727-wne/cpe355/hw13_sol.pdf)
- [HW14 & 15](/img/20250727-wne/cpe355/hw14-15.pdf) [solutions](/img/20250727-wne/cpe355/hw14-15_sol.pdf) 
- [HW16](/img/20250727-wne/cpe355/hw16.pdf) [solutions](/img/20250727-wne/cpe355/hw16_sol.pdf) 
- [HW17](/img/20250727-wne/cpe355/hw17.pdf) [solutions](/img/20250727-wne/cpe355/hw17_sol.pdf)

### Exams
- [Exam #01](/img/20250727-wne/cpe355/midterm_01.pdf) [solutions](/img/20250727-wne/cpe355/midterm_01_sol.pdf) 
- [Exam #02](/img/20250727-wne/cpe355/midterm_02.pdf) [solutions](/img/20250727-wne/cpe355/midterm_02_solutions.pdf)  

## Electronics Summer Camp (Ages 8–12)
- Hackerspace [PDF](/img/20250727-wne/summer_camp_2012/hackerspace.pdf)
- Day 1 [PDF](/img/20250727-wne/summer_camp_2012day_01.pdf)
- Day 2 [PDF](/img/20250727-wne/summer_camp_2012/day_02.pdf)
- Day 3 [PDF](/img/20250727-wne/summer_camp_2012/day_03.pdf)
- Day 4 [PDF](/img/20250727-wne/summer_camp_2012/day_04.pdf)

