//
// Parser.hpp
//
// Parser class interface
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __PARSER_H__
#define __PARSER_H__

#import <iostream>
#import <vector>
#import "../Lexer/Token.hpp"
#import "../AST/AST.hpp"
#import "../AST/ASTNode.hpp"

class Parser
{
    public:
        Parser();
        void parse(std::vector<Token> tokenList);

    private:
        AST ast;
        std::vector< std::vector<Token> > getLines(std::vector<Token> tokList);

        VarDeclNode parseVarDecl(std::vector<Token> line);
        FuncDeclNode parseFuncDecl(std::vector<Token> line);
};

#endif
