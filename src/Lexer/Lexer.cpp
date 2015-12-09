//
// Lexer.cpp
//
// Lexer class implementation
// Created by Gigabyte Giant on 12/09/2015
//

#import "Lexer.hpp"

Lexer::Lexer()
{
}

bool Lexer::is(tokenType type, char c)
{
    switch (type)
    {
        case Identifier:
            return _isIdentifier(c);

        case Number:
            return _isNumber(c);

        default:
            return false;
    }
}