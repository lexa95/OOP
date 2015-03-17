#include "stdafx.h"
#include "../task3/OccurrenceOfWords.h"

BOOST_AUTO_TEST_CASE(Empty)
{
	std::map<std::string, int> arr;

	std::string line = "";
	AddToTheArray(line, arr);
	BOOST_CHECK(arr.empty());
}

BOOST_AUTO_TEST_CASE(CheckResult1)
{
	std::map<std::string, int> arr;
	std::map<std::string, int> result;
	
	std::string line = "Word word WORD DROW";
	AddToTheArray(line, arr);

	result["Word"] = 3;
	result["DROW"] = 1;
	BOOST_CHECK(result == arr);
}
BOOST_AUTO_TEST_CASE(CheckResult2)
{
	std::map<std::string, int> arr;
	std::map<std::string, int> result;

	std::string line = " CAt ";
	AddToTheArray(line, arr);

	result["CAt"] = 1;
	BOOST_CHECK(result == arr);
}
BOOST_AUTO_TEST_CASE(CheckResult3)
{
	std::map<std::string, int> arr;
	std::map<std::string, int> result;

	std::string line = "Hello Wold hello";
	AddToTheArray(line, arr);

	result["Hello"] = 2;
	result["Wold"] = 1;
	BOOST_CHECK(result == arr);
}
