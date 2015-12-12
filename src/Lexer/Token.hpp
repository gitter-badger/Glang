//
// Token.hpp
//
// Token class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __TOKEN_H__
#define __TOKEN_H__

#import <iostream>
#import <string>

enum TokenType
{
    Unknown,
    Number,
    String,
    Identifier
};

class Token
{
    public:
        Token(TokenType type, std::string value);

        TokenType getType();
        std::string getValue();
        void append(std::string value);

    private:
        TokenType type;
        std::string value;
};

class UnknownToken: public Token
{
    public:
        UnknownToken(std::string value);
};

class NumberToken: public Token
{
    public:
        NumberToken(std::string value);
};

class StringToken: public Token
{
    public:
        StringToken(std::string value);
};

class IdentifierToken: public Token
{
    public:
        IdentifierToken(std::string value);
};

#endif
