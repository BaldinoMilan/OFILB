/*
	--------------------------------------------------
			Obj Format Import Library (OFILB)
	--------------------------------------------------

*/
/* @file mtl_file.cpp
*/

#include "ofilb/mtl_file.h"
#include "ofilb/parse.h"

namespace oi {

	std::vector<oi::Material> mtl_parser(const char* file, const char* dir) // main func of the file
	{
		const char* filepath = oi::switch_file_to_path(file, dir);
		std::vector<oi::Material> materials;
		
		oi::mtl::FileParser mtl_parser(filepath, materials);
		mtl_parser.process_file();

		return materials;
	}

	namespace mtl {

		FileParser::FileParser(const char* filepath, std::vector<oi::Material>& materials)
			:file_data(oi::parse_file(filepath)), materials(materials), current_material(-1), current_line(0), errorbuffer()
		{
			if (file_data.empty()) {
				current_addr = nullptr;
				// TO DO: 
				// -- add an error : wrong path
				return;
			}
			current_addr = file_data.c_str();
			delete[] filepath; // free the buffer alocated in 'const char* oi::switch_file_to_path()'
		}

		void FileParser::process_file()
		{
			if (!current_addr)
				return;

			while (*current_addr) 
			{
				this->process_line();
				++current_addr;
			}
			return;
		}

		void FileParser::process_line()
		{
			oi::STM_MTL statement = (oi::STM_MTL)(this->check_statement());
			if (statement == oi::STM_MTL::None) {
				errorbuffer.push_back({ oi::ERROR_MTL::StatementError, current_line, current_addr }); // call the error message in the destructor
			}

			this->process_statement(statement);
		}

