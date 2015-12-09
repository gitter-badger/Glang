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

#define _isIdentifier(c)    ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define _isNumber(c)        (c >= '0' && c <= '9')
#define _isArithOperator(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
#define _isWhitespace(c)    (c == '\n' || c == '\r' || c == '\t' || c == '\f' || c == ' ')
#define _isComment(c)       (c == '$')
#define _isIgnored(c)       (_isWhitespace(c) || c == '\0')
#define _isLeftParen(c)     (c == '(' || c == '[')
#define _isRightParen(c)    (c == ')' || c == ']')
#define _isTerminator(c)    (c == ';')

#endif