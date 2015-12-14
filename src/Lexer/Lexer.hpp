//
// Lexer.hpp
//
// Lexer class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __LEXER_H__
#define __LEXER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tokenRules.h"
#include "Token.hpp"
#include "keywords.h"

struct flagStruct
{
    bool inComment;
    bool inString;
    bool seenEscape;
    bool doIgnores;
};

typedef struct flagStruct lexFlags;

class Lexer
{
    public:
        Lexer();
        std::vector<Token> tokenizeFile(const char *filePath);

    private:
        Token getTokenFromChar(char c, lexFlags flags);
};

#endif
