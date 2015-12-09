//
// misc.hpp
//
// Defines all of our general-purpose functions.
// Created by Gigabyte Giant on 12/09/2015
//

#ifndef __MISC_H__
#define __MISC_H__

#import <fstream>
#import <string>

std::string getFile(const char *filePath)
{
    std::string fileValue;
    std::ifstream inputFile;

    inputFile.open(filePath);

    if (inputFile.is_open())
    {
        char tmpChar;

        while (inputFile.get(tmpChar))
        {
            fileValue = fileValue + tmpChar;
        }

        inputFile.close();
    }

    return fileValue;
}

#endif