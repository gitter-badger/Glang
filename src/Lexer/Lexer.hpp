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

class Lexer
{
    public:
        Lexer();

    private:
        bool isIdentifier(char c);
};

#endif