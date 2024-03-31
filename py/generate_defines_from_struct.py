import re
import sys
import os.path

def generate_defines_from_struct(filename, output_filename, *ignored_keys):
    with open(filename, 'r') as file:
        data = file.read()

    # Extracting struct members using regex
    matches = re.findall(r"\[([A-Za-z0-9_]+)\]", data)

    # Generating #define directives
    idx = 0
    max_length = max(len(match) for match in matches if match not in ignored_keys)
    with open(output_filename, 'w') as outfile:
        for match in matches:
            if match not in ignored_keys:
                padding = " " * (max_length - len(match) + 2)  # Adding two more spaces
                outfile.write(f"#define {match}{padding} {idx}\n")
                idx += 1

# Check if filename and output filename arguments are provided
if len(sys.argv) < 3:
    print("Usage: generate_defines_from_struct.py <input_filename> <output_filename> [ignored_keys...]")
    sys.exit(1)

# Extract filenames from command line arguments
input_filename = sys.argv[1]

# Determine the output filename based on the provided argument
output_filename = sys.argv[2]
if "." not in output_filename:
    # If the output filename does not contain a ".", interpret it as one of the ignored keys
    ignored_keys = sys.argv[2:]
    output_filename = "output.txt"  # Use default output filename
else:
    ignored_keys = sys.argv[3:] if len(sys.argv) > 3 else []

# Generate #define directives from the struct in the specified file
generate_defines_from_struct(input_filename, output_filename, *ignored_keys)
