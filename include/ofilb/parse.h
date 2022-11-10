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

namespace oi
{
    inline std::string parse_file(const std::string& path) noexcept
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

        return result;
    }

    inline float str_to_float(const char*& begin, char end) {
    
        unsigned int mantissa = 0;
        unsigned short size = 0, index = 0;

        while (begin[size] != end) 
        {
            if (begin[size] == '.') { index = size++; continue; }
            
            mantissa *= 10;
            mantissa += unsigned int(begin[size]) - 48;
            
            ++size;
        }
        
        begin = &begin[size]; // I need to move the address to the end of every float

        if (index == 0)
            return (float)mantissa;
        else
            return (float)mantissa / powf(10.0f, (float)(size - index - 1));
    }

    inline unsigned int uint_to_str(const char*& begin, char end) 
    {
        unsigned int number = 0;
        
        while (*begin != end)
        {
            number *= 10;
            number += unsigned int(*begin) - 48;

            ++begin;
        }

        return number;
    }
}