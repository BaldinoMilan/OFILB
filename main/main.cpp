/* 
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file main.cpp
*/

#include <iostream>
#include <ofilb/type_vec.h>
#include <ofilb/type_matrix.h>

int main()
{
	oi::mat2 matrix(1.0f, 2.0f, 
					3.0f, 4.0f);
	matrix = matrix * oi::inverse(matrix);

	std::cout << oi::value_ptr<float>(matrix) << " " << *oi::value_ptr<float>(matrix) << std::endl;
	std::cout << matrix[0][0] << " " << matrix[0][1] << std::endl << matrix[1][0] << " " << matrix[1][1] << std::endl;
}