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

void Сrypt(int ch, int key, FILE * f)
{
	fputc(StirBits(ch ^ key), f);
}

void Decrypt(int ch, int key, FILE * f)
{

	fputc(BackStirBits(ch) ^ key, f);
}

bool WriteFromFileInFile(const char * nameInputFile, const char * nameOutputFile,
	const int key, void(*Process)(int ch, int key, FILE * f))
{
	FILE *pInputFile = fopen(nameInputFile, "rb");
	if (pInputFile == NULL)
	{
		printf("File opening error\n");
		return true;
	}

	FILE *pOutputFile = fopen(nameOutputFile, "wb");
	if (pOutputFile == NULL)
	{
		printf("File opening error\n");
		return true;
	}
	
	int ch;
	while ((ch = fgetc(pInputFile)) != EOF)
	{
		Process(ch, key, pOutputFile);
	}

	fclose(pInputFile);
	fclose(pOutputFile);
	return false;
}

int main(int argc, const char * argv[])
{
	/*int result = 0;
	int backResult = 0;
	int num = 254;

	result |= (num & 1) << 2;
	result |= (num & 2) << 2;
	result |= (num & 4) << 2;
	result |= (num & 8) << 3;
	result |= (num & 16) << 3;
	result |= (num & 32) >> 5;
	result |= (num & 64) >> 5;
	result |= (num & 128) >> 2;
	std::cout << int(result) << std::endl;

	backResult |= (result & 1) << 5;
	backResult |= (result & 2) << 5;
	backResult |= (result & 4) >> 2;
	backResult |= (result & 8) >> 2;
	backResult |= (result & 16) >> 2;
	backResult |= (result & 32) << 2;
	backResult |= (result & 64) >> 3;
	backResult |= (result & 128) >> 3;
	std::cout << int(backResult) << std::endl;

	_getch();*/

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
		if (WriteFromFileInFile(argv[2], argv[3], key, Сrypt))
		{
			return 1;
		}
	}
	else if (!strcmp(argv[1], "decrypt"))
	{
		if (WriteFromFileInFile(argv[2], argv[3], key, Decrypt))
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

