//
// entry.cpp
//
// Entry point for the glang transpiler
// Created by Gigabyte Giant on 12/08/2015
//

#import <iostream>
#import "Lexer/Lexer.hpp"
#import "Parser/Parser.hpp"
#import "misc.hpp"

int main(int argc, const char **argv)
{
    Lexer myLex = Lexer();
    Parser myParser = Parser();

    // NOTE: We start 'argInd' at 1 because we don't want
    //  to do anything with the first argument (the program).
    for (int argInd = 1; argInd < argc; argInd++)
    {
        printf("Current input file: %s\n", *(argv + argInd));
    
        myParser.parse(myLex.tokenizeFile(*(argv + argInd)));
    }

    return 0;
}
