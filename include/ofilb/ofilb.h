/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file ofilb.h
*/

#pragma once
#include "ofilb/type_vec.h" 
#include "ofilb/type_matrix.h"
#include "ofilb/parse.h"


#ifndef OFILB
#define OFILB

namespace oi 
{
	void import_file(const char* path);
	
	void process_line(const char*& ptr);
	STATEMENT check_statement(const char* _ptr);
	void process_statement(const char*& ptr, STATEMENT state);

} // namespace oi

#endif // OFILB