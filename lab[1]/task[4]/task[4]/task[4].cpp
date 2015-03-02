#include "stdafx.h"
#include <conio.h>
#include <iostream>

void WriteInFile(FILE * f, int num1, int num2)
{
	fputc(num1, f);
	fputc(num2, f);
}

bool Pack(const char * nameInputFile, const char * nameOutputFile)
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
	
	int ch, previous;
	int index = 1;
	previous = fgetc(pInputFile);
	
	while ((ch = fgetc(pInputFile)) != EOF)
	{
		if (ch == previous && index != 255)
		{
			index++;
		}
		else
		{
			WriteInFile(pOutputFile, index, previous);
			index = 1;
		}
		previous = ch;
	}
	WriteInFile(pOutputFile, index, previous);

	fclose(pInputFile);
	fclose(pOutputFile);
	return false;
}

bool UnPack(const char * nameInputFile, const char * nameOutputFile)
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
	int val;
	while ((val = fgetc(pInputFile)) != EOF)
	{
		ch = fgetc(pInputFile);
		for (int i = 0; i < val; i++)
		{
			fputc(ch, pOutputFile);
		}
	}

	fclose(pInputFile);
	fclose(pOutputFile);
	return false;
}

int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "Rus");

	if (argc != 4)
	{
		std::cout << "Неверное кол-во параметров." << std::endl;
		return 1;
	}

	if (!strcmp(argv[1], "pack"))
	{
		if (Pack(argv[2], argv[3]))
		{
			return 1;
		}
	}
	else if (!strcmp(argv[1], "unpack"))
	{
		if (UnPack(argv[2], argv[3]))
		{
			return 1;
		}
	}
	else
	{
		std::cout << "Не удалось распознать ключ" << std::endl;
		return 1;
	}

	return 0;
}

