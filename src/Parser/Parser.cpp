//
// Parser.cpp
//
// Parser class implementation
// Created by Gigabyte Giant on 12/09/2015
//

#import "Parser.hpp"

Parser::Parser()
{
}

void Parser::parse(std::vector<Token> tokenList)
{
    std::vector< std::vector<Token> > fileLines = this->getLines(tokenList);

    for (size_t lnInd = 0; lnInd < fileLines.size(); lnInd++)
    {
        std::vector<Token> currLn = fileLines.at(lnInd);

        if (currLn.at(0).resolveType() == "Keyword")
        {
            if (currLn.at(0).getValue() == "let")
            {
                this->ast.addNode(this->parseVarDecl(currLn));
            }
            else if (currLn.at(0).getValue() == "fn")
            {
                this->ast.addNode(this->parseFuncDecl(currLn));
            }
        }
        else
        {
            // TODO (Gigabyte Giant): Figure out a good way to determine
            //  what everything else is.
        }
    }

    // TEST: Check to see if our ASTNodes were added properly
    // TODO (Gigabyte Giant): Remove once the Parser is somewhat finished.
    for (size_t i = 0; i < this->ast.size(); i++)
    {
        ASTNode currNode = this->ast.get(i);

        printf("%s", currNode.nodeType.c_str());

        if (currNode.nodeType == "VariableDeclaration")
        {
            printf(": %s %s\n", currNode.varName.c_str(), currNode.varValue.c_str());
        }

        printf("\n");
    }
}

std::vector< std::vector<Token> > Parser::getLines(std::vector<Token> tokList)
{
    std::vector< std::vector<Token> > allLines;
    std::vector<Token> currentLine;

    for (size_t tokInd = 0; tokInd < tokList.size(); tokInd++)
    {
        Token thisTok = tokList.at(tokInd);

        if (thisTok.resolveType() != "Terminator")
        {
            currentLine.push_back(thisTok);
        }
        else
        {
            allLines.push_back(currentLine);

            currentLine.clear();
        }
    }

    return allLines;
}

VarDeclNode Parser::parseVarDecl(std::vector<Token> line)
{
    // TODO (Gigabyte Giant): Parse a variable declaration

    return VarDeclNode("someVar", "someValue");
}

FuncDeclNode Parser::parseFuncDecl(std::vector<Token> line)
{
    // TODO (Gigabyte Giant): Parse a function declaration

    return FuncDeclNode("someFunc", std::vector<ASTNode>());
}
