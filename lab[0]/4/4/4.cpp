// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <assert.h>

using namespace std;

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

bool IsArithmeticOperation(const char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*';
}

double ApplyOperation(double num1, double num2, const char operations, bool & err)
{
	err = false;
	switch (operations)
	{
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '/': if (num2 != 0) return num1 / num2; else  err = true;
		case '*': return num1 * num2;
		default: assert(0);
	}
	return 0;
}

double EvaluateExpression(const char* Expression[], int count, bool & error)
{
	double result = 0;
	double num = 0;
	bool err;
	for (int i = 1; i < count; i += 2)
	{
		if (i == 1)
		{
			result = StringToDouble(Expression[i], err);
		}
		else
		{
			num = StringToDouble(Expression[i], err);

			if (!IsArithmeticOperation(*Expression[i - 1]))
			{
				error = true;
				return 0;
			}
			result = ApplyOperation(result, num, *Expression[i - 1], err);
			if (err)
			{
				error = true;
				return 3;
			}
		}
		if (err)
		{
			error = true;
			return 1;
		}
	}
	error = false;
	return result;
}

void PrintArithmeticExpression(int count, const char* Expression[])
{
	for (int i = 1; i < count; i++)
	{
		cout << Expression[i] << ' ';
	}
}

int main(int argc, const char* argv[])
{

	if (argc <= 1)
	{
		printf("Program calculates sum of its command line arguments.\n");
		return 1;
	}

	bool err;
	double result = EvaluateExpression(argv, argc, err);
	
	if (err)
	{
		switch (int(result))
		{
		case 0: cout << "operator error"; return 1;
		case 1: cout << "error number"; return 1;
		case 2: cout << "division by zero error"; return 1;
		}
	}
	
	PrintArithmeticExpression(argc, argv);
	printf("= %.3f", result);

	return 0;
}