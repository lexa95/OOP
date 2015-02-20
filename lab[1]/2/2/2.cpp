#include "stdafx.h"
#include <conio.h>
#include <iostream>

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

unsigned char RevByte(unsigned char x)
{
	x = (x & 0x55) << 1 | (x >> 1) & 0x55;
	x = (x & 0x33) << 2 | (x >> 2) & 0x33;
	x = (x & 0x0F) << 4 | (x >> 4) & 0x0F;
	return x;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of parameters." << std::endl;
		_getch();
		return 1;
	}
	bool err;

	int num = StringToInt(argv[1], err);
	if (err)
	{
		std::cout << "Incorrect number." << std::endl;
		_getch();
		return 1;
	}

	if (num < 0 || num > 255)
	{
		std::cout << "Number must be from 0 to 255." << std::endl;
		_getch();
		return 1;
	}
	unsigned char val = num;

	std::cout << int(RevByte(val)) << std::endl;
	_getch();
	return 0;
}

