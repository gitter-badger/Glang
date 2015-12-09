#!/bin/bash
# Clean up the 'bin' directory for the project.

projectRoot=/Users/Brynden/src/glang

binDir=$projectRoot/bin

remove=$binDir/**/*.o

# We'll go ahead and pass the '-f' option to
#  the 'rm' command so it doesn't yell at us
#  if a file doesn't exist.
rm -rf $remove
rm -f $binDir/glang