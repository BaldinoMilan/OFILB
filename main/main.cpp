/* 
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file main.cpp
*/

#include <iostream>
#include <ofilb/type_vec.h>
#include <ofilb/matrix2x2.h>

int main()
{
	oi::tmat2<float> matrix(0.1f, 0.2f, 0.3f, 0.4f);
	matrix = 2.0f - matrix;
	std::cout << matrix[0][0] << " " << matrix[0][1] << std::endl << matrix[1][0] << " " << matrix[1][1] << std::endl;
}