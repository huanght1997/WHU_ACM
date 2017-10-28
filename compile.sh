#!/bin/bash
mkdir -p bin
for file in *.cpp
do
    #zy=${file// /\\ }
    echo "Compiling $file..."
    bash -c "g++ -o \"bin/${file%.cpp}\" \"$file\" --std=c++11"
done
