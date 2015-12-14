//
// keywords.c
//
// Defines all of Glang's reserved keywords
// Created by Gigabyte Giant on 12/14/2015
//

#ifndef __KEYWORDS_H__
#define __KEYWORDS_H__

#define _isKeyword(str) (_keyFn(str) || _keyLet(str))

#define _keyFn(str) (str == "fn")
#define _keyLet(str) (str == "let")
#define _keyGive(str) (str == "give")

#endif
