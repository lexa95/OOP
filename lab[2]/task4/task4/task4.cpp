// task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GaneratePrimeNumbersSet.h"

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
		std::cout << *it << ' ';
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");

	if (argc != 2)
	{
		std::cout << "������ ���� ���� ��������." << std::endl;
		return 1;
	}
	
	bool err;
	int upperBound = StringToInt(argv[1], err);
	if (err)
	{
		std::cout << "�� ����� ��������." << std::endl;
		return 1;
	}
	
	if (upperBound <= 1 || upperBound >= 100000)
	{
		std::cout << "����� ������ ���� ������ 100 000 � ������ 1." << std::endl;
		return 1;
	}

	PrintSet(GeneratePrimeNumbersSet(upperBound));

	system("PAUSE");
	return 0;
}

