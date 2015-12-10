//
// ASTNode.hpp
//
// ASTNode class interface
// Also contains interfaces and implementations for other classes related to ASTNode
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
//
// An ASTNode will *always* accept a "NodeType" parameter.
// ...

enum NodeType
{
    _ntVarDeclNode,
    _ntFuncDeclNode
};

class ASTNode
{
    public:
        ASTNode(NodeType nodeType);

        // Begin properties used for all nodes
        std::string nodeType;
        // End properties used for all nodes

        // Begin properties used for variables
        std::string varName;
        std::string varValue;
        // End properties used for variables

        // Begin properties used for functions
        std::string funcName;
        std::vector<ASTNode> funcBody;
        // End properties used for functions

    private:
        std::string resolveTypeToStr(NodeType nodeType);
};

class VarDeclNode: public ASTNode
{
    public:
        VarDeclNode(std::string varName, std::string value): ASTNode(_ntVarDeclNode)
        {
            this->varName = varName;
            this->varValue = value;
        }
};

class FuncDeclNode: public ASTNode
{
    public:
        FuncDeclNode(std::string funcName, std::vector<ASTNode> body): ASTNode(_ntFuncDeclNode)
        {
            this->funcName = funcName;
            this->funcBody = body;
        }
};

#endif
