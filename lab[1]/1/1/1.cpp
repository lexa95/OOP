#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int strcmp(const char*, const char*);

void WriteStringInFile(FILE *f, const char * line, int count)
{
	for (int i(0); i < count; i++)
	{
		fputc(line[i], f);
	}
}

void ReplacementString(FILE * inFile, FILE * outFile, const char *searchString, const char *replaceString)
{
	int ch;
	int i = 0;

	while ((ch = fgetc(inFile)) != EOF)
	{
		if (ch == searchString[i])
		{
			i++;
			if (searchString[i] == '\0')
			{
				WriteStringInFile(outFile, replaceString, strlen(replaceString));
				i = 0;
			}
		}
		else
		{
			if (i != 0)
			{
				WriteStringInFile(outFile, searchString, i);
			}
			i = 0;
			fputc(ch, outFile);
		}
	}
	if (i != 0)
	{
		WriteStringInFile(outFile, searchString, i);
	}
}

int main(int argc, const char* argv[])
{
	if (argc != 5)
	{
		cout << "Wrong number of parameters!" << endl;
		_getch();
		return 1;
	}

	FILE *inFile = fopen(argv[1], "r");
	if (inFile == NULL)
	{
		printf("File opening error\n");
		_getch();
		return 1;
	}

	FILE *outFile = fopen(argv[2], "w");
	if (outFile == NULL)
	{
		printf("File opening error\n");
		_getch();
		return 1;
	}

	ReplacementString(inFile, outFile, argv[3], argv[4]);

	fclose(inFile);
	fclose(outFile);

	_getch();
	return 0;
}