//
// Lexer.hpp
//
// Lexer class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __LEXER_H__
#define __LEXER_H__

#include <iostream>
#include <string>
#include "tokenRules.h"

enum tokenType
{
    Identifier,
    Number,
    ArithmeticOperator,
    Ignored
};

class Lexer
{
    public:
        //
        // Lexer::Lexer()
        //
        Lexer();

        //
        // Lexer::tokenize(std::string fileData)
        //
        // Used to tokenize any string of data.
        //
        void tokenize(std::string data);

    private:
        //
        // Used to keep track of all of the characters in the current "token"
        // 
        std::string tmpTokStr;

        //
        // Lexer::is(tokenType type, char c)
        //
        // Used to determine if a character is of the desired type.
        //
        bool is(tokenType type, char c);
};

#endif