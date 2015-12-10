//
// tokenRules.h
//
// Defines all of the macros used when determining what a character is.
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __TOKENRULES_H__
#define __TOKENRULES_H__

// NOTE: All macros in this file should be
//  prefixed with an underscore ('_').
// 
// NOTE: When implementing lexer methods
//  make sure to *not* prefix method names
//  with underscores.

#define _isIdent(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define _isNumber(c) (c >= '0' && c <= '9')
#define _isNewline(c) (c == '\r' || c == '\n' || c == '\f')
#define _isWhitespace(c) (_isNewline(c) || c == ' ' || c == '\t')
#define _isIgnored(c) (c == '\0' || _isWhitespace(c))
#define _isTerminator(c) (c == ';')
#define _isLeftParen(c) (c == '(' || c == '[')
#define _isRightParen(c) (c == ')' || c == ']')
#define _isParen(c) (_isLeftParen(c) || _isRightParen(c))
#define _isCommentStart(c) (c == '$')
#define _isCommentEnd(c) (_isNewline(c))
#define _isOperator(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')

#define _isUnknown(c) ( \
    !_isIdent(c) && \
    !_isNumber(c) && \
    !_isWhitespace(c) && \
    !_isParen(c) && \
    !_isCommentStart(c) && \
    !_isCommentEnd(c) && \
    !_isOperator(c) \
)

#endif