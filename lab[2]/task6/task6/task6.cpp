// task6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <windows.h>

int ToUpper(const int ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (int)(ch - ('a' - 'A'));
	}

	if (ch >= 224 && ch <= 255)
	{
		return (int)(ch - ('а' - 'ј'));
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

bool ReadFromFileDictionary(std::map<std::string, std::string> & dictionary, const char *nameFile)
{
	FILE *mFile = nullptr;

	if (fopen_s(&mFile, nameFile, "r") != 0)
	{
		printf("File opening error\n");
		return false;
	}

	int ch;
	std::string line = "";

	do
	{
		ch = fgetc(mFile);
		if (ch == '\n' || ch == EOF || ch == '\0')
		{
			if (line != "")
			{
				std::string word = GetStringToSubstring(line, "/");
				bool err;
				dictionary[word] = line.substr(strlen(word.c_str()) + 1);
				line = "";
			}
		}
		else
		{
			line += ch;
		}
	} while (ch != EOF);
	fclose(mFile);
	return true;
}

bool WriteToFileDictionary(std::map<std::string, std::string> & dictionary, const char *nameFile)
{
	FILE *mFile = nullptr;

	if (fopen_s(&mFile, nameFile, "w") != 0)
	{
		printf("File opening error\n");
		return false;
	}

	for each(std::pair<std::string, std::string> word in dictionary)
	{
		if (fputs((word.first + "/" + word.second + "\n").c_str(), mFile))
		{
			printf("Error writing to a file\n");
			fclose(mFile);
			return false;
		}
	}

	fclose(mFile);
	return true;
}

std::map<std::string, std::string>::iterator SearchForKeyInTheArray(std::map<std::string, std::string> & dictionary, std::string line)
{
	std::map<std::string, std::string>::iterator it;
	for (it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		if (UpperCase(it->first) == UpperCase(line))
		{
			return it;
		}
	}
	return it;
}

bool InteractionWithTheUser(std::map<std::string, std::string> & dictionary, const char *nameFile)
{
	std::cout << "Enter word: " << std::endl;
	bool isChangeDictionary = false;
	while (!std::cin.eof())
	{
		std::string line;
		std::cout << '>';
		if (std::getline(std::cin, line))
		{
			if (line == "")
			{
				continue;
			}

			auto search = SearchForKeyInTheArray(dictionary, line);
			if (search != dictionary.end()) {
				std::cout << search->second << '\n';
			}
			else 
			{
				std::cout << "Ќеизвестное слово У" << line << "Ф. ¬ведите перевод или пустую строку дл€ отказа.\n>";
				
				std::string value;
				std::getline(std::cin, value);
				if (value != "")
				{
					isChangeDictionary = true;
					dictionary[line] = value;
					std::cout << "—лово У" << line << "Ф сохранено в словаре как У" << value << "Ф." << std::endl;
				}
				else
				{
					std::cout << "—лово У" << line << "Ф проигнорировано." << std::endl;
				}
			}
		}
		else
		{
			break;
		}
	}

	if (isChangeDictionary)
	{
		std::cout << "¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом." << std::endl << ">";
		char answer;
		scanf_s("%c", &answer);
		if (answer == 'Y' || answer == 'y')
		{
			if (!WriteToFileDictionary(dictionary, nameFile))
			{
				std::cout << "ќшибка записи в файл."<<std::endl;
				return false;
			}
			else
			{
				std::cout << "»зменени€ сохранены. ƒо свидани€." << std::endl;
			}
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 2)
	{
		std::cout << "ƒолжен быть один параметр." << std::endl;
		return 1;
	}

	std::map<std::string, std::string> dictionary;
	if (!ReadFromFileDictionary(dictionary, argv[1]))
	{
		return 1;
	}
	if (!InteractionWithTheUser(dictionary, argv[1]))
	{
		return 1;
	}
	
	return 0;
}

