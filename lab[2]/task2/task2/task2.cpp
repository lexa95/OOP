// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "RemoveExtraSpaces.h"

int main(int argc, char* argv[])
{
	while (!std::cin.eof())
	{
		std::string line;
		if (std::getline(std::cin, line))
		{
			if (line == "exit")
			{
				break;
			}
			line = RemoveExtraSpaces(line);
			std::cout << "Result: " << line << std::endl;
		}
		else
		{
			break;
		}
	}
	system("PAUSE");
	return 0;
}

