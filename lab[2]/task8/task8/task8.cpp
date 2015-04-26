#include "stdafx.h"
#include "ExpandTemplate.h"

using namespace std;

bool WriteFromFileInFile(const char * nameInputFile, const char * nameOutputFile,
	const map<string, string> params, string(*Process)(string tpl, map<string, string> params))
{
	ifstream inputFile(nameInputFile);
	if (!inputFile.is_open())
	{
		printf("File opening error\n");
		return false;
	}

	ofstream outputFile(nameOutputFile);
	if (!outputFile.is_open())
	{
		printf("File opening error\n");
		inputFile.close();
		return false;
	}

	string line;
	while (!inputFile.eof())
	{
		getline(inputFile, line);
		outputFile << Process(line, params);
		outputFile << "\n";
	}

	inputFile.close();
	outputFile.close();
	return true;
}

map<string, string> CreateMap(int count, char* argv[])
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
	if (argc % 2 == 0 || argc < 3)
	{
		cout << "Не верное кол-во параметров." << endl;
		return 1;
	}

	map<string, string> params = CreateMap(argc, argv);
	
	if (!WriteFromFileInFile(argv[1], argv[2], params, ExpandTemplate))
	{
		return -1;
	}

	return 0;
}