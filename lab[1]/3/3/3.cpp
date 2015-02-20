#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

std::vector<std::vector<double>> ReadFromFile(FILE *F)
{
	int i = 0;
	std::string val = "";
	bool err;
	std::vector<std::vector<double>> matrix;
	int ch;
	while ((ch = fgetc(F)) != EOF)
	{
		if (ch == '\n')
		{
			matrix[i].push_back(StringToDouble(val.c_str(), err));
			std::cout << val << std::endl;
			val = "";
			i++;
			continue;
		}
		if (ch == '\t')
		{
			matrix[i].push_back(StringToDouble(val.c_str(), err));
			std::cout << val;
			val = "";
			continue;
		}
		val += ch;
	}
	return matrix;
}

void PrintMatrix(std::vector<std::vector<double>> matrix)
{
	for (int i(0); i < 3; i++)
	{
		for (int j(0); i < 3; j++)
		{
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	
	if (argc != 2)
	{
		std::cout << "Неверное кол-во параметров." << std::endl;
		_getch();
		return -1;
	}

	FILE *inFile = fopen(argv[1], "r");
	if (inFile == NULL)
	{
		printf("File opening error\n");
		return 1;
	}
	std::vector<std::vector<double>> matrix;
	matrix = ReadFromFile(inFile);	fclose(inFile);
	//PrintMatrix(matrix);

	_getch();
	return 0;
}

