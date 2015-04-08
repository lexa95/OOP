#include "stdafx.h"
#include "RectArray.h"
#include <iostream>
#include <conio.h>
#include <vector>

const int MAX_SIZE = 100;

const int start = 3;
const int end = INT_MAX;
const int obstacle = 1;
const int way = 2;

void PrintMap(RectArray map)
{
	for (int i = 0; i < map.GetHight(); i++)
	{
		for (int j = 0; j < map.GetWidth(); j++)
		{
			switch (map[i][j])
			{
			case obstacle: std::cout << '#'; break;
			case start: std::cout << 'A'; break;
			case end: std::cout << 'B'; break;
			default: std::cout << '-';
			}
		}
		std::cout << std::endl;
	}
}

void WriteMazeOfFile(FILE * f, RectArray map)
{
	for (int i = 0; i < map.GetHight(); i++)
	{
		for (int j = 0; j < map.GetWidth(); j++)
		{
			switch (map[i][j])
			{
			case obstacle: putc('#', f); break;
			case start: putc('A', f); break;
			case end: putc('B', f); break;
			case way: putc('-', f); break;
			default: putc(' ', f);
			}
		}
		putc('\n', f);
	}
}

void SearchBorder(FILE *pFile, int & leftLimit,
	int & rightLimit, int & topLimit, int & lowerLimit)
{
	int i = 0;
	int j = 0;
	int ch;

	leftLimit = INT_MAX;
	rightLimit = 0;
	topLimit = INT_MAX;
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

RectArray ReadFromFileMap(FILE *pFile, bool & err)
{
	int ch;
	int i = 0;
	int j = 0;

	int leftLimit, rightLimit, topLimit, lowerLimit;
	SearchBorder(pFile, leftLimit, rightLimit, topLimit, lowerLimit);

	if ((rightLimit - leftLimit) > MAX_SIZE || (lowerLimit - topLimit) > MAX_SIZE)
	{
		err = true;
	}
	else
	{
		err = false;
	}

	int width = rightLimit - leftLimit + 1;
	int height = lowerLimit - topLimit + 1;
	RectArray map(height, width, 0);

	bool flag = false;
	while ((ch = fgetc(pFile)) != EOF)
	{
		if (ch != '\n')
		{
			if ((i >= leftLimit && i <= rightLimit) && (j >= topLimit && j <= lowerLimit))
			{
				int x = j - topLimit;
				int y = i - leftLimit;
				switch (ch)
				{
				case '#': map[x][y] = obstacle; break;
				case 'A': map[x][y] = start; break;
				case 'B': map[x][y] = end; break;
				default: break;
				}
			}
			i++;
		}
		else
		{
			i = 0;
			j++;
		}
	}
	return map;
}

bool CheckArrayBounds(RectArray map, int x, int y)
{
	return (x >= 0 && map.GetHight() >= x) && (y > 0 && map.GetWidth() >= y);
}

void AddIndexes(RectArray & map, int x, int y, unsigned index)
{
	if (CheckArrayBounds(map, x + 1, y) && (map[x + 1][y] > index) || map[x + 1][y] == 0)
	{
		map[x + 1][y] = index;
	}
	if (CheckArrayBounds(map, x - 1, y) && (map[x - 1][y] > index) || map[x - 1][y] == 0)
	{
		map[x - 1][y] = index;
	}
	if (CheckArrayBounds(map, x, y + 1) && (map[x][y + 1] > index) || map[x][y + 1] == 0)
	{
		map[x][y + 1] = index;
	}
	if (CheckArrayBounds(map, x, y - 1) && (map[x][y - 1]  > index) || map[x][y - 1] == 0)
	{
		map[x][y - 1] = index;
	}
}

void TakeCoordinatesEnd(RectArray map, int & x, int & y)
{
	for (int i = 0; i < map.GetHight(); i++)
	{
		for (int j = 0; j < map.GetWidth(); j++)
		{
			if (map[i][j] == end)
			{
				x = i;
				y = j;
				return;
			}
		}
	}
}

void LetWave(RectArray & map, unsigned index, int xEnd, int yEnd)
{
	bool flag = true;

	while (map[xEnd][yEnd] == end && flag)
	{
		flag = false;
		for (int i = 0; i < map.GetHight(); i++)
		{
			for (int j = 0; j < map.GetWidth(); j++)
			{
				if (map[i][j] == index)
				{
					AddIndexes(map, i, j, index + 1);
					flag = true;
				}
			}
		}
		index++;
	}
}

void GatherWay(RectArray & map, const int xEnd, const int yEnd)
{
	int x = xEnd;
	int y = yEnd;
	int index = map[xEnd][yEnd];

	while (map[x][y] != start)
	{
		map[x][y] = way;
		if (CheckArrayBounds(map, x + 1, y) && map[x + 1][y] == index - 1)
		{
			CheckArrayBounds(map, x + 1, y) &&
				x++;
		}
		else if (CheckArrayBounds(map, x - 1, y) && map[x - 1][y] == index - 1)
		{
			x--;
		}
		else if (CheckArrayBounds(map, x, y + 1) && map[x][y + 1] == index - 1)
		{
			y++;
		}
		else if (CheckArrayBounds(map, x, y - 1) && map[x][y - 1] == index - 1)
		{
			y--;
		}
		else 
		{
			break;
		}

		index--;
	}
	map[xEnd][yEnd] = end;
}

void WaveSearch(RectArray & map)
{
	int xEnd, yEnd;
	TakeCoordinatesEnd(map, xEnd, yEnd);

	LetWave(map, start, xEnd, yEnd);
	GatherWay(map, xEnd, yEnd);

}

bool CheckMap(RectArray map)
{
	int pointStart = 0;
	int pointEnd = 0;

	for (int i = 0; i < map.GetHight(); i++)
	{
		for (int j = 0; j < map.GetWidth(); j++)
		{
			if (map[i][j] == start)
			{
				pointStart++;
			}
			if (map[i][j] == end)
			{
				pointEnd++;
			}
		}
	}
	return  (pointStart == 1) && (pointEnd == 1);
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Wrong number of parameters\n");
		return 1;
	}

	FILE *pFile;
	if (fopen_s(&pFile, argv[1], "r") != 0)
	{
		printf("File opening error\n");
		return 1;
	}

	bool err;
	RectArray map = ReadFromFileMap(pFile, err);
	fclose(pFile);
	if (err)
	{
		std::cout << "Large size of the maze." << std::endl;
		return 1;
	}

	if (!CheckMap(map))
	{
		std::cout << "Incorrect map." << std::endl;
		return 1;
	}

	WaveSearch(map);

	FILE *outFile;
	if (fopen_s(&outFile, argv[2], "w") != 0)
	{
		printf("File opening error\n");
		return 1;
	}
	WriteMazeOfFile(outFile, map);
	fclose(outFile);

	return 0;
}