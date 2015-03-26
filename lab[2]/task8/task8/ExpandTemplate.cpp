#include "stdafx.h"
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

size_t Prefix(string const& searchString, size_t count)
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

string KMP(string const& line, string const& searchString, string const& replacementString, vector<bool> & isReplacement)
{
	string result;
	vector<bool> resultIsReplacement;

	size_t lenLine = line.size();
	size_t lenSearchString = searchString.size();
	size_t i = 0;
	size_t j = 0;

	while (i < lenLine)
	{
		if (isReplacement[i])
		{
			if (j != 0)
			{
				for (size_t index = i - j; index < j; index++)
				{
					result += line[index];
					resultIsReplacement.push_back(isReplacement[i]);
				}
				j = 0;
			}
			else
			{
				resultIsReplacement.push_back(isReplacement[i]);
				result += line[i];
			}
			i++;
		}
		else if (line[i] == searchString[j])
		{
			j++;
			i++;
			if (j == lenSearchString)
			{
				result += replacementString;
				for (size_t index = 0; index < replacementString.size(); index++) resultIsReplacement.push_back(true);
				j = 0;
			}
		}
		else
		{
			if (j == 0)
			{
				resultIsReplacement.push_back(isReplacement[i]);
				result += line[i];
				i++;
			}
			else
			{
				size_t pre = Prefix(searchString, j);
				for (size_t index = i - j; index <= i - j - pre; index++)
				{
					result += line[index];
					resultIsReplacement.push_back(isReplacement[i]);
				}
				j = pre;
			}
		}
	}
	isReplacement = resultIsReplacement;
	return result;
}

string ExpandTemplate(string tpl, map<string, string> params)
{
	string result = tpl;
	vector<bool> isReplacement(tpl.size());
	size_t count = params.size();

	for (int i = 0; i < count; i++)
	{
		map<string, string>::iterator more = params.begin();
		for (map<string, string>::iterator it = params.begin(); it != params.end(); it++)
		{
			if (it->first.size() > more->first.size())
			{
				more = it;
			}
		}
		result = KMP(result, more->first, more->second, isReplacement);
		params.erase(more);
	}
	return result;
}