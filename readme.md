
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

<img src="https://user-images.githubusercontent.com/50604576/164134283-1be0d094-fb9e-49d0-b291-cba5dd123104.png" width="40%" height="40%">


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
2) Correct Prediction
3) Correct Prediction as TAKEN 
4) Correct Prediction as Not-TAKEN
5) Misprediction 
6) Misprediction as TAKEN 
7) Misprediction as Not-TAKEN


We also run another experiment to evaluate the effects of numbers of iterations on branch prediction performance.



# Results

During our experiment we observed that:
 1: Static Branch Prediction Always Not-Taken is always better than Static Branch Prediction Always Taken 
 2: 1-Bit Branch Prediction Always is better than Static Branch Prediction Always Taken
 3: Surprisingly Static Branch Prediction Always Not-Taken is always better than 1-Bit Branch Prediction
 4: Surprisingly 1-Bit Branch Prediction Always is better than 2-Bit Branch Prediction 
 5: Static Branch Prediction Always Not-Taken is always better than other three branch prediction methods


Here are the results of our experiment on four test cases:


Test Case 1 : 1 For, 1 If: 

![case-study1](https://user-images.githubusercontent.com/50604576/164154623-6c85a091-d838-4944-88a2-8aa322aecdc2.png)

Test Case 2 : 2 For, 1 If:

![case-study2](https://user-images.githubusercontent.com/50604576/164154585-db2f51d2-6c4c-47cc-b49e-2ba8513c0220.png)

Test Case 3 : 2 For, 2 If

![case-study3](https://user-images.githubusercontent.com/50604576/164154521-0e6b90f0-a5ac-446e-af90-d73b9906460e.png)

Test Case 4 : 1 For, 1 If with different Iteration number

![case-study4](https://user-images.githubusercontent.com/50604576/164154660-5110981b-8560-49b9-9c1e-550cfe20eb62.png)



## Instruction 

### Run predictors:

You can use any of the 4 traces present in the trace directory
`./snt traces.txt`
`./st traces.txt`
`./dynamic_1bit traces.txt`
`./dynamic_2bit traces.txt

### Pin-tool set up

1. `wget https://software.intel.com/sites/landingpage/pintool/downloads/pin-3.22-98547-g7a303a835-gcc-linux.tar.gz`
2. `tar -zxvf pin-3.22-98547-g7a303a835-gcc-linux.tar.gz`
3. `mv collect_traces to pin-3.22-98547-g7a303a835-gcc-linux/source/tools`
4. `make all TARGET=intel64`
5. `cd pin-3.22-98547-g7a303a835-gcc-linux/source/tools/collect_traces`
6. `./../../pin -t obj-intel64/branchpred.so -- sample_C/sample`
	`brancpred.so : binary generated from our branchpred.cpp
	sample: program we to get traces for
traces generated on:
Ubuntu 20.04.1 LTS`11:34











