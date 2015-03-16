// task1Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/ProcessVectors.h"

using namespace std;

BOOST_AUTO_TEST_CASE(EmptyVectorProducesEmptyVector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}


BOOST_AUTO_TEST_CASE(VectorWithoutPositivesDoesntChangeContent)
{
	vector<double> numbers = { -4, 0, -3 };
	auto copy(numbers);
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}

BOOST_AUTO_TEST_CASE(checkingResult1)
{
	vector<double> numbers = ProcessVector({ 4, 0, 3 });
	vector<double> result = { 0, 0, 0 };
	BOOST_CHECK(numbers == result);
}

BOOST_AUTO_TEST_CASE(checkingResult2)
{
	vector<double> numbers = ProcessVector({ 4, 1, 3 });
	vector<double> result = { 1, 3, 4 };
	BOOST_CHECK(numbers == result);
}

BOOST_AUTO_TEST_CASE(checkingResult3)
{
	vector<double> numbers = ProcessVector({ 4, 2, 3 });
	vector<double> result = { 4, 6, 8 };
	BOOST_CHECK(numbers == result);
}

