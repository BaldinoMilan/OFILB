/*
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file type_matrix.h
*/

#pragma once
#ifndef TYPE_MATRIX_OFILB
#define TYPE_MATRIX_OFILB

#include "ofilb/matrix2x2.h"
#include "ofilb/matrix3x3.h"
#include "ofilb/matrix4x4.h"

namespace oi 
{
	// tmat2
	typedef tmat2<float> mat2;
	typedef tmat2<double> dmat2;
	typedef tmat2<int> imat2;
	typedef tmat2<unsigned int> uimat2;

	// tmat3
	typedef tmat3<float> mat3;
	typedef tmat3<double> dmat3;
	typedef tmat3<int> imat3;
	typedef tmat3<unsigned int> uimat3;

	// tmat4
	typedef tmat4<float> mat4;
	typedef tmat4<double> dmat4;
	typedef tmat4<int> imat4;
	typedef tmat4<unsigned int> uimat4;

}

#endif