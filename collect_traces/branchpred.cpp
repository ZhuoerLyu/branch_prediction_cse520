#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <map>
#include "pin.H"
#include "instlib.H"
using std::iostream;
using std::ostringstream;
using std::cerr;
using std::ofstream;
using std::ios;
using std::string;
using std::endl;

ofstream OutFile;

// To collect branch taken and not taken
class COUNTER
{
  public:
    
    UINT64 _taken;

    COUNTER() :  _taken(0)  {}

};

std::map<ADDRINT, COUNTER> counterMap;

// This function is executed at each branch
static VOID for_each_branch(ADDRINT ip, ADDRINT target, BOOL taken)
{

    // add branch taken and not taken
    if(taken){
    	counterMap[ip]._taken = 1 ; 
    }
    else{
	    counterMap[ip]._taken = 0 ;

    }
 
}

// Pin calls this function every time a new instruction is encountered
VOID Instruction(INS ins, VOID *v)
{	// #################

	// 	INS_HasFallThrough: The fall-through address represents the instruction just after the branch
	//	IPOINT_BEFORE : execute before instruction is executed
	//	AFUNPTR : means it is a function pointer
	// 	Insert a call to branch before every instruction - 3 arguments (instr ptr, branch target and branch taken)

    if (INS_IsBranch(ins) && INS_HasFallThrough(ins)) {
        INS_InsertCall(ins, IPOINT_BEFORE, 
                       (AFUNPTR)for_each_branch,
                       IARG_INST_PTR, IARG_BRANCH_TARGET_ADDR, 
                       IARG_BRANCH_TAKEN, IARG_END);
    }
}

// specify file name to collect traces
KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE, "pintool",
    "o", "traces.txt", "specify output file name");

// Function Fini is executed when the application ends
VOID Fini(INT32 code, VOID *v)
{
    // Write traces to a file
    OutFile.setf(ios::showbase);
   
    for (std::map<ADDRINT, COUNTER>::iterator it=counterMap.begin();
         it!=counterMap.end(); ++it) {

	OutFile << it->first << "\t" << it->second._taken << endl; 
    }
    OutFile.close();
   
}

// To help th euser with correct usage
INT32 Usage()
{
    cerr << "This tool collects branch taken and not taken and branch address" << endl;
    cerr << endl << KNOB_BASE::StringKnobSummary() << endl;
    return -1;
}

int main(int argc, char * argv[])
{
    // Initialize pin
    if (PIN_Init(argc, argv)) return Usage();

    OutFile.open(KnobOutputFile.Value().c_str());

    if (!KnobOutputFile.Value().empty())
    {
        cerr << "Traces in file " << KnobOutputFile.Value() << " ... " << endl;
    }
  
    // Register Instruction to be called to instrument instructions
    INS_AddInstrumentFunction(Instruction, 0);

    // Call Register Fini when the application exits
    PIN_AddFiniFunction(Fini, 0);
    
    // Start the program
    PIN_StartProgram();

    return 0;
}
