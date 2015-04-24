#include "stdafx.h"
#include "..\task1\Complex.h"
#include <iostream>


BOOST_AUTO_TEST_CASE(CheckTheAdditionOperator)
{
	CComplex num1(rand(), rand());
	CComplex num2(rand(), rand());

	CComplex num3 = num1 + num2;
	BOOST_CHECK(num3.GetX() == num1.GetX() + num2.GetX());
	BOOST_CHECK(num3.GetY() == num1.GetY() + num2.GetY());
}