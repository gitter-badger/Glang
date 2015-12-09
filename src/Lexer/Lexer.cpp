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

bool Lexer::isIdentifier(char c)
{
    return _isIdentifier(c);
}

bool Lexer::isNumber(char c)
{
    return _isNumber(c);
}