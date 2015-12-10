//
// Lexer.hpp
//
// Lexer class interface
// Created by Gigabyte Giant on 12/09/2015
//
// TODO (Gigabyte Giant): Completely rewrite Lexer class interface.
//

#ifndef __LEXER_H__
#define __LEXER_H__

#include <iostream>
#include <fstream>
#include <vector>
#include "tokenRules.h"
#include "Token.hpp"

enum CharacterType
{
    _ctUnknown,
    _ctNumber,
    _ctIdentifier,
    _ctWhitespace,
    _ctIgnored
};

class Lexer
{
    public:
        Lexer();
        std::vector<Token> tokenizeFile(const char *filePath);

    private:
        bool is(CharacterType type, char c);
        Token getTokenFromChar(char c);
};

#endif