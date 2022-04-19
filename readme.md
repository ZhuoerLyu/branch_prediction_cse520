# Branch Prediction
This project is implementing and simulating different branch prediction algorithms and comparing their performance.  

pin-tool setup:
1. wget https://software.intel.com/sites/landingpage/pintool/downloads/pin-3.22-98547-g7a303a835-gcc-linux.tar.gz
2. tar -zxvf pin-3.22-98547-g7a303a835-gcc-linux.tar.gz
3. mv collect_traces to pin-3.22-98547-g7a303a835-gcc-linux/source/tools
4. make all TARGET=intel64
5. cd pin-3.22-98547-g7a303a835-gcc-linux/source/tools/collect_traces
6. ./../../pin -t obj-intel64/branchpred.so -- sample_C/sample
	brancpred.so : binary generated from our branchpred.cpp 
	sample: program we to get traces for
traces generated on:
Ubuntu 20.04.1 LTS


we refernced these links to collect traces and modify branchpred.cpp script
https://www.intel.com/content/www/us/en/developer/articles/tool/pin-a-dynamic-binary-instrumentation-tool.html
https://malithjayaweera.com/2018/10/branch-count-using-intel-pin-tool/
https://malithjayaweera.com/2020/06/branch-listing-using-intel-pin-tool/   
/pin-3.22-98547-g7a303a835-gcc-linux/source/tools/ToolUnitTests/branch_target_addr.cpp


to run predictors:
./snt traces.txt
