//
// Parser.cpp
//
// Parser class implementation
// Created by Gigabyte Giant on 12/09/2015
//

#import "Parser.hpp"

Parser::Parser()
{
}

void Parser::parse(std::vector<Token> tokenList)
{
    for (size_t tokInd = 0; tokInd < tokenList.size(); tokInd++)
    {
        Token thisTok = tokenList.at(tokInd);

        printf("[%s]\t%s\n", thisTok.getType().c_str(), thisTok.getVal().c_str());

        // TODO (Gigabyte Giant): Figure out a good way to determine what
        //  a statement is.
        // Example:
        //  `let a = 1` should be marked at a variable declaration
    }
}