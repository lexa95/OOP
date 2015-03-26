#include "stdafx.h"
#include "ExpandTemplate.h"

using namespace std;

bool WriteFromFileInFile(const char * nameInputFile, const char * nameOutputFile,
	const map<string, string> params, string(*Process)(string tpl, map<string, string> params))
{
	ifstream pInputFile(nameInputFile);
	if (!pInputFile.is_open())
	{
		printf("File opening error\n");
		return true;
	}

	ofstream pOutputFile(nameOutputFile);
	if (!pOutputFile.is_open())
	{
		printf("File opening error\n");
		pInputFile.close();
		return true;
	}

	string line;
	while (!pInputFile.eof())
	{
		getline(pInputFile, line);
		pOutputFile << Process(line, params);
		pOutputFile << "\n";
	}

	pInputFile.close();
	pOutputFile.close();
	return false;
}

map<string, string> createMap(int count, char* argv[])
{
	map<string, string> result;
	for (int i = 3; i < count; i += 2)
	{
		result[argv[i]] = argv[i + 1];
	}
	return result;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc % 2 == 0 || argc < 3)
	{
		cout << "Не верное кол-во параметров." << endl;
		return 1;
	}

	map<string, string> params = createMap(argc, argv);
	
	if (WriteFromFileInFile(argv[1], argv[2], params, ExpandTemplate))
	{
		return -1;
	}

	system("PAUSE");
	return 0;
}