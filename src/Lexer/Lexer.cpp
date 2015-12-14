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

    lexFlags flags;

    // === Begin flag initialization ===
    flags.inComment = false;
    flags.inString = false;
    flags.seenEscape = false;
    flags.doIgnores = true;
    // === End flag initialization =====

    file.open(filePath);

    if (file.is_open())
    {
        Token lastToken = UnknownToken("");
        char tmpChar;

        while (file.get(tmpChar))
        {
            if (file.good())
            {
                Token tempToken = UnknownToken("");

                if (!flags.inComment && !flags.seenEscape && !flags.inString && _isCommentStart(tmpChar))
                {
                    flags.inComment = true;
                }
                else if (flags.inComment && !flags.seenEscape && !flags.inString && _isCommentEnd(tmpChar))
                {
                    flags.inComment = false;
                }

                if (!flags.inComment)
                {
                    std::string stringVal = std::string(&tmpChar);

                    if (!flags.seenEscape && _isEscape(tmpChar))
                    {
                        flags.seenEscape = true;
                    }
                    else if (flags.seenEscape)
                    {
                        flags.seenEscape = false;
                    }
                    if (!flags.seenEscape && !flags.inString && _isQuote(tmpChar))
                    {
                        tempToken = StringToken("\"");
                        flags.inString = true;
                        flags.doIgnores = false;
                    }
                    else if (!flags.seenEscape && flags.inString && _isQuote(tmpChar))
                    {
                        flags.inString = false;
                        flags.doIgnores = true;
                    }

                    if (!flags.inString)
                    {
                        tempToken = this->getTokenFromChar(tmpChar, flags);
                    }
                    else
                    {
                        tempToken = StringToken(stringVal);
                    }

                    if ((lastToken.getType() != tempToken.getType()) && lastToken.getValue().size() > 0)
                    {
                        finalTokenList.push_back(lastToken);
                        lastToken = UnknownToken("");
                    }

                    if ((flags.doIgnores && !_isIgnored(tmpChar)) || !flags.doIgnores)
                    {
                        lastToken = Token(tempToken.getType(), lastToken.getValue() + stringVal);
                    }
                }
            }
        }

        if (lastToken.getType() != Unknown)
        {
            finalTokenList.push_back(lastToken);
        }

        file.close();
    }

    for (size_t i = 0; i < finalTokenList.size(); i++)
    {
        Token thisTok = finalTokenList.at(i);

        printf("[%s]\t%s\n", thisTok.resolveType().c_str(), thisTok.getValue().c_str());
    }

    return finalTokenList;
}

Token Lexer::getTokenFromChar(char c, lexFlags flags)
{
    std::string stringVal = std::string(&c);
    Token tempToken = UnknownToken(stringVal);

    if (_isIdentifier(c))
    {
        tempToken = IdentifierToken(stringVal);
    }
    else if (_isNumber(c))
    {
        tempToken = NumberToken(stringVal);
    }
    else if (_isOperator(c))
    {
        tempToken = OperatorToken(stringVal);
    }
    else if (_isWhitespace(c))
    {
        tempToken = WhitespaceToken(stringVal);
    }
    else if (_isTerminator(c))
    {
        tempToken = TerminatorToken(stringVal);
    }
    else if (_isLeftParen(c))
    {
        tempToken = LeftParenToken(stringVal);
    }
    else if (_isRightParen(c))
    {
        tempToken = RightParenToken(stringVal);
    }
    else if (_isLeftBrace(c))
    {
        tempToken = LeftBraceToken(stringVal);
    }
    else if (_isRightBrace(c))
    {
        tempToken = RightBraceToken(stringVal);
    }
    else if (_isQuote(c))
    {
        tempToken = StringToken(stringVal);
    }

    return tempToken;
}
