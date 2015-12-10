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

        std::string nodeType;

    private:
        std::string resolveTypeToStr(NodeType nodeType);
};

class VarDeclNode: public ASTNode
{
    public:
        VarDeclNode(std::string varName, std::string value): ASTNode(_ntVarDeclNode)
        {
            this->name = varName;
            this->value = value;
        }

        std::string name;
        std::string value;
};

class FuncDeclNode: public ASTNode
{
    public:
        FuncDeclNode(std::string funcName, std::vector<ASTNode> body): ASTNode(_ntFuncDeclNode)
        {
            this->name = funcName;
            this->body = body;
        }

        std::string name;
        std::vector<ASTNode> body;
};

#endif
