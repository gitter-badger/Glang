//
// AST.hpp
//
// AST class interface
// Created by Gigabyte Giant on 12/10/2015
//

#ifndef __AST_H__
#define __AST_H__

#import <iostream>
#import <vector>
#import "ASTNode.hpp"

class AST
{
    public:
        AST();
        void addNode(ASTNode newNode);
        size_t size();
        ASTNode get(size_t index);

    private:
        std::vector<ASTNode> nodes;
};

#endif
