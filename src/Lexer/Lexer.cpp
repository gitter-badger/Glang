//
// Lexer.cpp
//
// Lexer class implementation
// Created by Gigabyte Giant on 12/09/2015
//

#import "Lexer.hpp"

Lexer::Lexer()
{
    // TODO (Gigabyte Giant): Figure out a better way to keep track of
    //  reserved words.
    this->keywords.push_back("fn");
    this->keywords.push_back("let");
    this->keywords.push_back("do");
    this->keywords.push_back("done");
    this->keywords.push_back("give");
}

std::vector<Token> Lexer::tokenize(std::string fileData)
{
    for (int i = 0; i < (fileData.length() + 1); i++)
    {
        char currChar = *(fileData.c_str() + i);
        Token thisTok = this->getToken(currChar);

        if (thisTok.getType() == "Comment")
        {
            this->inComment = true;
        }

        if (currChar == '\n')
        {
            this->inComment = false;
        }

        if (!this->inComment)
        {
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

    return this->tokenList;
}

void Lexer::printTokenList()
{
    for (size_t i = 0; i < this->tokenList.size(); i++)
    {
        Token currTok = this->tokenList.at(i);

        printf("%s (%s)\n", currTok.getVal().c_str(), currTok.getType().c_str());
    }
}

void Lexer::reset()
{
    this->tokenList.clear();
    this->tmpTokStr.clear();
    this->lastToken = Token("Ignored", "N/A");
    this->inComment = false;
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
    if (tokType == "Identifier")
    {
        if (this->isKeyword(finalVal))
        {
            this->tokenList.push_back(Token("Keyword", finalVal));
            return;
        }
    }

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

        case Parenthesis:
            return _isLeftParen(c) || _isRightParen(c);

        case LeftParen:
            return _isLeftParen(c);

        case RightParen:
            return _isRightParen(c);

        case Comment:
            return _isComment(c);

        case Terminator:
            return _isTerminator(c);

        default:
            return false;
    }
}

bool Lexer::isKeyword(std::string identifier)
{
    for (size_t i = 0; i < this->keywords.size(); i++)
    {
        if (this->keywords.at(i) == identifier) {
            return true;
        }
    }

    return false;
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
    else if (this->is(Parenthesis, c))
    {
        if (this->is(LeftParen, c))
        {
            return Token("LeftParen", tmpStr);
        }
        else if (this->is(RightParen, c))
        {
            return Token("RightParen", tmpStr);
        }
    }
    else if (this->is(Comment, c))
    {
        return Token("Comment", tmpStr);
    }
    else if (this->is(Terminator, c))
    {
        return Token("Terminator", tmpStr);
    }


    return Token("Unknown", tmpStr);
}