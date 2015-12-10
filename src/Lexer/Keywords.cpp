//
// Keywords.cpp
//
// Keywords class implementation
// Created by Gigabyte Giant on 12/10/2015
//

#include "Keywords.hpp"

Keywords::Keywords()
{
    this->keywordList.push_back("let");
    this->keywordList.push_back("fn");
    this->keywordList.push_back("do");
    this->keywordList.push_back("done");
    this->keywordList.push_back("give");
}

bool Keywords::isStrKeyword(std::string subject)
{
    for (size_t kwInd = 0; kwInd < this->keywordList.size(); kwInd++)
    {
        if (subject == this->keywordList.at(kwInd))
        {
            return true;
        }
    }
    
    return false;
}