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

bool Сrypt(const char * nameInputFile, const char * nameOutputFile, const int key)
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
		fputc(ch ^ key, pOutputFile);
	}

	fclose(pInputFile);
	fclose(pOutputFile);
	return false;
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

	if (!strcmp(argv[1], "crypt") || !strcmp(argv[1], "decrypt"))
	{
		if (Сrypt(argv[2], argv[3], key))
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

