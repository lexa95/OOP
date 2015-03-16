#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <boost/chrono.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << boost::chrono::steady_clock::now() << std::endl;
	_getch();
	return 0;
}