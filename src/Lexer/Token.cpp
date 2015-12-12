//
// Token.cpp
//
// Token class implementation
// Created by Gigabyte Giant on 12/09/2015
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

void Token::append(std::string value)
{
    this->value = this->value + value;
}

UnknownToken::UnknownToken(std::string value): Token(Unknown, value)
{
}

NumberToken::NumberToken(std::string value): Token(Number, value)
{
}

StringToken::StringToken(std::string value): Token(String, value)
{
}

IdentifierToken::IdentifierToken(std::string value): Token(Identifier, value)
{
}

TerminatorToken::TerminatorToken(std::string value): Token(Terminator, value)
{
}
