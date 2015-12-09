//
// Token.hpp
//
// Token class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __TOKEN_H__
#define __TOKEN_H__

#import <iostream>
#import <string>

class Token
{
    public:
        Token(std::string type, std::string val);

        //
        // Token::getType()
        //
        // Used to fetch the token's type
        //
        std::string getType();

        //
        // Token::getVal()
        //
        // Used to fetch the token's value
        //
        std::string getVal();

    private:
        std::string typeStr;
        std::string valStr;
};

#endif