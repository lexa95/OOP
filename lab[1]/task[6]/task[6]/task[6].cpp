#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>

const int MAX_SIZE = 100;

void PrintMap(std::vector<std::vector<unsigned>> map)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			switch (map[i][j])
			{
			case 1: std::cout << '#'; break;
			case 3: std::cout << 'A'; break;
			case -1: std::cout << 'B'; break;
			case 2: std::cout << '-'; break;
			default: std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

}

void WriteMazeOfFile(FILE * f, std::vector<std::vector<unsigned>> map)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			switch (map[i][j])
			{
			case 1: putc('#', f); break;
			case 3: putc('A', f); break;
			case -1: putc('B', f); break;
			case 2: putc('-', f); break;
			default: putc(' ', f);
			}
		}
		putc('\n', f);
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

std::vector<std::vector<unsigned>> ReadFromFileMap(FILE *pFile, bool & err)
{
	int ch;
	unsigned i = 0;
	unsigned j = 0;
	
	unsigned leftLimit,	rightLimit,	topLimit, lowerLimit;
	SearchBorder(pFile, leftLimit, rightLimit, topLimit, lowerLimit);
	
	if ((rightLimit - leftLimit) > 100 || (lowerLimit - topLimit) > 100)
	{
		err = true;
	}
	else
	{
		err = false;
	}

	std::vector<std::vector<unsigned>> map;
	std::vector<unsigned> line;
	
	bool flag = false;
	while ((ch = fgetc(pFile)) != EOF)
	{
		if (ch != '\n')
		{
			if ((i >= leftLimit && i <= rightLimit) && (j >= topLimit && j <= lowerLimit))
			{
				flag = true;
				switch (ch)
				{
				case '#': line.push_back(1); break;
				case 'A': line.push_back(3); break;
				case 'B': line.push_back(-1); break;
				case ' ': line.push_back(0); break;
				default: break;
				}
			}
			i++;
		}
		else
		{
			if (flag)
			{
				map.push_back(line);
				line.clear();
			}
			flag = false;
			i = 0;
			j++;
		}
	}
	return map;
}

bool CheckArrayBounds(std::vector<std::vector<unsigned>> map, int x, int y)
{
	return (x >= 0 && map.size() >= x) && (y > 0 && map[x].size() > y);
}

void AddIndexes(std::vector<std::vector<unsigned>> & map, int x, int y, unsigned index)
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

void TakeCoordinatesEnd(std::vector<std::vector<unsigned>> map, int & x, int & y)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == -1)
			{
				x = i;
				y = j;
				return;
			}
		}
	}
}

void LetWave(std::vector<std::vector<unsigned>> & map, unsigned index, int xEnd, int yEnd)
{
	bool flag = true;

	while (map[xEnd][yEnd] == -1 && flag)
	{
		flag = false; 
		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[i].size(); j++)
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

void GatherWay(std::vector<std::vector<unsigned>> & map, int xEnd, int yEnd)
{
	int index = map[xEnd][yEnd];
	map[xEnd][yEnd] = -1;
	bool flag = true;
	
	while (flag)
	{
		if (CheckArrayBounds(map, xEnd + 1, yEnd) && map[xEnd + 1][yEnd] == index - 1)
		{CheckArrayBounds(map, xEnd + 1, yEnd) &&
			xEnd++;
		}
		else if (CheckArrayBounds(map, xEnd - 1, yEnd) && map[xEnd - 1][yEnd] == index - 1)
		{
			xEnd--;
		}
		else if (CheckArrayBounds(map, xEnd, yEnd + 1) && map[xEnd][yEnd + 1] == index - 1)
		{
			yEnd++;
		}
		else if (CheckArrayBounds(map, xEnd, yEnd - 1) && map[xEnd][yEnd - 1] == index - 1)
		{
			yEnd--;
		}
		else flag = false;

		if (map[xEnd][yEnd] == 3) break;
		map[xEnd][yEnd] = 2;
		index--;
	}
}

void WaveSearch(std::vector<std::vector<unsigned>> & map)
{
	int xEnd, yEnd;
	TakeCoordinatesEnd(map, xEnd, yEnd);
	
	LetWave(map, 3, xEnd, yEnd);
	GatherWay(map, xEnd, yEnd);

}

bool CheckMap(std::vector<std::vector<unsigned>> map)
{
	int pointStart = 0;
	int pointEnd = 0;

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 3)
			{
				pointStart++;
			}
			if (map[i][j] ==-1)
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

	FILE *pFile = fopen(argv[1], "r");
	if (pFile == NULL)
	{
		printf("File opening error\n");
		return 1;
	}

	bool err;
	std::vector<std::vector<unsigned>> map = ReadFromFileMap(pFile, err);
	fclose(pFile);

	if (err)
	{
		std::cout << "Large size of the maze." << std::endl;
		return 1;
	}

	if (!CheckMap)
	{
		std::cout << "Incorrect map." << std::endl;
		return 1;
	}

	WaveSearch(map);

	FILE *outFile = fopen(argv[2], "w");
	if (outFile == NULL)
	{
		printf("File opening error\n");
		return 1;
	}
	WriteMazeOfFile(outFile, map);
	fclose(outFile);

	_getch();
	return 0;
}

