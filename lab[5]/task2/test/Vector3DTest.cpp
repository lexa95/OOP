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

BOOST_AUTO_TEST_CASE(ByOperatorsOfBinaryAdditionAndSubtraction)
{
	CVector3D vector1(1, 2, 3);
	CVector3D vector2(3, 2, 1);
	CVector3D vector3(4, 4, 4);
	CVector3D vector4(2, 0, -2);
	BOOST_CHECK((vector1 + vector2) == vector3);
	BOOST_CHECK((vector2 - vector1) == vector4);
}

BOOST_AUTO_TEST_CASE(CheckIncreaseDecreaseLengthOfTheVector)
{
	CVector3D v1(1, 2, 3);
	CVector3D v2(1, 2, 3);
	v1 -= v2;

	BOOST_CHECK((fabs(v1.GetLength() - 0)) < DBL_MIN);

	CVector3D v3(1, 2, 3);
	CVector3D v4(1, 2, 3);
	v3 += v4;

	BOOST_CHECK((fabs(v3.GetLength() - 7.483314773547883)) < DBL_MIN);

	CVector3D v5(2, 3, 6);
	CVector3D v6(4, 1, 3);
	v5 += v6;
	
	BOOST_CHECK((fabs(v5.GetLength() - 12.0990195135927845)) < DBL_MIN);
}

BOOST_AUTO_TEST_CASE(MultipliesDividesVectorByScalar)
{
	CVector3D v(1, 2, 3);
	CVector3D v1(2, 4, 6);
	CVector3D v2(4, 8, 12);

	BOOST_CHECK((v * 2) == v1);
	BOOST_CHECK(((v * 2) * 2) == v2);
	BOOST_CHECK((((v * 2) * 2) / 2) == v1);
	BOOST_CHECK(((((v * 2) * 2) / 2) / 2) == v);
}