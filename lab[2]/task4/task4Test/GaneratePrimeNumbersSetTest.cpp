#include "stdafx.h"
#include "../task4/GaneratePrimeNumbersSet.h"

bool IsEqualSet(std::set<int> set1, std::set<int> set2)
{
	std::set<int>::iterator itSet1;
	std::set<int>::iterator itSet2;

	for (itSet1 = set1.begin(), itSet2 = set2.begin(); itSet1 != set1.end(); ++itSet1, ++itSet2)
	{
		if (*itSet1 != *itSet2)
		{
			return false;
		}
	}
	return true;
}

BOOST_AUTO_TEST_CASE(ChackResult1)
{
	std::set<int> result;
	result.insert(2);
	result.insert(3);
	BOOST_CHECK(result == GeneratePrimeNumbersSet(3));
}

BOOST_AUTO_TEST_CASE(ChackResult2)
{
	std::set<int> result;
	result.insert(2);
	result.insert(3);
	result.insert(5);
	result.insert(7);
	BOOST_CHECK(result == GeneratePrimeNumbersSet(10));
}

BOOST_AUTO_TEST_CASE(ChackEmplySet)
{
	BOOST_CHECK(GeneratePrimeNumbersSet(1).empty());
	BOOST_CHECK(GeneratePrimeNumbersSet(-1).empty());
	BOOST_CHECK(GeneratePrimeNumbersSet(0).empty());
}