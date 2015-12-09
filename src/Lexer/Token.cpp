//
// Token.cpp
//
// Token class implementation
// Created by Gigabyte Giant on 12/09/2015
//

#import "Token.hpp"

Token::Token(std::string type, std::string val)
{
    this->typeStr = type;
    this->valStr = val;
}

std::string Token::getType()
{
    return this->typeStr;
}

std::string Token::getVal()
{
    return this->valStr;
}