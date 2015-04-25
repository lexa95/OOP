// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Complex.h"

int main(int argc, char* argv[])
{
	CComplex num(-9, -22);
	std::cin >> num;
	std::cout << num << std::endl;
	return 0;
}

