//
// Parser.hpp
//
// Parser class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __PARSER_H__
#define __PARSER_H__

#import <iostream>
#import <vector>
#import "../Lexer/Token.hpp"

class Parser
{
    public:
        Parser();
        void parse(std::vector<Token> tokenList);

    private:
        std::vector< std::vector<Token> > separateLines(std::vector<Token> tokenList);
};

#endif