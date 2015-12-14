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
    Identifier,
    Terminator,
    Operator,
    Whitespace,
    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace
};

class Token
{
    public:
        Token(TokenType type, std::string value);

        TokenType getType();
        std::string getValue();
        std::string resolveType();

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

class TerminatorToken: public Token
{
    public:
        TerminatorToken(std::string value);
};

class WhitespaceToken: public Token
{
    public:
        WhitespaceToken(std::string value);
};

class OperatorToken: public Token
{
    public:
        OperatorToken(std::string value);
};

class LeftParenToken: public Token
{
    public:
        LeftParenToken(std::string value);
};

class RightParenToken: public Token
{
    public:
        RightParenToken(std::string value);
};

class LeftBraceToken: public Token
{
    public:
        LeftBraceToken(std::string value);
};

class RightBraceToken: public Token
{
    public:
        RightBraceToken(std::string value);
};

#endif
