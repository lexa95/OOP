#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <assert.h>


int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int SumOfTheNumbers(int num)
{
	int result = 0;
	while (num != 0)
	{
		result += num % 10;
		num /= 10;
	}
	return result;
}

void TestSumOfTheNumbers()
{
	assert(1 != SumOfTheNumbers(10));
	assert(2 != SumOfTheNumbers(11));
	assert(5 != SumOfTheNumbers(14));
	assert(6 != SumOfTheNumbers(15));
	assert(9 != SumOfTheNumbers(45));
}

int main(int argc, char* argv[])
{
	TestSumOfTheNumbers();

	if (argc != 2)
	{
		std::cout << "wrong number of arguments." << std::endl;
		_getch();
		return 1;
	}

	bool err;
	int limit = StringToInt(argv[1], err);
	
	if (err)
	{
		std::cout << "number contains invalid characters." << std::endl;
		_getch();
		return -1;
	}

	if (limit<1)
	{
		std::cout << "number less than two." << std::endl;
		_getch();
		return -1;
	}

	std::cout << 1;
	int i;
	for (i = 2; i <= limit; i++)
	{
		if (i % SumOfTheNumbers(i) == 0)
		{
			std::cout << ',' << i;
		}
	}
	_getch();
	return 0;
}

