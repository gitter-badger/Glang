//
// keywords.hpp
//
// Keywords class interface
// Created by Gigabyte Giant on 12/10/2015
//

#ifndef __KEYWORDS_H__
#define __KEYWORDS_H__

#include <iostream>
#include <string>
#include <vector>

class Keywords
{
    public:
        Keywords();
        bool isStrKeyword(std::string subject);
        
    private:
        std::vector<std::string> keywordList;
};

#endif