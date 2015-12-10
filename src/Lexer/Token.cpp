//
// Token.cpp
//
// Token class implementation
// Created by Gigabyte Giant on 12/09/2015
//
// TODO (Gigabyte Giant): Rewrite Token class implementation.
//

#import "Token.hpp"

Token::Token(TokenType type, std::string value)
{
    this->type = type;
    this->value = value;
}

TokenType Token::getType()
{
    return this->type;
}

std::string Token::getValue()
{
    return this->value;
}

std::string Token::resolveType()
{
    switch (this->type)
    {
        case Identifier:
            return "Identifier";

        case Number:
            return "Number";

        case Whitespace:
            return "Whitespace";

        case Unknown:
            return "Unknown";
    }
}