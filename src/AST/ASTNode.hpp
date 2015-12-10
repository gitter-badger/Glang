//
// ASTNode.hpp
//
// ASTNode class interface
// Also contains interfaces for other classes related to ASTNode
//
// Created by Gigabyte Giant on 12/10/2015
//

#ifndef __ASTNODE_H__
#define __ASTNODE_H__

#import <iostream>
#import <string>
#import <vector>

// TODO (Gigabyte Giant): Figure out what the root "ASTNode" class needs
//  to be able to accept and store.

class ASTNode
{
    public:
        ASTNode();
};

class VarDeclNode: public ASTNode
{
    public:
        VarDeclNode(std::string varName, std::string value): ASTNode()
        {
            this->name = varName;
            this->value = value;
        }

        std::string name;
        std::string value;
};

#endif
