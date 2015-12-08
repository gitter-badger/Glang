#!/bin/bash
# Build Glang compiler using g++

projectRoot=/Users/Brynden/src/glang

binaryDir=$projectRoot/bin
entryPoint=$projectRoot/src/entry.cpp

g++ -o $binaryDir/glang $entryPoint

chmod 700 $binaryDir/glang
