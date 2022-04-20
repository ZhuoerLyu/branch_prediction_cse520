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

	int wrong_predcitoin_taken = 0;
	int wrong_predcitoin_not_taken = 0;

	int correct_predction_taken = 0;
	int correct_predction_not_taken = 0;
    // Configure table size
    int tsize = 1;
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
            if(table_value == 2 || table_value == 3) {correct += 1;correct_predction_taken += 1;}
            if (table_value != 3) {branch_prediction_table[index] = 1; wrong_predcitoin_not_taken += 1;}
		}

        // If branch is not taken
        else if(branch_taken == 0)
        {
            if (table_value == 0 || table_value == 1) {correct += 1; correct_predction_not_taken += 1;}
            if (table_value != 3) {branch_prediction_table[index]++; wrong_predcitoin_taken += 1;}
        }
        // increase instruction count
		instruction_count += 1;
	}
	cerr << "bt " << branch_taken << "\tic " << instruction_count << endl;

    // Generate metrics
	cerr << "total number of prediction " << instruction_count << "\n";
	cerr << "wrong prediction as taken " << wrong_predcitoin_taken << "\n";
	cerr << "wrong prediction as not taken " << wrong_predcitoin_not_taken << "\n";
	cerr << "correct predction as taken " << correct_predction_taken << "\n";
	cerr << "correct prediction as not taken " << correct_predction_not_taken << "\n";
	accuracy = ((float)correct * 100 / instruction_count);
	cerr << "accuracy " << accuracy << endl;
	accuracy = ((float)correct * 100 / instruction_count);
	cerr << accuracy << endl;



}