//
// Lexer.cpp
//
// Lexer class implementation
// Created by Gigabyte Giant on 12/09/2015
//
// TODO (Gigabyte Giant): Completely rewrite Lexer class implementation.
//

#import "Lexer.hpp"

Lexer::Lexer()
{

}

std::vector<Token> Lexer::tokenizeFile(const char *filePath)
{
    std::ifstream file;

    // Used to keep track of all of the "final tokens".
    // Also gets returned to caller.
    std::vector<Token> finalTokenList;

    // Used to keep track of things like "123546"
    std::string tmpStream = "";

    // Used to keep track of the last token that we iterated over.
    Token lastToken = Token(Unknown, "N/A");

    // (Try to) open the file at the path specified in 'filePath'
    file.open(filePath);

    // If we were able to open the file...
    if (file.is_open())
    {
        // ...tokenize!

        char tmpChar;

        while (file.get(tmpChar))
        {
            if (file.good())
            {
                Token currToken = this->getTokenFromChar(tmpChar);

                // TODO (Gigabyte Giant): Figure out a more "sane" check
                //  to see if we're at the start of the file.
                if (lastToken.getValue() == "N/A")
                {
                    lastToken = currToken;
                }

                if ((lastToken.getType() != currToken.getType()) &&
                    tmpStream.size() > 0)
                {
                    // TODO (Gigabyte Giant): Perform a final check to see if
                    //  the "tokens" in 'tmpStream' make up a reserved word.

                    // Append a new 'Token' to 'finalTokenList'.
                    finalTokenList.push_back(Token(lastToken.getType(), tmpStream));

                    // Clear 'tmpStream'.
                    tmpStream = "";
                }

                if (!this->is(_ctIgnored, tmpChar))
                {
                    // Append the current character to 'tmpStream'.
                    tmpStream = tmpStream + tmpChar;

                    // Since we'll be moving forward, "the current token
                    //  becomes the last token".
                    lastToken = currToken;
                }
            }
        }

        // Since we've finished looping through the file, we should
        //  dump the contents of 'tmpStream' into 'finalTokenList'.
        finalTokenList.push_back(Token(lastToken.getType(), tmpStream));

        // Close the file that we opened earlier, because we're done with it.
        file.close();
    }
    else
    {
        // TODO (Gigabyte Giant): If we couldn't open the file, tell the end
        //  user.
    }

    // TEST: Check to make sure everything was "tokenized" correctly.
    for (size_t i = 0; i < finalTokenList.size(); i++)
    {
        Token thisTok = finalTokenList.at(i);

        printf("[%s]\t%s\n", thisTok.resolveType().c_str(), thisTok.getValue().c_str());
    }

    return finalTokenList;
}

bool Lexer::is(CharacterType type, char c)
{
    switch (type)
    {
        case _ctNumber:
            return _isNumber(c);

        case _ctIdentifier:
            return _isIdent(c);

        case _ctWhitespace:
            return _isWhitespace(c);

        case _ctIgnored:
            return _isIgnored(c);

        case _ctUnknown:
            // I really don't think this check is needed, but whatever.
            return _isUnknown(c);
    }

    return false;
}

Token Lexer::getTokenFromChar(char c)
{
    if (this->is(_ctIdentifier, c))
    {
        return Token(Identifier, std::string(c, 1));
    }
    else if (this->is(_ctNumber, c))
    {
        return Token(Number, std::string(c, 1));
    }
    else if (this->is(_ctWhitespace, c))
    {
        return Token(Whitespace, std::string(c, 1));
    }

    return Token(Unknown, std::string(c, 1));
}