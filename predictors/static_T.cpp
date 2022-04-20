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

	// read traces
	std::ifstream trace_file(argv[1]);
	
	// intialize counter 
	int branch_taken = 0;
	long long target_address;
	int always_taken = 0;
	int instruction_count = 0;
	float accuracy;

	// iterate over trace file and read target address and branch (0 or 1) in target_address and branch_taken respectively 
	while(trace_file >>  target_address >> branch_taken) {
		instruction_count += 1;
		if(branch_taken == 1){
			always_taken += 1;
			
		}
	}
	
	// accuacy
	accuracy = ((float)always_taken * 100 / instruction_count);
	cerr << accuracy << endl;
	cerr << "total number of prediction " << instruction_count << "\n";
	cerr << "correct prediction as taken " << always_taken << "\n";
	accuracy = ((float)always_taken * 100 / instruction_count);
	cerr << "accuracy " << accuracy << endl;


}
