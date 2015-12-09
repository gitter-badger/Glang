#!/bin/bash
# Build Glang transpiler using clang++

# We'll go ahead and keep an 'absolute path' to the project directory.
# While using 'relative paths' is convenient, it can be dangerous.
projectRoot=/Users/Brynden/src/glang

srcDir=$projectRoot/src
binDir=$projectRoot/bin

classes=(
    "Lexer"
    "Parser"
)

incStrs=""

for class in ${classes[@]}
do
    # The way this is written, we're basically forced to make sure
    #  that all filenames are unique, no matter what the directory.
    #  This should probably be changed in the future.
    cppFile="$srcDir/**/$class.cpp"

    # All *.o files are placed in the root of the './bin/' directory.
    outFile="$binDir/$class.o"

    # Passing the '-c' option makes 'clang' only run the
    #  preprocessor, compiler, and assembler steps.
    # This *does not* give us an 'executable binary'. We
    #  link our entry file with these output files, later on.
    clang++ -c $cppFile -o $outFile

    incStrs="$incStrs $outFile"
done

# Currently, we're assuming that the entry point of 'glang'
#  is located in a 'entry.cpp' file. If it doesn't, we'll
#  need to change this line.
entryPoint=$srcDir/entry.cpp

clang++ -o $binDir/glang $entryPoint $incStrs