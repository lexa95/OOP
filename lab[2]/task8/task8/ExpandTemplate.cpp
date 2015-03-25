#include "stdafx.h"
#include <algorithm>
#include "ExpandTemplate.h"

using namespace std;

int ToUpper(const int ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (int)(ch - ('a' - 'A'));
	}

	if (ch >= 224 && ch <= 255)
	{
		return (int)(ch - ('à' - 'À'));
	}
	return ch;
}

std::string	UpperCase(const std::string word)
{
	std::string result;
	size_t count = strlen(word.c_str());

	for (size_t i = 0; i < count; i++)
	{
		result += ToUpper(word[i]);
	}
	return result;
}

size_t CheckForOccurrence(const char *searchString, size_t count)
{
	for (size_t i = 1; i < count; i++)
	{
		for (size_t j = i; j <= count; j++)
		{
			if (j == count) return j - i;
			if (!(searchString[j] == searchString[j - i]))
			{
				break;
			}
		}
	}
	return 0;
}

vector<size_t> Prefix(const char *line)
{
	vector<size_t> kmpArray;
	size_t count = strlen(line);
	for (size_t i = 0; i < count; ++i)
	{
		kmpArray.push_back(CheckForOccurrence(line, i + 1));
	}
	return kmpArray;
}

string Kmp(string line, string searchString, string replaceString)
{
	vector<size_t> prefix = Prefix(searchString.c_str());
	size_t count = strlen(line.c_str());
	size_t lenSearchString = strlen(searchString.c_str());
	string result = "";

	size_t j = 0;
	for (size_t i = 0; i < count; i++)
	{
		if (ToUpper(line[i]) != ToUpper(searchString[j]))
		{
			if (j != 0)
			{
				size_t len = j;
				j = prefix[j - 1];
				cout << searchString.substr(0, len - j);
				if (ToUpper(line[i]) == ToUpper(searchString[j]))
				{
					j++;
				}
				else
				{
					cout << line[i];
					j = 0;
				}
			}
			else
			{
				cout << line[i];
				j = 0;
			}
		}
		else
		{
			j++;
			if (lenSearchString == j)
			{
				cout << replaceString;
				j = 0;
			}
		}
	}
	return result;
}

string ExpandTemplate(string const& tpl, map<string, string> params)
{
	string result = tpl;

	for (auto it = params.begin(); it != params.end(); it++)
	{
		result = Kmp(result, it->first, it->second);
	}

	return result;
}