#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
int strcmp(const char *str1, const char *str2);



double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

double CalculatesDistance(double speed, double angle)
{
	double g = 9.8;
	double result;
	result = ((speed * speed) * sin(2 * ((angle * M_PI) / 180))) / g;
	return result;
}

bool IsExit(const char *line)
{
	return !strcmp(line, "exit");
}

double InputNumber(const char* line, bool & err)
{
	string str;
	double result;

	do
	{
		cout << line;
		cin >> str;
		result = StringToDouble(str.c_str(), err);
		if (result < 0)
		{
			cout << "number must be greater than zero" << endl;
		}
		else if (err && !IsExit(str.c_str()))
		{
			cout << "Incorrect number." << endl;
		}
	} while (err && !IsExit(str.c_str()) || result < 0);

	err = IsExit(str.c_str());
	return result;
}

int main(int argc, char* argv[])
{
	string strSpeed, strAngle;
	double angle, speed;
	bool err;
	while (true)
	{
		speed = InputNumber("Enter the initial velocity: ", err);
		if (err)
		{
			break;
		}

		angle = InputNumber("Enter the angle in degrees: ", err);
		if (err)
		{
			break;
		}
		cout << CalculatesDistance(speed, angle) << endl;
		
	}
	_getch();
	return 0;
}

