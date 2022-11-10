/*
	--------------------------------------------------
			Obj Format Import Library (OFILB)
	--------------------------------------------------

*/
/* @file main.cpp
*/

#include <iostream>
#include <ofilb/ofilb.h>
#include "ofilb/mtl_file.h"

std::ostream& operator<<(std::ostream& os, const oi::vec3& v) {
	os << v.x << ' ' << v.y << ' ' << v.z;
	return os;
}

int main(int argc, char *argv[])
{
	int start = clock();
	std::vector<oi::Material> materials = oi::mtl_parser("RTX 3090.mtl", "demo/res/nvidia3090/source/RTX 3090.obj");
	int end = clock();

	printf("time: %.3f\n", (float)(end - start) / (float)CLOCKS_PER_SEC);
	
	return 0;
}