//
// Lexer.hpp
//
// Lexer class interface
// Created by Gigabyte Giant on 12/09/2015
//

//
// TODO (Gigabyte Giant): Figure out a good way to store
//  a list of reserved keywords.
//

//
// TODO (Gigabyte Giant): Figure out a good way to determine
//  if a string of tokens makes up a reserved keyword.
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
    _ctTerminator,
    _ctIgnored,
    _ctLeftParen,
    _ctRightParen,
    _ctOperator
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
