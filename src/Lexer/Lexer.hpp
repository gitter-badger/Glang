//
// Lexer.hpp
//
// Lexer class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __LEXER_H__
#define __LEXER_H__

#include <iostream>
#include "tokenRules.h"

enum tokenType
{
    Identifier,
    Number
};

class Lexer
{
    public:
        //
        // Lexer::Lexer()
        //
        Lexer();

    private:
        //
        // Lexer::is(tokenType type, char c)
        //
        // Used to determine if a character is of the desired type.
        //
        bool is(tokenType type, char c);
};

#endif