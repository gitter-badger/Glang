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

        if (i == 0)
        {
            this->lastToken = thisTok;
        }

        if ((thisTok.getType() != this->lastToken.getType() || this->is(Ignored, currChar)) &&
            this->tmpTokStr.size() > 0)
        {
            this->putStreamInList();

            this->tmpTokStr.clear();
        }

        if (!this->is(Ignored, currChar))
        {
            this->tmpTokStr.push_back(thisTok);

            this->lastToken = thisTok;
        }
    }
}

void Lexer::printTokenList()
{
    for (size_t i = 0; i < this->tokenList.size(); i++)
    {
        Token currTok = this->tokenList.at(i);

        printf("\"%s\"\t:\t\"%s\"\n", currTok.getVal().c_str(), currTok.getType().c_str());
    }
}

void Lexer::putStreamInList()
{
    std::string tokType = "";
    std::string finalVal = "";

    for (size_t i = 0; i < this->tmpTokStr.size(); i++)
    {
        tokType = this->tmpTokStr.at(i).getType();
        finalVal = finalVal + this->tmpTokStr.at(i).getVal();
    }

    // TODO (Gigabyte Giant): Take this chance to check if something is a keyword.

    this->tokenList.push_back(Token(tokType, finalVal));
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