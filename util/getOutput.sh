#!/bin/bash
# Generate a file that contains the transpiler's output

projectRoot=/Users/Brynden/src/glang

scriptsDir=$projectRoot/util

output=$projectRoot/sampleOutput.txt

$scriptsDir/run.sh > $output