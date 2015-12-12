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

std::vector<Token> Lexer::tokenizeFile(const char *filePath)
{
    std::ifstream file;

    std::vector<Token> finalTokenList;

    file.open(filePath);

    if (file.is_open())
    {
        char tmpChar;

        while (file.get(tmpChar))
        {
            
        }

        file.close();
    }

    return finalTokenList;
}

bool Lexer::is(CharacterType type, char c)
{
    return false;
}

Token Lexer::getTokenFromChar(char c)
{
    return Token(Unknown, std::string(c, 1));
}