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
    std::vector< std::vector<Token> > lines = this->separateLines(tokenList);

    for (size_t lnInd = 0; lnInd < lines.size(); lnInd++)
    {
        std::vector<Token> thisLn = lines.at(lnInd);

        // TODO (Gigabyte Giant): Figure out a good way to determine what
        //  a statement is.
        // Example:
        //  `let a = 1` should be marked at a variable declaration

        for (size_t tokInd = 0; tokInd < thisLn.size(); tokInd++)
        {
            Token thisTok = thisLn.at(tokInd);

            printf("[%s]\t%s\n", thisTok.getType().c_str(), thisTok.getVal().c_str());
        }

        printf("===\n");
    }
}

std::vector< std::vector<Token> > Parser::separateLines(std::vector<Token> tokenList)
{
    std::vector< std::vector<Token> > lines;
    std::vector<Token> tmpLine;

    for (size_t i = 0; i < tokenList.size(); i++)
    {
        Token thisTok = tokenList.at(i);

        if (thisTok.getType() == "Terminator")
        {
            lines.push_back(tmpLine);
            tmpLine.clear();
        }
        else
        {
            tmpLine.push_back(thisTok);
        }
    }

    return lines;
}