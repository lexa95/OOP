#include "stdafx.h"
#include "../task2/Vector3D.h"

BOOST_AUTO_TEST_CASE(CheckUnaryMinusAndPlus)
{
	CVector3D vector1(1, 2, 3);
	CVector3D vector2(-1, -2, -3);
	BOOST_CHECK((-vector1) == vector2);
	BOOST_CHECK((+vector1) == vector1);
}

BOOST_AUTO_TEST_CASE(TestComparisonOperators)
{
	CVector3D vector1(4, 4, 4);
	CVector3D vector2(4, 4, 4);
	BOOST_CHECK(vector1 == vector2);
	BOOST_CHECK(!(vector1 != vector2));

	CVector3D vector3(1, 2, 3);
	BOOST_CHECK(!(vector1 == vector3));
	BOOST_CHECK(vector1   != vector3);
}