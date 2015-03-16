#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>

using namespace std;

void WriteStringInFile(FILE *f, const char * line, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		fputc(line[i], f);
		cout << line[i];
	}
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

vector<size_t> Kmp(const char *line)
{
	vector<size_t> kmpArray;
	size_t count = strlen(line);
	for (size_t i = 0; i < count; ++i)
	{
		kmpArray.push_back(CheckForOccurrence(line, i + 1));
	}
	return kmpArray;
}

void ReplacementString(FILE * inFile, FILE * outFile, const char *searchString, const char *replaceString)
{
	int ch;
	size_t i = 0;
	auto kmpArray = Kmp(searchString);

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
				size_t count = i;
				i = kmpArray[i-1];
				WriteStringInFile(outFile, searchString, count - i);
				i++;
			}
			else 
			{
				i = 0;
				fputc(ch, outFile);
			}
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