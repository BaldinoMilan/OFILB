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

#include <array>

#ifndef PARSE_OFILB
#define PARSE_OFILB

namespace oi 
{
    
enum STATEMENT {
    NONE = -1, COMMENT = 0,
    VERTEX = 1, VERTEX_TEXTURE = 2, VERTEX_NORMAL = 3, FACE = 4, 
    SHADING = 5, 
    OBJECT_DEFINITION = 6, 
    USING_MATERIAL = 7, MATERIAL_DEFINITION = 8
};

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


inline float strtf(const char* _beg)
{
    int mantissa = 0;
    size_t i, idx;
    
    if (*_beg == '-')
    {
        for (i = 1; _beg[i] > ' '; ++i)
        {
            if (_beg[i] == '.') { idx = i; continue; }
            mantissa *= 10;
            mantissa += int(_beg[i] - 48);
        }
        return -((float)mantissa / powf(10.0f, (float)(i - idx - 1)));
    }

    for (i = 0; _beg[i] > ' '; ++i)
    {
        if (_beg[i] == '.') { idx = i; continue; }
        mantissa *= 10;
        mantissa += int(_beg[i] - 48);
    }
    return (float)mantissa / powf(10.0f, (float)(i - idx - 1));
}

template<size_t _size>
inline std::array<char, _size> buffer_line(const char* _beg)
{
    std::array<char, _size> arr;
    for (size_t i = 0; true; i++)
    {
        if (_beg[i] == '\n') { arr[i] = '\0'; break; }
        arr[i] = _beg[i];
    }
    
    return arr;
}

} // namespace oi

#endif // PARSE OFILB