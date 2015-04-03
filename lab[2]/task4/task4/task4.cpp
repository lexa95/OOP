// task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GaneratePrimeNumbersSet.h"
#include <ctime>

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

void PrintSet(std::set<int> & setNumbers)
{
	std::set<int>::iterator it;
	for (it = setNumbers.begin(); it != setNumbers.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");

	if (argc != 2)
	{
		std::cout << "Должен быть один параметр." << std::endl;
		return 1;
	}
	
	bool err;
	int upperBound = StringToInt(argv[1], err);
	if (err)
	{
		std::cout << "Не верный параметр." << std::endl;
		return 1;
	}
	
	if (upperBound <= 1 || upperBound > 100000000)
	{
		std::cout << "Число должно быть меньше 100 000 000 и больше 1." << std::endl;
		return 1;
	}

	std::set<int> datebase;
	unsigned int start_time = clock();
	datebase = GeneratePrimeNumbersSet(upperBound);
	unsigned int end_time = clock();
	//std::cout << end_time - start_time << std::endl;
	//system("PAUSE");
	PrintSet(datebase);
	
	
	system("PAUSE");
	return 0;
}

