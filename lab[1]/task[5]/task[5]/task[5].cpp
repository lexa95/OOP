#include "stdafx.h"
#include <conio.h>
#include <iostream>

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int StirBits(int bit)
{
	int result = 0;

	result |= (bit & 1) << 2;
	result |= (bit & 2) << 2;
	result |= (bit & 4) << 2;
	result |= (bit & 8) << 3;
	result |= (bit & 16) << 3;
	result |= (bit & 32) >> 5;
	result |= (bit & 64) >> 5;
	result |= (bit & 128) >> 2;

	return result;
}

int BackStirBits(int bit)
{
	int result = 0;

	result |= (bit & 1) << 5;
	result |= (bit & 2) << 5;
	result |= (bit & 4) >> 2;
	result |= (bit & 8) >> 2;
	result |= (bit & 16) >> 2;
	result |= (bit & 32) << 2;
	result |= (bit & 64) >> 3;
	result |= (bit & 128) >> 3;

	return result;
}

bool WriteFromFileInFile(const std::string nameInputFile, const std::string nameOutputFile,
	const int key, void(*Process)(int ch, int key, FILE * f))
{
	
	FILE *pInputFile;
	if (fopen_s(&pInputFile, nameInputFile.c_str(), "rb") != 0)
	{
		printf("File opening error\n");
		return false;
	}

	FILE *pOutputFile;
	if (fopen_s(&pOutputFile, nameOutputFile.c_str(), "wb") != 0)
	{
		printf("File opening error\n");
		fclose(pInputFile);
		return false;
	}
	
	int ch;
	while ((ch = fgetc(pInputFile)) != EOF)
	{
		Process(ch, key, pOutputFile);
	}

	fclose(pInputFile);
	fclose(pOutputFile);
	return true;
}

int main(int argc, const char * argv[])
{
	setlocale(LC_ALL, "Rus");
	if (argc != 5)
	{
		std::cout << "Неверное кол-во параметров." << std::endl;
		return 1;
	}

	bool err;
	int key = StringToInt(argv[4], err);
	if (err || !(key >= 0 && key <= 255))
	{
		std::cout << "Не верный ключ" << std::endl;
		return 1;
	}

	if (!strcmp(argv[1], "crypt"))
	{
		std::function<bool()> f = []() -> bool {
			return false;
		};

		auto Сrypt = [](int ch, int key, FILE * f) -> void
		{
			fputc(StirBits(ch ^ key), f);
		};

		if (!WriteFromFileInFile(argv[2], argv[3], key, Сrypt))
		{
			return 1;
		}
	}
	else if (!strcmp(argv[1], "decrypt"))
	{
		auto Decrypt = [](int ch, int key, FILE * f) -> void
		{
			fputc(BackStirBits(ch) ^ key, f);
		};

		if (!WriteFromFileInFile(argv[2], argv[3], key, Decrypt))
		{
			return 1;
		}
	}
	else
	{
		std::cout << "Не удалось распознать команду" << std::endl;
		return 1;
	}

	return 0;
}

