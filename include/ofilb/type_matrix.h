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

namespace oi 
{
	// tmat2
	typedef tmat2<float> mat2;
	typedef tmat2<double> dmat2;
	typedef tmat2<int> imat2;
	typedef tmat2<unsigned int> uimat2;

}

#endif