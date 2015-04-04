#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

bool Pack(const string nameInputFile, const string nameOutputFile)
{
	ifstream inputFile(nameInputFile, ios::binary | ios::in);
	if (!inputFile.is_open())
	{
		cout << "File opening error\n";
		return false;
	}

	ofstream outputFile(nameOutputFile, ios::binary | ios::out);
	if (!outputFile.is_open())
	{
		cout << "File opening error\n";
		return false;
	}

	char ch;
	char previous;
	int index = 1;


	inputFile.read((char*)&previous, sizeof(char));

	while (!inputFile.eof())
	{
		inputFile.read((char*)&ch, sizeof(char));


		if (ch == previous && index != 255 && !inputFile.eof())
		{
			index++;
		}
		else
		{
			//cout << ' ' << index << ' ' << previous;
			outputFile.write((char*)&index, sizeof(char));
			outputFile.write((char*)&previous, sizeof(char));
			index = 1;
		}
		previous = ch;
	}

	inputFile.close();
	outputFile.close();

	return true;
}

bool UnPack(const string nameInputFile, const string nameOutputFile)
{
	ifstream inputFile(nameInputFile, ios::binary | ios::in);
	if (!inputFile.is_open())
	{
		cout << "File opening error\n";
		return false;
	}

	ofstream outputFile(nameOutputFile, ios::binary | ios::out);
	if (!outputFile.is_open())
	{
		inputFile.close();
		cout << "File opening error\n";
		return false;
	}

	char ch;
	char val;

	while (!inputFile.eof())
	{
		inputFile.read((char*)&val, sizeof(char));
		inputFile.read((char*)&ch, sizeof(char));

		if (inputFile.eof())
		{
			continue;
		}
		
		int length = unsigned char(val);

		for (int i = 0; i < length; i++)
		{
			outputFile.write((char*)&ch, sizeof(char));
		}
	}

	inputFile.close();
	outputFile.close();
	return true;
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
		if (!Pack(argv[2], argv[3]))
		{
			return 1;
		}
	}
	else if (!strcmp(argv[1], "unpack"))
	{
		if (!UnPack(argv[2], argv[3]))
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

