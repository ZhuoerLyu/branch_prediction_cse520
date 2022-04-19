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
	int correct = 0;
	int instruction_count = 0;
	float accuracy;

    // Configure table size as 2 bits
    int tsize = 2;
    int branch_prediction_table[tsize];

    // Initilize branch prediciton table
    for(int i = 0; i < tsize; i++) branch_prediction_table[i] = 0;

	while(trace_file >>  target_address >> branch_taken) {
		cerr << "target addr: " << target_address <<  "branch taken?: " << branch_taken << endl;
        
        // Get index number and table value
        int index = instruction_count%tsize;
        int table_value = branch_prediction_table[index];
        

        // tranfer binary into decimal form of 
        // If branch is taken
		if(branch_taken == 1)
        {
            if(table_value == 2 || table_value == 3) correct += 1;
            if (table_value != 3) branch_prediction_table[index] += 1;
		}

        // If branch is not taken
        else if(branch_taken == 0)
        {
            if (table_value == 0 || table_value == 1) correct += 1;
            if (table_value != 3) branch_prediction_table[index]++;
        }
        // increase instruction count
		instruction_count += 1;
	}
	cerr << "bt " << branch_taken << "\tic " << instruction_count << endl;
	accuracy = ((float)correct * 100 / instruction_count);
	cerr << accuracy << endl;



}


