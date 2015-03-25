// Automatic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((str == '\0') || (pLastChar != '\0'));
	return param;
}



std::string GetStringToSubstring(std::string const& line, std::string const& substring)
{
	std::string result = "";

	size_t lenLine = strlen(line.c_str());
	size_t lenSubstring = strlen(substring.c_str());

	for (size_t i = 0; i < lenLine; i++)
	{
		if (line.substr(i, lenSubstring) == substring)
		{
			return result;
		}
		else
		{
			result += line[i];
		}
	}
	return result;
}

void ConvertToMrOfMl(vector<vector<string>> const & datebase, vector<vector<string>> & result)
{

}

void ConvertToMlOfMr(vector<vector<string>> const & datebase, vector<vector<string>> & result)
{
	vector<string> vetrix;

	for (int i = 0; i < datebase.size(); i++)
	{
		for (int j = 0; j < datebase[i].size(); j++)
		{
			if ()
			{}
		}
	}
}

bool CreateNewcreAteautomatic(vector<vector<string>> const & datebase, vector<vector<string>> & result, string const & key)
{
	if (key == "<ML>")
	{
		ConvertToMlOfMr(datebase, result);
		return true;
	}
	else if (key == "<MR>")
	{
		ConvertToMrOfMl(datebase, result);
		return true;
	}
	else
	{
		return false;
	}

}

bool ReadFromFile(vector<vector<string>> & datebase, string nameFile, string & key)
{
	string line;
	string num;

	ifstream pFile(nameFile);
	if (!pFile.is_open())
	{
		return false;
	}

	int inputSymbol, outputSymbol, vertix;
	bool err;
	
	getline(pFile, line);
	num = GetStringToSubstring(line, ",");
	inputSymbol = StringToInt(num.c_str(), err);
	
	line = line.substr(strlen(num.c_str()) + 1);
	num = GetStringToSubstring(line, ",");
	outputSymbol = StringToInt(num.c_str(), err);

	line = line.substr(strlen(num.c_str()) + 1);
	vertix = StringToInt(line.c_str(), err);

	getline(pFile, key);

	while (!pFile.eof())
	{
		vector<string> date;
		getline(pFile, line);
		line += ",";

		while (!line.empty())
		{
			string val;
			val = GetStringToSubstring(line, ",");
			date.push_back(val);
			line = line.substr(strlen(val.c_str()) + 1);
		}
		datebase.push_back(date);
	}

	pFile.close();
	return true;
}

int main(int argc, char* argv[])
{
	vector<vector<string>> datebase;
	string key;

	ReadFromFile(datebase, "inputMl.txt", key);

	system("PAUSE");
	return 0;
}

