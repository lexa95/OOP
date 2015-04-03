#include "stdafx.h"
#include "GaneratePrimeNumbersSet.h"


void DeleteMultiplesOfTheNumber(std::vector<bool> & isSkip, const int upperBound, const int number)
{
	if (long long int(number) * number < INT_MAX)
	{
		for (int i = (number * number); i <= upperBound; i += number)
		{
			isSkip[i - 2] = false;
		}
	}
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> result;
	std::vector<bool> isSkip;
	isSkip.reserve(upperBound);

	if (upperBound < 2)
	{
		return result;
	}

	isSkip.push_back(true);
	for (int i = 3; i <= upperBound; i += 2)
	{
		isSkip.push_back(true);
		isSkip.push_back(false);
	}

	result.insert(2);
	for (int i = 3; i <= upperBound; i++)
	{
		if (isSkip[i - 2])
		{
			result.insert(i);
			DeleteMultiplesOfTheNumber(isSkip, upperBound, i);
		}
	}
	return result;
}