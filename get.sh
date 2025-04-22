#!/bin/bash

# Check if argument is passed
if [ -z "$1" ]; then
  echo "Usage: $0 [ls|cp|lsl]"
  exit 1
fi

# Validate and construct filename
case "$1" in
  ls|cp|lsl)
    file="$1.c"
    ;;
  *)
    echo "Error: Invalid argument. Use 'ls', 'cp', or 'lsl'."
    exit 1
    ;;
esac

# GitHub raw URL (replace this with your actual URL)
base_url="https://raw.githubusercontent.com/cvr-noob/os/main"

# Download and overwrite local file
curl -s "$base_url/$file" -o $file

# Check if curl succeeded
if [ $? -eq 0 ]; then
  echo $file
else
  echo "Failed to download $file"
  exit 1
fi
