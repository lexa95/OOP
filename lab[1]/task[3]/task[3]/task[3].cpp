#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS

struct Matrix3x3
{
	double body[3][3];
};

struct Matrix2x2
{
	double body[2][2];
};

Matrix2x2 Minor(const Matrix3x3 & matrix, int x, int y);

double Determinant2x2(const Matrix2x2 & matrix)
{
	return matrix.body[0][0] * matrix.body[1][1] - matrix.body[0][1] * matrix.body[1][0];
}

double Determinant3x3(const Matrix3x3 & matrix)
{
	double result = 0;
	for (int i = 0; i < 3; i++)
	{
		if (i != 1)
		{
			result += matrix.body[0][i] * Determinant2x2(Minor(matrix, 0, i));
		}
		else
		{
			result -= matrix.body[0][i] * Determinant2x2(Minor(matrix, 0, i));
		}
	}
	return result;
}

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

Matrix2x2 Minor(const Matrix3x3 & matrix, int x, int y)
{
	Matrix2x2 result;
	int indX = 0;

	for (int i = 0; i < 3; i++)
	{
		if (i != x)
		{
			int indY = 0;
			for (int j = 0; j < 3; j++)
			{
				if (j != y)
				{
					result.body[indX][indY] = matrix.body[i][j];
					indY++;
				}
			}
			indX++;
		}
	}
	return result;
}

Matrix3x3 Matrix3x3OfCofactors(Matrix3x3 matrix)
{
	matrix.body[0][1] *= -1;
	matrix.body[1][0] *= -1;
	matrix.body[1][2] *= -1;
	matrix.body[2][1] *= -1;
	return matrix;
}

Matrix3x3 MatrixMinors(const Matrix3x3 & matrix)
{
	Matrix3x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.body[i][j] = Determinant2x2(Minor(matrix, i, j));
		}
	}

	return result;
}

Matrix3x3 TransposeMatrix(const Matrix3x3 & matrix)
{
	Matrix3x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.body[i][j] = matrix.body[j][i];
		}
	}

	return result;
}

Matrix3x3 MultiplicationMatrixByNumber(const Matrix3x3 & matrix, double number)
{
	Matrix3x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.body[i][j] = matrix.body[i][j] * number;
		}
	}
	return result;
}

void PrintMatrix(const Matrix3x3 & matrix)
{
	std::cout << std::fixed << std::setprecision(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix.body[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

Matrix3x3 InverseMatrix(const Matrix3x3 & matrix, bool & err)
{
	Matrix3x3 result = { 0 };
	double determinant = Determinant3x3(matrix);
	if (determinant == 0)
	{
		err = true;
		return result;
	}
	result = MatrixMinors(matrix);
	result = Matrix3x3OfCofactors(result);
	result = TransposeMatrix(result);
	result = MultiplicationMatrixByNumber(result, 1 / determinant);
	PrintMatrix(result);

	err = false;
	return result;
}

bool ReadMatrixFromFile(const char * fileName, Matrix3x3 & matrix)
{
	FILE *inFile = nullptr;
	
	if (fopen_s(&inFile, fileName, "r") != 0)
	{
		printf("File opening error\n");
		return false;
	}

	int i = 0;
	int j = 0;
	std::string line = "";
	bool err;
	int ch = fgetc(inFile);
	do
	{
		if (ch == '\t')
		{
			matrix.body[i][j] = StringToDouble(line.c_str(), err);
			if (err)
			{
				fclose(inFile);
				return false;
			}
			line = "";
			j++;
		}
		else if (ch == '\n')
		{
			matrix.body[i][j] = StringToDouble(line.c_str(), err);
			if (err)
			{
				fclose(inFile);
				return false;
			}
			line = "";
			i++;
			j = 0;
		}
		else
		{
			line += ch;
		}
	} while ((ch = fgetc(inFile)) != EOF);
	
	if (i == 2 && j == 2)
	{
		matrix.body[i][j] = StringToDouble(line.c_str(), err);
	}
	else if (!(i == 3 && j == 0))
	{
		return false;
	}
	
	fclose(inFile);
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of parameters!" << std::endl;
		return 1;
	}

	Matrix3x3 matrix;
	if (!ReadMatrixFromFile(argv[1], matrix))
	{
		std::cout << "incorrect file" << std::endl;
		return 1;
	}

	bool err;
	InverseMatrix(matrix, err);
	if (err)
	{
		std::cout << "Impossible to invert a matrix" << std::endl;
		return 1;
	}

	_getch();
	return 0;
}

