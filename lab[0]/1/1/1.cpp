// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	for (i = 100; i > 2; i = i - 2)
	{
		std::cout << i << ',';
	}
	std::cout << i ;

	_getch();
	return 0;
}

