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
        Token currToken = tokenList.at(tokInd);

        // TODO (Gigabyte Giant): Figure out a good way to "parse"
        //  statements.
    }
}
