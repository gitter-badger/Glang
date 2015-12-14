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

                // TODO (Gigabyte Giant): Rewrite this, as Dalendrion broke it.
                if (!flags.inComment && !flags.seenEscape && _isCommentStart(tmpChar))
                {
                    flags.inComment = true;
                }
                else if (flags.inComment && !flags.seenEscape && _isCommentEnd(tmpChar))
                {
                    flags.inComment = false;
                }
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
                }
                else if (!flags.seenEscape && flags.inString && _isQuote(tmpChar))
                {
                    tempToken = StringToken("\"");
                    flags.inString = false;
                }

                std::string stringVal = std::string(&tmpChar);

                if (!flags.inComment && !flags.inString)
                {
                    if (_isIdentifier(tmpChar))
                    {
                        tempToken = IdentifierToken(stringVal);
                    }
                    if (_isNumber(tmpChar))
                    {
                        tempToken = NumberToken(stringVal);
                    }
                    if (_isOperator(tmpChar))
                    {
                        tempToken = OperatorToken(stringVal);
                    }
                    if (_isWhitespace(tmpChar))
                    {
                        tempToken = WhitespaceToken(stringVal);
                    }
                    if (_isTerminator(tmpChar))
                    {
                        tempToken = TerminatorToken(stringVal);
                    }
                }
                else if (flags.inString)
                {
                    tempToken = StringToken(stringVal);
                }

                if ((lastToken.getType() != tempToken.getType()) && lastToken.getValue().size() > 0)
                {
                    finalTokenList.push_back(lastToken);
                    lastToken = UnknownToken("");
                }

                // This is a really crappy way of doing this.
                //  I (Gigabyte Giant), obviously didn't write it.
                //  (Actually, I did... I feel ashamed)
                if ((flags.inString == true ? true : !_isIgnored(tmpChar)))
                {
                    lastToken = Token(tempToken.getType(), lastToken.getValue() + stringVal);
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

bool Lexer::is(CharacterType type, char c)
{
    return false;
}

Token Lexer::getTokenFromChar(char c)
{
    if (_isIdentifier(c))
    {
        return IdentifierToken(std::string(c, 1));
    }
    else if (_isNumber(c))
    {
        return NumberToken(std::string(c, 1));
    }
    else if (_isWhitespace(c))
    {
        return WhitespaceToken(std::string(c, 1));
    }
    else if (_isTerminator(c))
    {
        return TerminatorToken(std::string(c, 1));
    }
    else if (_isOperator(c))
    {
        return OperatorToken(std::string(c, 1));
    }

    return UnknownToken(std::string(c, 1));
}
