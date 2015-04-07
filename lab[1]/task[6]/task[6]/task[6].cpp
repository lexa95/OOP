#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>

const int MAX_SIZE = 100;

const int start = 3;
const int end = -1;
const int obstacle = 1;
const int way = 2;

struct Map
{
	int width;
	int height;
	std::vector<unsigned> body;
};

void PrintMap(Map map)
{
	for (int i = 0; i < map.height; i++)
	{
		for (int j = 0; j < map.width; j++)
		{
			switch (map.body[i * map.width + j])
			{
			case obstacle : std::cout << '#'; break;
			case start    : std::cout << 'A'; break;
			case end      : std::cout << 'B'; break;
			case way      : std::cout << '-'; break;
			default: std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

}

void WriteMazeOfFile(FILE * f, Map map)
{
	for (int i = 0; i < map.height; i++)
	{
		for (int j = 0; j < map.width; j++)
		{
			switch (map.body[i * map.width + j])
			{
			case obstacle : putc('#', f); break;
			case start    : putc('A', f); break;
			case end      : putc('B', f); break;
			case way      : putc('-', f); break;
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

Map ReadFromFileMap(FILE *pFile, bool & err)
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

	Map result;
	result.width = rightLimit - leftLimit + 1;
	result.height = lowerLimit - topLimit + 1; 
	result.body.reserve(result.height * result.width);
	
	size_t length = result.height * result.width;
	for (size_t index = 0; index <= length; index++) result.body.push_back(0);
	
	bool flag = false;
	while ((ch = fgetc(pFile)) != EOF)
	{
		if (ch != '\n')
		{
			if ((i >= leftLimit && i <= rightLimit) && (j >= topLimit && j <= lowerLimit))
			{
				int coordinate = (j - topLimit) * result.width + (i - leftLimit);
				flag = true;
				switch (ch)
				{
				case '#': result.body[coordinate] = obstacle; break;
				case 'A': result.body[coordinate] = start; break;
				case 'B': result.body[coordinate] = end; break;
				default: break;
				}
				//std::cout << char(ch);
			}
			i++;
		}
		else
		{
			//std::cout << std::endl;
			flag = false;
			i = 0;
			j++;
		}
	}
	return result;
}

bool CheckArrayBounds(Map map, int coordinates)
{
	return (0 <= coordinates) && coordinates <= (map.height * map.width) &&
		(coordinates + 1) % map.width != 0 && (coordinates + 1) % map.width + 1 != 0;
} 

void AddIndexes(Map & map, int coordinates, unsigned index)
{
	if (CheckArrayBounds(map, coordinates + 1) && (map.body[coordinates + 1] > index) || map.body[coordinates + 1] == 0)
	{
		map.body[coordinates + 1] = index;
	}
	if (CheckArrayBounds(map, coordinates - 1) && (map.body[coordinates - 1] > index) || map.body[coordinates - 1] == 0)
	{
		map.body[coordinates - 1] = index;
	}
	if (CheckArrayBounds(map, coordinates + map.width) && (map.body[coordinates + map.width] > index) || map.body[coordinates + map.width] == 0)
	{
		map.body[coordinates + map.width] = index;
	}
	if (CheckArrayBounds(map, coordinates - map.width) && (map.body[coordinates - map.width] > index) || map.body[coordinates - map.width] == 0)
	{
		map.body[coordinates - map.width] = index;
	}
}

int TakeCoordinatesEnd(Map const & map)
{
	for (int i = 0; i < map.width * map.height; i++)
	{
		if (map.body[i] == -1)
		{
			return i;
		}
	}
}

void LetWave(Map & map, unsigned index, int coordinatesEnd)
{
	bool flag = true;

	while (map.body[coordinatesEnd] == end && flag)
	{
		flag = false; 
		for (int i = 0; i < map.height * map.width; i++)
		{
			if (map.body[i] == index)
			{
				AddIndexes(map, i, index + 1);
				flag = true;
			}
		}
		index++;
	}
}

void GatherWay(Map & map, int coordinatesEnd)
{
	int coordinates = coordinatesEnd;
	int index = map.body[coordinates];
	map.body[coordinates] = end;
	bool flag = true;
	
	while (map.body[coordinates] != start)
	{
		map.body[coordinates] = way;
		if (CheckArrayBounds(map, coordinates + 1) && map.body[coordinates + 1] == index - 1)
		{
			coordinates++;
		}
		else if (CheckArrayBounds(map, coordinates - 1) && map.body[coordinates - 1] == index - 1)
		{
			coordinates--;
		}
		else if (CheckArrayBounds(map, coordinates + map.width) && map.body[coordinates + map.width] == index - 1)
		{
			coordinates += map.width;
		}
		else if (CheckArrayBounds(map, coordinates - map.width) && map.body[coordinates - map.width] == index - 1)
		{
			coordinates -= map.width;
		}
		else
		{
			break;
		}

		index--;
		//PrintMap(map);
	}
	map.body[coordinatesEnd] = end;
}

void WaveSearch(Map & map)
{
	int coordinatesEnd = TakeCoordinatesEnd(map);
	LetWave(map, start, coordinatesEnd);
	GatherWay(map, coordinatesEnd);
}

bool CheckMap(Map map)
{
	int pointStart = 0;
	int pointEnd = 0;

	for (int i = 0; i < map.height * map.width; i++)
	{
		if (map.body[i] == start)
		{
			pointStart++;
		}
		if (map.body[i] == end)
		{
			pointEnd++;
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
	Map map = ReadFromFileMap(pFile, err);
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

