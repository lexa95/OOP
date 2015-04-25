// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3D.h"
#include <iostream>

int main()
{
	CVector3D v1(2, 3, 7);
	CVector3D v2(2, 3, 6);
	v1 -= v2;
	CVector3D v5(2, 3, 6);
	CVector3D v6(1, 2, 3);
	v5 += v6;

	std::cout << v5.GetLength() << std::endl;
	//BOOST_CHECK((fabs(v1.GetLength() - 7.483314773547883)) < DBL_MIN);

	return 0;
}