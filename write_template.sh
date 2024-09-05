#!/bin/bash

# Check if the filename argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

# Store the filename from the argument
filename="$1"

# Write the C++ template to the specified file
cat <<EOL > "$filename"
#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
EOL

echo "Template written to $filename"