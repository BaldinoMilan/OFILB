/* 
--------------------------------------------------
Obj Format Import Library (OFILB)
--------------------------------------------------

*/
/* @file main.cpp
*/

#include <iostream>
#include <ofilb/ofilb.h>

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

std::ostream& operator<<(std::ostream& stream, const oi::mat4& mat)
{
	stream << mat[0][0] << " " << mat[0][1] << " " << mat[0][2] << " " << mat[0][3] << std::endl <<
			  mat[1][0] << " " << mat[1][1] << " " << mat[1][2] << " " << mat[1][3] << std::endl <<
			  mat[2][0] << " " << mat[2][1] << " " << mat[2][2] << " " << mat[2][3] << std::endl <<
			  mat[3][0] << " " << mat[3][1] << " " << mat[3][2] << " " << mat[3][3] << std::endl;
	
	return stream;
}


int main()
{
	oi::vec4 v;
}