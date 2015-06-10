#include "stdafx.h"
#include "../task2/CMyArray.h"
#include <iostream>

BOOST_AUTO_TEST_CASE(TestInt)
{
	CMyArray<int> arr;
	arr.Add(1);
	arr.Add(2);
	BOOST_CHECK(arr.Size() == 2);
	try
	{
		BOOST_CHECK(arr[0] == 1);
	}
	catch (std::out_of_range e)
	{
		BOOST_CHECK(false);
	}
	//BOOST_CHECK(arr[0] == 1);
	//BOOST_CHECK(arr[1] == 2);
}

BOOST_AUTO_TEST_CASE(TestFloat)
{
	//BOOST_CHECK();
}

BOOST_AUTO_TEST_CASE(TestString)
{
	//BOOST_CHECK();
}