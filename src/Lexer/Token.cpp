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

std::string Token::resolveType()
{
    switch (this->type)
    {
        case Unknown:
            return "Unknown";

        case Number:
            return "Number";

        case String:
            return "String";

        case Identifier:
            return "Identifier";

        case Terminator:
            return "Terminator";

        case Whitespace:
            return "Whitespace";

        case Operator:
            return "Operator";

        case LeftParen:
            return "LeftParen";

        case RightParen:
            return "RightParen";

        case LeftBrace:
            return "LeftBrace";

        case RightBrace:
            return "RightBrace";

        default:
            return "Failed to resolve type";
    }
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

WhitespaceToken::WhitespaceToken(std::string value): Token(Whitespace, value)
{
}

OperatorToken::OperatorToken(std::string value): Token(Operator, value)
{
}

LeftParenToken::LeftParenToken(std::string value): Token(LeftParen, value)
{
}

RightParenToken::RightParenToken(std::string value): Token(RightParen, value)
{
}

LeftBraceToken::LeftBraceToken(std::string value): Token(LeftBrace, value)
{
}

RightBraceToken::RightBraceToken(std::string value): Token(RightBrace, value)
{
}
