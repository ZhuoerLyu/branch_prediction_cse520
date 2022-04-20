#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {

	// Program reads traces file, containing the address and corresponding branch taken or not taken
	if(argc != 2){
		cerr << "Please give me a trace file!\n" << endl;  
		return 1;
	}

	// read trace file
	std::ifstream trace_file(argv[1]);
	
	
	// initialize counters 
	int branch_taken = 0;
	long long target_address;
	int always_not_taken = 0;
	int instruction_count = 0;
	float accuracy;

	// iterate over trace file and read target address and branch (0 or 1) in target_address and branch_taken respectively 
	while(trace_file >>  target_address >> branch_taken) {
		cerr << "target addr: " << target_address <<  "branch taken?: " << branch_taken << endl;
		instruction_count += 1;
		if(branch_taken == 0){
			always_not_taken += 1;
			
		}
	}

	//calculate accuracy
    // Generate metrics
	cerr << "total number of prediction " << instruction_count << "\n";
	cerr << "correct prediction as not taken " << always_not_taken << "\n";
	accuracy = ((float)always_not_taken * 100 / instruction_count);
	cerr << "accuracy " << accuracy << endl;

	//calculate mispredictions
	
	// TODO



}
