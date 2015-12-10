//
// entry.cpp
//
// Entry point for the glang transpiler
// Created by Gigabyte Giant on 12/08/2015
//

#import <iostream>
#import "misc.hpp"

int main(int argc, const char **argv)
{
    // NOTE: We start 'argInd' at 1 because we don't want
    //  to do anything with the first argument (the program).
    for (int argInd = 1; argInd < argc; argInd++)
    {
        printf("Current input file: %s\n", *(argv + argInd));

        // TODO (Gigabyte Giant): ...
    }

    return 0;
}