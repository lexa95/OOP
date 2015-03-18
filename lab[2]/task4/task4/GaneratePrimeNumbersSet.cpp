#include "stdafx.h"
#include "GaneratePrimeNumbersSet.h"

void DeleteMultiplesOfTheNumber(std::set<int> & setNumbers, int upperBound, int number)
{
	for (int i = number * 2; i <= upperBound; i += number)
	{
		setNumbers.erase(i);
	}
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> result;
	std::set<int>::iterator it;

	for (int i = 2; i <= upperBound; i++)
	{
		result.insert(i);
	}

	for (it = result.begin(); it != result.end(); ++it)
	{
		DeleteMultiplesOfTheNumber(result, upperBound, *it);
	}

	return result;
}