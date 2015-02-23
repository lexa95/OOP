#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>

const int MAX_SIZE = 100;

void PrintMap(map myMap)
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			std::cout << myMap.coordinates[i][j];
		}
		std::cout << std::endl;
	}
}

void SearchBorder(FILE *pFile, unsigned & leftLimit, 
	unsigned & rightLimit, unsigned & topLimit, unsigned & lowerLimit)
{
	unsigned i = 0;
	unsigned j = 0;
	int ch;
	
	leftLimit = -1;
	rightLimit = 0;
	topLimit = -1;
	lowerLimit = 0;

	while ((ch = fgetc(pFile)) != EOF)
	{
		if (ch != '\n')
		{
			if (ch != ' ')
			{
				if (i < leftLimit) leftLimit = i;
				if (i > rightLimit) rightLimit = i;
				if (j < topLimit) topLimit = j;
				if (j > lowerLimit) lowerLimit = j;
			}
			i++;
		}
		else
		{
			i = 0;
			j++;
		}
	}
	rewind(pFile);
}

std::vector<std::vector<int>> ReadFromFileMap(FILE *pFile, )
{
	std::vector<std::vector<int>> map(10);
	int ch;
	unsigned i = 0;
	unsigned j = 0;
	unsigned leftLimit,	rightLimit,	topLimit, lowerLimit;
	SearchBorder(pFile, leftLimit, rightLimit, topLimit, lowerLimit);
	while ((ch = fgetc(pFile)) != EOF)
	{
		if (ch != '\n')
		{
			if ((i >= leftLimit || i <= rightLimit) && (j >= topLimit || j <= lowerLimit))
			{
				switch (ch)
				{
				case '#': myMap.coordinates[j - topLimit][i - leftLimit] = 1; break;
				case 'A': myMap.coordinates[j - topLimit][i - leftLimit] = 2; break;
				case 'B': myMap.coordinates[j - topLimit][i - leftLimit] = 3; break;
				case ' ': myMap.coordinates[j - topLimit][i - leftLimit] = 0; break;
				default: break;
				}
				i++;
			}
		}
		else
		{
			i = 0;
			j++;
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *pFile = fopen("labyrinth-3.txt", "r");
	if (pFile == NULL)
	{
		printf("File opening error\n");
		return 1;
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			myMap.coordinates[i][j] = 0;
		}
	}

	ReadFromFileMap(pFile, myMap);
	fclose(pFile);

	PrintMap(myMap);

	_getch();
	return 0;
}

