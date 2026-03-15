#!/bin/bash

# Check for the correct number of arguments
if [ $# -lt 2 ]; then
    echo "Error: Two arguments are required: <file path> <string>"
    exit 1
fi

writefile="$1"
writestr="$2"

# Extract the directory from the file path
writedir=$(dirname "$writefile")

# Create the directory if it doesn't exist
mkdir -p "$writedir"

# Write the string to the file (overwrites if it exists)
echo "$writestr" > "$writefile"

# Check if the file was successfully created
if [ $? -ne 0 ]; then
    echo "Error: Could not create file '$writefile'."
    exit 1
fi

exit 0
