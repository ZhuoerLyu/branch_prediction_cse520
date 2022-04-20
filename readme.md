# Project Description

In this project we evaluate static and dynamic branch prediction methods. The main goal of this project is to understand how different branch prediction methods work, and evaluate these methodes performance.
To perform this analysis we chose four different branch prediction methods:

1-Static always Taken
2-Static always Not-Taken
3-Bit Dynamic 
4-Bits Dynamic


We implement these four methods seperately, evaluate theier performance, and compare their performance. 

# Experiment Desing 

To perform a comprehensive evaluation on static and dynamic branch prediction methods we designe an experiment. Our experiment has three main phases:

 Phase 1: Trace generator implementation
 Phase 2: Branch Prediction metods implementation
 Phase 3: Performance evlautation and comparison 

Figure 1 shows the design of our experiment. 

# Evaluation metrics


# Branch Prediction
This project is implementing and simulating different branch prediction algorithms and comparing their performance.  

## Contribution
1. Setting up pin-tool to generate our own execution traces to evaluate different branch prediciton algorithms' performance.

2. Implementing static-taken, static-nottaken, dynamic-1bit, and dynamic-2bit branch prediction algorithms.

3. Evaluating performance by calcualting the accuracy.


## Instruction

>### Pin-tool set up
>1. `wget https://software.intel.com/sites/landingpage/pintool/downloads/pin-3.22-98547-g7a303a835-gcc-linux.tar.gz`
>2. `tar -zxvf pin-3.22-98547-g7a303a835-gcc-linux.tar.gz`
>3. `mv collect_traces to pin-3.22-98547-g7a303a835-gcc-linux/source/tools`
>4. `make all TARGET=intel64`
>5. `cd pin-3.22-98547-g7a303a835-gcc-linux/source/tools/collect_traces`
>6. `./../../pin -t obj-intel64/branchpred.so -- sample_C/sample`
>	`brancpred.so : binary generated from our branchpred.cpp 
>	sample: program we to get traces for
>traces generated on:
>Ubuntu 20.04.1 LTS`


>### Run predictors:
>`./snt traces.txt` 
>
>`./st traces.txt`
>
>`./dynamic_1bit traces.txt`
>
>`./dynamic_2bit traces.txt`

>### Notes
>we refernced these links to collect traces and modify branchpred.cpp script
>https://www.intel.com/content/www/us/en/developer/articles/tool/pin-a-dynamic-binary-instrumentation-tool.html
>https://malithjayaweera.com/2018/10/branch-count-using-intel-pin-tool/
>
>https://malithjayaweera.com/2020/06/branch-listing-using-intel-pin-tool/   
>
>/pin-3.22-98547-g7a303a835-gcc-linux/source/tools/ToolUnitTests/branch_target_addr.cpp
