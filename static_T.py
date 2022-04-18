def static_T(trace_file_path):

    """
    Implementing static branch prediction with always taken.

    trace_file_path: the file location of trace file.
    """

    # Initilize counter
    always_taken = 0
    instruction_num = 0

    with open(trace_file_path, "r") as f:
        for line in f:
            addr, prediction = line.split("    ")

            if (prediction == "1"):
                always_taken += 1
        
            instruction_num += 1
    
    accuracy = always_taken/ instruction_num

    return accuracy


def static_NT(trace_file_path):

    """
    Implementing static branch prediction with always not taken.

    trace_file_path: the file location of trace file.
    """

    # Initilize counter
    always_nottaken = 0
    instruction_num = 0

    with open(trace_file_path, "r") as f:
        for line in f:
            addr, prediction = line.split("    ")

            if (prediction == "0"):
                always_nottaken += 1
        
            instruction_num += 1
    
    accuracy = always_nottaken/ instruction_num

def dynamic_2bit(trace_file_path)

    # Initilize counter
    always_nottaken = 0
    instruction_num = 0

    with open(trace_file_path, "r") as f:
        for line in f:
            addr, prediction = line.split("    ")

            if (prediction == "0"):
                always_nottaken += 1
        
            instruction_num += 1
    
    accuracy = always_nottaken/ instruction_num