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
	
	num3 = 2 + num2;
	BOOST_CHECK(num3.Re() == num2.Re() + 2);
	BOOST_CHECK(num3.Im() == num2.Im());

	num4 = +num3;
	BOOST_CHECK(num4.Re() == num3.Re());
	BOOST_CHECK(num4.Im() == num3.Im());
}

BOOST_AUTO_TEST_CASE(CheckTheSubtractionOperator)
{
	CComplex num1(rand(), rand());
	CComplex num2(rand(), rand());

	CComplex num3 = num1 - num2;
	BOOST_CHECK(num3.Re() == num1.Re() - num2.Re());
	BOOST_CHECK(num3.Im() == num1.Im() - num2.Im());

	CComplex num4 = num2 - 2;
	BOOST_CHECK(num4.Re() == num2.Re() - 2);
	BOOST_CHECK(num4.Im() == num2.Im());

	num3 = 2 - num2;
	BOOST_CHECK(num3.Re() == 2 - num2.Re());
	BOOST_CHECK(num3.Im() == - num2.Im());

	num4 = -num3;
	BOOST_CHECK(num4.Re() == - num3.Re());
	BOOST_CHECK(num4.Im() == - num3.Im());
}

BOOST_AUTO_TEST_CASE(CheckTheMultiplicationOperator)
{
	CComplex num1(5, 3);
	CComplex num2(4, 7);

	CComplex num3 = num1 * num2;
	BOOST_CHECK(num3.Re() == -1);
	BOOST_CHECK(num3.Im() == 47);

	CComplex num4 = num1 * 2;
	BOOST_CHECK(num4.Re() == 10);
	BOOST_CHECK(num4.Im() == 6);

	num3 = 2 * num1;
	BOOST_CHECK(num3.Re() == num4.Re());
	BOOST_CHECK(num3.Im() == num4.Im());
}

BOOST_AUTO_TEST_CASE(CheckTheDivisionOperator)
{
	CComplex num1(7, -4);
	CComplex num2(3,  2);

	CComplex num3 = num1 / num2;
	BOOST_CHECK(num3.Re() == 1);
	BOOST_CHECK(num3.Im() == -2);

	CComplex num5(8, -4);
	CComplex num4 = num5 / 2;
	BOOST_CHECK(num4.Re() == 4);
	BOOST_CHECK(num4.Im() == -2);
}