#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

std::vector<double>AddNumber()
{
	std::vector<double> result;
	std::string num;
	do
	{
		std::cout << "Enter number: ";
		std::cin >> num;
		if (!strcmp(num.c_str(), "*"))
		{
			return result;
		}

		bool err;
		double value = StringToDouble(num.c_str(), err);
		if (err)
		{
			std::cout << "Incorrect number.";
		}
		else
		{
			result.push_back(value);
		}
	} while (1);
}

double MinimumElement(const std::vector<double> arr)
{
	double result = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (result > arr[i])
		{
			result = arr[i];
		}
	}
	return result;
}

void MultiplyArray(std::vector<double> & arr, double num)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] *= num;
	}
}

void SortArray(std::vector<double> & arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		double value;
		double num = arr[i];
		int index = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (num > arr[j])
			{
				num = arr[j];
				index = j;
			}
		}
		value = arr[i];
		arr[i] = num;
		arr[index] = value;
	}
}

void PrintArr(const std::vector<double> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}

int main(int argc, char* argv[])
{
	std::vector<double> arr = AddNumber();
	if (arr.size() == 0)
	{
		return 0;
	}
	double min = MinimumElement(arr);
	MultiplyArray(arr, min);
	SortArray(arr);
	PrintArr(arr);

	_getch();
	return 0;
}

