#include "stdafx.h"
#include "../task1/FindMax.h"

BOOST_AUTO_TEST_CASE(TestVectorInt)
{
	vector<int> array = { 1, 2, 10, 4, 8, 1 };
	int number;
	BOOST_CHECK(FindMax(array, number));
	BOOST_CHECK(number == 10);
}

BOOST_AUTO_TEST_CASE(TestVectorString)
{
	vector<string> array = { "1.1", "2.3", "10.23", "4.12", "82.1", "82.2" };
	string value;
	BOOST_CHECK(FindMax(array, value));
	BOOST_CHECK(value == "82.2");
}

BOOST_AUTO_TEST_CASE(TestVectorCharArray)
{
	vector<char *> array = { "1.1", "2.3", "10.23", "4.12", "82.1", "82.2" };
	char * value;
	BOOST_CHECK(FindMax(array, value));
	BOOST_CHECK(!strcmp(value,"82.2"));
}