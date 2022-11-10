/*
	--------------------------------------------------
			Obj Format Import Library (OFILB)
	--------------------------------------------------

*/
/* @file mtl_file.h
*/
#pragma once
#include <string>
#include <vector>

#include <ofilb/type_vec.h>

namespace oi {
	
	struct Material;

	enum STM_MTL {
		None = -1, Comment = 0,
		Ka, Kd, Ks, Ns, Ke,
		Ni, d, Tr, illum,
		newmtl,
		map_Ka, map_Kd, map_Ks, map_Ns, map_d, map_bump, disp, decal
	};

	enum ERROR_MTL {
		StatementError = 4,
	};

	namespace mtl {

		struct map {
			char label[64];
			const char* type;
		};

		struct error_data {
			unsigned int scancode;
			unsigned long long line;
			const char* errline;
		};

		class FileParser {
		public:
			FileParser(const char* filepath, std::vector<oi::Material>& materials);
			~FileParser() = default;
			FileParser(const FileParser&) = default;

			void process_file();
			void process_line();
			signed short check_statement();
			void process_statement(oi::STM_MTL statement);

		private:
			std::string file_data;
			std::vector<oi::Material>& materials;

			unsigned long long current_material;

			unsigned long long current_line;
			const char* current_addr;

			std::vector<oi::mtl::error_data> errorbuffer;
		};
	}
	
	struct Material {
		oi::vec3 ambient_coef, diffuse_coef, specular_coef;
		oi::vec3 emissive_coef;
		float specular_exponent, optical_density, dissolved;

		unsigned short illum;
		std::vector<oi::mtl::map> textures;

		char name_buffer[64];
	};

	//--	is called in the obj parser to read the mtl file
	std::vector<oi::Material> mtl_parser(const char* file, const char* dir);
	
	inline bool compare_str(const char* addr, const char* str) {
		while (*str)  {
			if (*str != *addr) { return false; }
			++str; ++addr;
		}
		return true;
	}

	inline void endl(const char*& addr) {
		while (*addr != '\n') { ++addr; }
	}

	// -- fonctions to get the filepath 

	inline unsigned short str_size(const char* str) {
		unsigned short size = 0;
		while (str[size]) { size++; }

		return ++size;
	}

	inline void str_to_buffer(const char* str, char* buffer) {
		unsigned short i = 0;
		while (str[i]) 
		{
			buffer[i] = str[i];
			i++;
		}
		buffer[i] = '\0';
	}

	inline const char* switch_file_to_path(const char* f, const char* dir)  {	
		signed short index = oi::str_size(dir);
		while (dir[index] != '/') { 
			if (!index) { index = -1; break; }
			--index;
		}
		
		char* buffer = new char[index + oi::str_size(f) + 1];	
			
		for (signed short i = 0; i <= index; i++) {
			buffer[i] = dir[i];
		}
		
		oi::str_to_buffer(f, &buffer[index + 1]);
		return buffer; // have to delete it manualy later in the program 
	}

	template<unsigned long long _size>
	inline 
	const char* buffer_str_s(char (&buff)[_size], const char* begin, char end) {
		unsigned long long i = 0;

		while (begin[i] != end && i < _size - 1) {
			buff[i] = begin[i];
			i++;
		}
		buff[i] = '\0';
		return &(begin[i]);
	}
}