#include "stdafx.h"
#include "ReadFromFile.h"

using namespace std;

void PrintSet(const set<string> datebase)
{
	for (auto it = datebase.begin(); it != datebase.end(); ++it) 
	{
		cout << *it << endl;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc <= 1)
	{
		std::cout << "Wrong number of parameters.\n";
		return -1;
	}

	set<string> datebase;
	for (int i = 1; i < argc; i++)
	{
		ReadFromFile(datebase, argv[i], AddNameToSet);
		if (!ReadFromFile(datebase, argv[i], AddNameToSet))
		{
			return -1;
		}
	}


	PrintSet(datebase);
	return 0;
}

