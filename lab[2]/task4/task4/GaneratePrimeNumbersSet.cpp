#include "stdafx.h"
#include "GaneratePrimeNumbersSet.h"

void DeleteMultiplesOfTheNumber(std::vector<bool> & isSkip, const int upperBound, const int number)
{
	if (long long int(number) * number < INT_MAX)
	{
		for (int i = (number * number); i <= upperBound; i += number)
		{
			isSkip[i] = false;
		}
	}
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> result;
	std::vector<bool> isSkip;
	std::vector<int> allNumbers;

	for (int i = 1; i <= upperBound + 1; i++)
	{
		allNumbers.push_back(i);
		isSkip.push_back(true);
	}

	for (int i = 2; i <= upperBound + 1; i++)
	{
		if (isSkip[i])
		{
			result.insert(i);
			DeleteMultiplesOfTheNumber(isSkip, upperBound, i);
		}
	}
	return result;
}