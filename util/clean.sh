#!/bin/bash
# Clean up the 'bin' directory for the project.

projectRoot=/Users/Brynden/src/glang

binDir=$projectRoot/bin

# We'll go ahead and pass the '-f' option to
#  the 'rm' command so it doesn't yell at us
#  if a file doesn't exist.
rm -rf $binDir/**/*.o $binDir/*.o $binDir/glang