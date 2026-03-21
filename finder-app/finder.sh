#!/bin/sh

# Check for the correct number of arguments
if [ $# -lt 2 ]; then
	echo "Error: Two arguments are required: <directory> <search string>"
	exit 1
fi

filesdir="$1"
searchstr="$2"

# Check if filesdir is a directory
if [ ! -d "$filesdir" ]; then
	echo "Error: '$filesdir' is not a directory."
	exit 1
fi

# Count the number of files (recursively)
filecount=$(find "$filesdir" -type f | wc -l)

# Count the number of matching lines
matchcount=$(grep -r --binary-files=without-match -F "$searchstr" "$filesdir" 2>/dev/null | wc -l)

echo "The number of files are $filecount and the number of matching lines are $matchcount"