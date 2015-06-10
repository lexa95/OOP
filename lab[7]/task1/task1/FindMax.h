#pragma once

#include "stdafx.h"
using namespace std;

bool IsLess(const char* value1, const char* value2)
{
	int countIt = min(strlen(value1), strlen(value2));

	for (int i = 0; i < countIt; i++)
	{
		if (value1[i] == value2[i])
		{
			continue;
		}
		return value1[i] < value2[i];
	}
	return countIt == strlen(value1);
}

template < typename T >
bool FindMax(std::vector<T> const& arr, T& maxValue)
{
	if (arr.size() != 0)
	{
		maxValue = arr[0];
		for (size_t i = 1; i < arr.size(); i++)
		{
			if (maxValue < arr[i])
			{
				maxValue = arr[i];
			}
		}
		return true;
	}
	return false;
}

template <>
bool FindMax<const char *>(std::vector<const char*> const& arr, const char* & maxValue)
{
	if (arr.size() != 0)
	{
		maxValue = arr[0];
		for (size_t i = 1; i < arr.size(); i++)
		{
			if (IsLess(maxValue, arr[i]))
			{
				maxValue = arr[i];
			}
		}
		return true;
	}
	return false;
}