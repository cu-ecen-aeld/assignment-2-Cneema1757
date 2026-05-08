#!/bin/sh

# this code takes 2 arguments , first is file path and second is a word and writes the word in the text file.
#it create the file if it not exists
set -e
set -u

if [ $# -lt 2 ];
then
    echo "not enough args"
    exit 1
elif [ $# -eq 2 ]; then
    if [ -f $1 ]; then
        echo "${2}" > $1
    else
        DIR="$(dirname "$1")"
        mkdir -p $DIR 
        echo "${2}" > $1  
    fi      
else 
    echo "TOO many args" 
fi
