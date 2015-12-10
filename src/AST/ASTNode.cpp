//
// ASTNode.cpp
//
// ASTNode class implementation
//
// Created by Gigabyte Giant on 12/10/2015
//

#import "ASTNode.hpp"

ASTNode::ASTNode(NodeType nodeType)
{
    this->nodeType = this->resolveTypeToStr(nodeType);
}

std::string ASTNode::resolveTypeToStr(NodeType nodeType)
{
    switch (nodeType)
    {
        case _ntVarDeclNode:
            return "VariableDeclaration";

        case _ntFuncDeclNode:
            return "FunctionDeclaration";
    }

    return "";
}
