
# Project Description

In this project, we evaluate static and dynamic branch prediction methods. The main goal of this project is to understand how different branch prediction methods work and assess these methods' performance.
To perform this analysis, we chose four different branch prediction methods:

1: Static always Taken
2: Static always Not-Taken
3: 1-Bit Dynamic 
4: 2-Bits Dynamic


We implement these four methods separately, evaluate their performance, and compare them. 

# Experiment Design

We designed an experiment to evaluate static and dynamic branch prediction methods comprehensively. Our experiment has three main phases:

 Phase 1: Trace generator implementation
 Phase 2: Branch Prediction methods implementation
 Phase 3: Performance evaluation and comparison 

Figure 1 shows the design of our experiment. 
![Cse520-diagram](https://user-images.githubusercontent.com/50604576/164134283-1be0d094-fb9e-49d0-b291-cba5dd123104.png) 

In Phase 1, we create different types of Loop-Condition codes as our test cases in C languages. We made four test cases:
1-     One For loop with one If
2-     Two For loops with one If
3-     Two For loops with two Ifs
4-     One For loop with one if with two numbers of iterations (100 & 1000)
We wrote Three different loop branches and modified the iteration number for one of these codes to evaluate the effects of iteration on branch prediction methods performance.  
We utilized Pin-tool in this phase to generate execution traces. We modified this open-source code to create traces of our test cases.
In Phase 2, we implemented four branch prediction methods in C++ on Ubuntu 20.04.1 LTS. 
In Phase 3, we run the implemented branch prediction methods on the generated traces and calculate the evaluation metrics.

# Evaluation metrics

To evaluate these four branch prediction methods, we consider four metrics:
1) Accuracy
 2) Misprediction 
3) Misprediction as TAKEN 
4) Misprediction as Not-TAKEN


We also run another experiment to evaluate the effects of numbers of iterations on branch prediction performance.












