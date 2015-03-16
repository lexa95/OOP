#include "ProcessVectors.h"
#include "stdafx.h"

std::vector<double> MultiplyArrayOnNumber(const std::vector<double> numbers, const double minValue)
{
	std::vector<double> result;
	for (auto number : numbers)
	{
		result.push_back(minValue * number);
	}
	return result;
}

std::vector<double> ProcessVector(std::vector<double>  numbers)
{
	if (!numbers.empty())
	{
		auto it = min_element(numbers.begin(), numbers.end());
		double minValue = *it;
		stable_sort(numbers.begin(), numbers.end());
		return MultiplyArrayOnNumber(numbers, minValue);
	}
	else
	{
		return numbers;
	}
}
