#include "OccurrenceOfWords.h"
#include "stdafx.h"

char ToUpper(const char ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (char)(ch - ('a' - 'A'));
	}

	if (ch >= 224 && ch <= 255)
	{
		return (char)(ch - ('à' - 'À'));
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

void PrintArray(std::map<std::string, int> & arr)
{
	for each(std::pair<std::string, int> val in arr)
	{
		std::cout  << val.first << " -> " << val.second << std::endl;
	}
}

void AddToTheArrayWord(std::map<std::string, int> & arr, std::string word)
{
	for each(std::pair<std::string, int> val in arr)
	{
		if (UpperCase(val.first) == UpperCase(word))
		{
			arr[val.first]++;
			return;
		}
	}
	arr[word] = 1;
}

void AddToTheArray(const std::string line, std::map<std::string, int> & arr)
{
	std::string word;
	size_t count = strlen(line.c_str());
	
	for (size_t i = 0; i < count; i++)
	{
		if (line[i] == '\t' || line[i] == ' ' || line[i] == '\0')
		{
			if (!word.empty())
			{
				AddToTheArrayWord(arr, word);
				word.erase();
			}
		}
		else
		{
			word += line[i];
		}
	}

	if (!word.empty())
	{
		AddToTheArrayWord(arr, word);
	}
}

void OccurrenceOfWord()
{
	std::map<std::string, int> arr;
	std::string line;

	while (!std::cin.eof())
	{
		std::string line;
		if (std::getline(std::cin, line))
		{
			if (line == "exit")
			{
				break;
			}
			AddToTheArray(line, arr);
		}
		else
		{
			break;
		}
	}
	PrintArray(arr);
}