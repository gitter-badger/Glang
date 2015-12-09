#!/bin/bash
# Launch glang binary

projectRoot=/Users/Brynden/src/glang

binDir=$projectRoot/bin

testFiles=$projectRoot/test/*.glang

$binDir/glang $testFiles
