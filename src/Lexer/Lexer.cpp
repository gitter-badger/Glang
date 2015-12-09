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

void Lexer::tokenize(std::string fileData)
{
    for (int i = 0; i < (fileData.length() + 1); i++)
    {
        char currChar = *(fileData.c_str() + i);

        if (!this->is(Ignored, currChar))
        {
            printf("Current character: %c\n", currChar);
        }
    }
}

bool Lexer::is(tokenType type, char c)
{
    switch (type)
    {
        case Identifier:
            return _isIdentifier(c);

        case Number:
            return _isNumber(c);

        case ArithmeticOperator:
            return _isArithOperator(c);

        case Ignored:
            return _isIgnored(c);

        default:
            return false;
    }
}