		void FileParser::process_statement(oi::STM_MTL statement)
		{	
			switch (statement)
			{
			case oi::STM_MTL::newmtl:
				materials.push_back({}); ++current_material;
				current_addr = oi::buffer_str_s(materials[current_material].name_buffer, current_addr, '\n');
			
			default:
				if (current_material == -1) { oi::endl(current_addr); return; } // can't define something without defining a newmtl before
				
				std::vector<oi::mtl::map>& texture_maps = materials[current_material].textures;

				switch (statement) // it is a long function where each statement is specified so it basicly convert string into float
					// and put it in the last material;
				{
				case oi::STM_MTL::Ka: // from here -- 3 component vector
					materials[current_material].ambient_coef = { 
						oi::str_to_float(current_addr, ' '), oi::str_to_float(++current_addr, ' '), oi::str_to_float(++current_addr, '\n') 
					}; 
					return;
				
				case oi::STM_MTL::Kd:
					materials[current_material].diffuse_coef = {
						oi::str_to_float(current_addr, ' '), oi::str_to_float(++current_addr, ' '), oi::str_to_float(++current_addr, '\n')
					};
					return;

				case oi::STM_MTL::Ks:
					materials[current_material].specular_coef = {
						oi::str_to_float(current_addr, ' '), oi::str_to_float(++current_addr, ' '), oi::str_to_float(++current_addr, '\n')
					};
					return;

				case oi::STM_MTL::Ke:
					materials[current_material].emissive_coef = {
						oi::str_to_float(current_addr, ' '), oi::str_to_float(++current_addr, ' '), oi::str_to_float(++current_addr, '\n')
					};
					return;

				case oi::STM_MTL::Ns: // -- single float component
					materials[current_material].specular_exponent = oi::str_to_float(current_addr, '\n');
					return;

				case oi::STM_MTL::Ni:
					materials[current_material].optical_density = oi::str_to_float(current_addr, '\n');
					return;

				case oi::STM_MTL::d:
					materials[current_material].dissolved = oi::str_to_float(current_addr, '\n');
					return;

				case oi::STM_MTL::Tr:
					materials[current_material].dissolved = 1.0f - oi::str_to_float(current_addr, '\n');
					return;

				case oi::STM_MTL::illum: // -- single unsigned int component
					materials[current_material].illum = (unsigned short)oi::uint_to_str(current_addr, '\n');
					return;
				
				case oi::STM_MTL::map_Ka: // -- signle texture map components -> have to get a the label
					texture_maps.push_back({ {}, "map_Ka" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;

				case oi::STM_MTL::map_Kd:
					texture_maps.push_back({ {}, "map_Kd" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;

				case oi::STM_MTL::map_Ks:
					texture_maps.push_back({ {}, "map_Ks" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;

				case oi::STM_MTL::map_Ns:
					texture_maps.push_back({ {}, "map_Ns" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;;

				case oi::STM_MTL::map_bump:
					texture_maps.push_back({ {}, "map_bump" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;

				case oi::STM_MTL::map_d:
					texture_maps.push_back({ {}, "map_d" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;

				case oi::STM_MTL::disp:
					texture_maps.push_back({ {}, "disp" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;
				
				case oi::STM_MTL::decal:
					texture_maps.push_back({ {}, "decal" });
					current_addr = oi::buffer_str_s(texture_maps[texture_maps.size() - 1].label, current_addr, '\n');
					return;

				default:
					oi::endl(current_addr); 
					return;
				}
			}
		}

		inline signed short FileParser::check_statement() // large function where we check every key word and return the associated enum
		{
			if (compare_str(current_addr, "newmtl ")) {
				current_addr += 7; return oi::STM_MTL::newmtl;
			}
			if (compare_str(current_addr, "Ka ")) {
				current_addr += 3; return oi::STM_MTL::Ka;
			}
			if (compare_str(current_addr, "Kd ")) {
				current_addr += 3; return oi::STM_MTL::Kd;
			}
			if (compare_str(current_addr, "Ks ")) {
				current_addr += 3; return oi::STM_MTL::Ks;
			}
			if (compare_str(current_addr, "Ke ")) {
				current_addr += 3; return oi::STM_MTL::Ke;
			}
			if (compare_str(current_addr, "Ns ")) {
				current_addr += 3; return oi::STM_MTL::Ns;
			}
			if (compare_str(current_addr, "Ni ")) {
				current_addr += 3; return oi::STM_MTL::Ni;
			}
			if (compare_str(current_addr, "d ")) {
				current_addr += 2; return oi::STM_MTL::d;
			}
			if (compare_str(current_addr, "Tr ")) {
				current_addr += 3; return oi::STM_MTL::Tr;
			}
			if (compare_str(current_addr, "illum ")) {
				current_addr += 6; return oi::STM_MTL::illum;
			}
			if (compare_str(current_addr, "# ")) {
				current_addr += 2; return oi::STM_MTL::Comment;
			}
			if (compare_str(current_addr, "\n")) {
				return oi::STM_MTL::Comment;
			}
			if (compare_str(current_addr, "map_Ka ")) {
				current_addr += 7; return oi::STM_MTL::map_Ka;
			}
			if (compare_str(current_addr, "map_Kd ")) {
				current_addr += 7; return oi::STM_MTL::map_Kd;
			}
			if (compare_str(current_addr, "map_Ks ")) {
				current_addr += 7; return oi::STM_MTL::map_Ks;
			}
			if (compare_str(current_addr, "map_Ns ")) {
				current_addr += 7; return oi::STM_MTL::map_Ns;
			}
			if (compare_str(current_addr, "disp ")) {
				current_addr += 5; return oi::STM_MTL::disp;
			}
			if (compare_str(current_addr, "decal ")) {
				current_addr += 6; return oi::STM_MTL::decal;
			}
			if (compare_str(current_addr, "map_bump ")) {
				current_addr += 9; return oi::STM_MTL::map_bump;
			}
			if (compare_str(current_addr, "bump ")) {
				current_addr += 5; return oi::STM_MTL::map_bump;
			}

			return oi::STM_MTL::None;
		}

	}
}