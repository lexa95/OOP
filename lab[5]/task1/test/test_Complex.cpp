#include "stdafx.h"
#include "..\task1\Complex.h"
#include <iostream>


BOOST_AUTO_TEST_CASE(CheckTheAdditionOperator)
{
	CComplex num1(rand(), rand());
	CComplex num2(rand(), rand());

	CComplex num3 = num1 + num2;
	BOOST_CHECK(num3.Re() == num1.Re() + num2.Re());
	BOOST_CHECK(num3.Im() == num1.Im() + num2.Im());
	
	CComplex num4 = num2 + 2;
	BOOST_CHECK(num4.Re() == num2.Re() + 2);
	BOOST_CHECK(num4.Im() == num2.Im());
}