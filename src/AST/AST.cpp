//
// AST.cpp
//
// AST class implementation
// Created by Gigabyte Giant on 12/10/2015
//

#import "AST.hpp"

AST::AST()
{
}

void AST::addNode(ASTNode newNode)
{
    this->nodes.push_back(newNode);
}
