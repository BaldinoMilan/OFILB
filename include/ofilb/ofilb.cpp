/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file ofilb.cpp
*/

#include "ofilb/ofilb.h"

namespace oi
{

	void import_file(const char* path)
	{
		std::string obj = oi::parse_file(path);
		if (!obj.size())
		{
			printf_s("ofilb (error) : cannot find the file '%s' in the directory.\n", path);
			return;
		}
		
		int start = clock();
		for (const char* it = obj.c_str(); *it; ++it) {
			
			process_line(it);
		}
		int end = clock();
		std::cout << (float)(end - start) / (float)CLOCKS_PER_SEC << std::endl;
		
	}
	
	void process_line(const char*& it)
	{
		STATEMENT stm = check_statement(it);
		if (stm == NONE)
		{
			auto buff = buffer_line<128>(it);
			printf("ofilb (error) : statement error at line '%s'.\n", buff.data());
		}
		
		process_statement(++it, stm);
	}

	void process_statement(const char*& ptr, STATEMENT state)
	{
		if (state == VERTEX)
		{
			oi::vec3 vertex;

			++ptr;
			vertex.x = oi::strtf(ptr);
			while (*ptr != ' ') ++ptr;

			++ptr;
			vertex.y = oi::strtf(ptr);
			while (*ptr != ' ') ++ptr;

			++ptr; 
			vertex.z = oi::strtf(ptr);
			while (*ptr != '\n') ++ptr;

			std::cout << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
		}
		else
		{
			for (; *ptr != '\n'; ++ptr) { }
		}
	}

	inline STATEMENT check_statement(const char* it)
	{
		switch (*it)
		{
		case '#':
			return COMMENT;

		case 'v':

			switch (*(it + 1))
			{
			case 't':
				return VERTEX_TEXTURE;
			case 'n':
				return VERTEX_NORMAL;
			default:
				return VERTEX;
			}

		case 'f':
			return FACE;

		case 's':
			return SHADING;

		case 'o':
			return OBJECT_DEFINITION;

		case 'u':
			return USING_MATERIAL;

		case 'm':
			return MATERIAL_DEFINITION;

		default:
			return NONE;
		}
	}

} // namespace oi