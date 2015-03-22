#include "../task7/ReadFromFile.h"
#include "stdafx.h"

using namespace std;

void AddNameToSet(set<string> & database, string name)
{
	database.insert(name);
}

bool ReadFromFile(set<string> & database, string fileName, void(*ProcessLine)(set<string> & database, string name))
{
	ifstream pFile(fileName);

	if (!pFile.is_open())
	{
		cout << "Could not open file.";
		return false;
	}

	string line;
	while (!pFile.eof())
	{
		getline(pFile, line);
		if (line != "")
		{
			ProcessLine(database, line);
		}
	}
	
	pFile.close();
	return true;
}