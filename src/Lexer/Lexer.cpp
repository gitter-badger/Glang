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
        Token thisTok = this->getToken(currChar);

        if (!this->is(Ignored, currChar))
        {
            printf("%c\t:\t%s\n", currChar, thisTok.getType().c_str());
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

Token Lexer::getToken(char c)
{
    std::string tmpStr = "";
    tmpStr = c;

    if (this->is(Identifier, c))
    {
        return Token("Identifier", tmpStr);
    }
    else if (this->is(Number, c))
    {
        return Token("Number", tmpStr);
    }
    else if (this->is(ArithmeticOperator, c))
    {
        return Token("ArithmeticOperator", tmpStr);
    }
    else if (this->is(Ignored, c))
    {
        return Token("Ignored", tmpStr);
    }

    return Token("Unknown", tmpStr);
}