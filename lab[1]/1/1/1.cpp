#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int strcmp(const char*, const char*);

void AddCharacterInString(char * line, char symbol)
{ 
	for (int i = 0; i <= strlen(line); i++)
	{
		if (line[i] == '\0')
		{
			line[i++] = symbol;
			line[i] = '\0';
			return;
		}
	}
}

void ReplacementString(FILE * inFile, FILE * outFile, const char *searchString, const char *replaceString)
{
	int ch;
	int i = 0;
	char *line = new char[strlen(searchString)];
	line[0] = '\0';

	while ((ch = fgetc(inFile)) != EOF)
	{
		if (ch == searchString[i])
		{
			AddCharacterInString(line, ch);
			i++;
			if (searchString[i] == '\0')
			{
				for (int i(0); i < strlen(replaceString); i++)
				{
					fputc(replaceString[i], outFile);
				}
				line[0] = '\0';
				i = 0;
			}
		}
		else
		{
			if (line[0] != '\0')
			{
				for (int i(0); i < strlen(line); i++)
				{
					fputc(line[i], outFile);
				}
				line[0] = '\0';
			}
			i = 0;
			fputc(ch, outFile);
		}
	}
}

int main(int argc, char* argv[])
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