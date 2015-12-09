//
// Lexer.hpp
//
// Lexer class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __LEXER_H__
#define __LEXER_H__

#include <iostream>
#include <vector>
#include <string>
#include "tokenRules.h"
#include "Token.hpp"

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
        // Used to keep track of the last token that we "saw"
        //
        Token lastToken = Token("Ignored", "N/A");

        //
        // Used to keep track of all of the characters in the current "token"
        // 
        std::vector<Token> tmpTokStr;

        //
        // Used to keep track of all of the final tokens that we extracted
        //  from the input.
        //
        std::vector<Token> tokenList;

        //
        // Lexer::is(tokenType type, char c)
        //
        // Used to determine if a character is of the desired type.
        //
        bool is(tokenType type, char c);

        //
        // Lexer::getToken(char c)
        //
        // Fetches a token that matches the passed in character.
        //
        Token getToken(char c);

        //
        // Lexer::putStreamInList()
        //
        // Puts the contents of the temp token stream into the final
        //  token list
        //
        void putStreamInList();
};

#endif