#!/bin/bash
# Launch glang binary

projectRoot=/Users/Brynden/src/glang

binDir=$projectRoot/bin

testFiles=$projectRoot/test/*.txt

$binDir/glang $testFiles
