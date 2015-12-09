#!/bin/bash
# Build Glang compiler using g++

projectRoot=/Users/Brynden/src/glang

srcDir=$projectRoot/src
binDir=$projectRoot/bin

classes=(
    "Lexer"
)

incStrs=""

for class in ${classes[@]}
do
    cppFile="$srcDir/**/$class.cpp"
    outFile="$binDir/$class.o"

    clang++ -c $cppFile -o $outFile

    incStrs="$incStrs $outFile"
done

entryPoint=$srcDir/entry.cpp

clang++ -o $binDir/glang $entryPoint $incStrs