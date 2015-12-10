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
    Identifier,
    Number,
    Whitespace,
    Unknown
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

#endif