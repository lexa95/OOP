#include "stdafx.h"
#include "../task2/CMyArray.h"
#include <iostream>
#include <stdexcept>
#include <string>

BOOST_AUTO_TEST_CASE(TestAdd)
{
	CMyArray<int> arr;
	arr.Add(1);
	arr.Add(2);
	BOOST_CHECK(arr.Size() == 2);

	try
	{
		BOOST_CHECK(arr[0] == 1);
	}
	catch (std::out_of_range const&)
	{
		BOOST_CHECK(false);
	}
}

BOOST_AUTO_TEST_CASE(TestOperator)
{
	CMyArray<int> arr;
	arr.Add(1);
	arr.Add(2);

	arr[0] = 3;
	arr[1] = 4;

	BOOST_CHECK(arr.Size() == 2);
	BOOST_CHECK(arr[0] == 3);
	BOOST_CHECK(arr[1] == 4);
}

BOOST_AUTO_TEST_CASE(TestOutOfRange)
{
	CMyArray<int> arr;
	arr.Add(1);
	arr.Add(2);

	bool isError = false;
	try
	{
		BOOST_CHECK(arr[5] == 3);
	}
	catch (std::out_of_range const&)
	{
		isError = true;
	}
	BOOST_CHECK(isError);
}

BOOST_AUTO_TEST_CASE(TestResize)
{
	CMyArray<int> arr;
	arr.Add(1);
	arr.Add(2);

	arr.Resize(3);
	BOOST_CHECK(arr[0] == 1);
	BOOST_CHECK(arr[1] == 2);
	BOOST_CHECK(arr[2] == 0);

	arr.Resize(1);
	BOOST_CHECK(arr.Size() == 1);
	BOOST_CHECK(arr[0] == 1);

	bool isError = false;
	try
	{
		arr[2];
	}
	catch (std::out_of_range const&)
	{
		isError = true;
	}
	BOOST_CHECK(isError);
}

BOOST_AUTO_TEST_CASE(TestInt)
{
	CMyArray<int> arr;
	arr.Resize(3);
	BOOST_CHECK(arr.Size() == 3);

	BOOST_CHECK(arr[0] == 0);
	BOOST_CHECK(arr[1] == 0);
	BOOST_CHECK(arr[2] == 0);

}

BOOST_AUTO_TEST_CASE(TestFloat)
{
	CMyArray<float> arr;
	arr.Resize(3);
	BOOST_CHECK(arr.Size() == 3);

	BOOST_CHECK(arr[0] == 0);
	BOOST_CHECK(arr[1] == 0);
	BOOST_CHECK(arr[2] == 0);
}

BOOST_AUTO_TEST_CASE(TestString)
{
	CMyArray<std::string> arr;
	arr.Resize(3);
	BOOST_CHECK(arr.Size() == 3);

	arr[0] = "111";
	BOOST_CHECK(arr[0] == "111");
	BOOST_CHECK(arr[1] == "");
	BOOST_CHECK(arr[2] == "");
}