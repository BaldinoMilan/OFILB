/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file type_vec.h
*/

#pragma once
#ifndef TYPE_VECTOR_OFILB
#define TYPE_VECTOR_OFILB 

#include "ofilb/vec2.h"
#include "ofilb/vec3.h"
#include "ofilb/vec4.h"

namespace oi
{
	// tvec2 
	typedef tvec2<float> vec2;
	typedef tvec2<double> dvec2;
	typedef tvec2<int> ivec2;
	typedef tvec2<unsigned int> uivec2;

	// tvec3
	typedef tvec3<float> vec3;
	typedef tvec3<double> dvec3;
	typedef tvec3<int> ivec3;
	typedef tvec3<unsigned int> uivec3;

	// tvec4
	typedef tvec4<float> vec4;
	typedef tvec4<double> dvec4;
	typedef tvec4<int> ivec4;
	typedef tvec4<unsigned int> uivec4;
} // namespace oi

#endif // TYPE VECTOR OFILB