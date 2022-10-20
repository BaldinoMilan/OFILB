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


std::ostream& operator<<(std::ostream& stream, const oi::mat3& mat)
{
	stream << mat[0][0] << " " << mat[0][1] << " " << mat[0][2] << std::endl << mat[1][0] << " " << mat[1][1] << " " << mat[1][2] << std::endl << mat[2][0] << " " << mat[2][1] << " " << mat[2][2];
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const oi::mat2& mat)
{
	stream << mat[0][0] << " " << mat[0][1] << std::endl << mat[1][0] << " " << mat[1][1];
	return stream;
}


int main()
{

}