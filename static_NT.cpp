#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {

	if(argc != 2){
		cerr << "Please give me a trace file!\n" << endl;  
		return 1;
	}

	std::ifstream trace_file(argv[1]);
	
	// do we need to convert addr in hex??
	int branch_taken = 0;
	long long target_address;
	int always_not_taken = 0;
	int instruction_count = 0;
	float accuracy;

	while(trace_file >>  target_address >> branch_taken) {
		cerr << "target addr: " << target_address <<  "branch taken?: " << branch_taken << endl;
		instruction_count += 1;
		cerr << instruction_count << "icccc" << endl;
		if(branch_taken == 0){
			always_not_taken += 1;
			
		}
	}
	cerr << "bt " << branch_taken << "\tic " << instruction_count << endl;
	accuracy = ((float)always_not_taken * 100 / instruction_count);
	cerr << accuracy << endl;



}
