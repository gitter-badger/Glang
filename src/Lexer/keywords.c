//
// keywords.c
//
// Defines all of Glang's reserved keywords
// Created by Gigabyte Giant on 12/14/2015
//

#ifndef __KEYWORDS_H__
#define __KEYWORDS_H__

// TODO (Gigabyte Giant): Figure out a better way to do this...
#define _isKeyword(str) ( \
    _keyFn(str) ||        \
    _keyLet(str) ||       \
    _keyGive(str)         \
)

#define _keyFn(str) (str == "fn")
#define _keyLet(str) (str == "let")
#define _keyGive(str) (str == "give")

#endif
