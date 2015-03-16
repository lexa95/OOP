#include "stdafx.h"
#include "../task2/RemoveExtraSpaces.h"

BOOST_AUTO_TEST_CASE(Empty)
{
	std::string emptyLine;
	std::string result = RemoveExtraSpaces(emptyLine);
	BOOST_CHECK(emptyLine.empty());
}

BOOST_AUTO_TEST_CASE(TestResult1)
{
	std::string emptyLine = " 1  1";
	BOOST_CHECK(RemoveExtraSpaces(emptyLine) == "1 1");
}

BOOST_AUTO_TEST_CASE(TestResult2)
{
	std::string emptyLine = " 1  1 ";
	BOOST_CHECK(RemoveExtraSpaces(emptyLine) == "1 1");
}

BOOST_AUTO_TEST_CASE(TestResult3)
{
	std::string emptyLine = "test  t    est  t e s t        ";
	BOOST_CHECK(RemoveExtraSpaces(emptyLine) == "test t est t e s t");
}