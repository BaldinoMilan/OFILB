/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file parse.h
*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>

#ifndef PARSE_OFILB
#define PARSE_OFILB

std::string parse_file(const std::string& path) noexcept
{
    std::string result;
    std::ifstream in(path, std::ios::in | std::ios::binary);
    if (in)
    {
        in.seekg(0, std::ios::end);
        result.resize((unsigned int)in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&result[0], result.size());
        in.close();
    }
    else
    {
        printf_s("ofilb (error) : cannot find the file '%s' in the directory.\n", path.c_str());
    }

    return result;
}

#endif // PARSE OFILB