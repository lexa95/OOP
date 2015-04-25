#include "stdafx.h"
#include "RemoveExtraSpaces.h"

size_t SkipSymbol(const std::string line, size_t count, size_t i, char symbol)
{
	while (line[i] == symbol && i < count)
	{
		i++;
	}
	return i;
}
 
std::string MergeSymbol(std::string const & line, char symbol)
{
	std::string result = "";
	size_t count = strlen(line.c_str());
	
	size_t i = SkipSymbol(line, count, 0, symbol);;
	while (i < count)
	{
		if (line[i] != symbol)
		{
			result += line[i];
			i++;
		}
		else
		{
			result += symbol;
			i = SkipSymbol(line, count, i, symbol);
		}
	}
	return result;
}

std::string RemoveExtraSpaces(std::string const& arg)
{
	if (arg.empty())
	{
		return arg;
	}

	std::string result = MergeSymbol(arg, ' ');

	if (result.size() > 0 && result.back() == ' ')
	{
		result.pop_back();
	}
	
	return result;
}