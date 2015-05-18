// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

using namespace std;

struct EquationRoot4
{
	double numRoots;
	double roots[4];
};

EquationRoot4 Solve3(double a, double b, double c, double d)
{

}

EquationRoot4 Solve4(double a, double b, double c, double d, double e)
{
	EquationRoot4 result;

	if (0 == a)
	{
		throw "\n a = 0";
	}

	double p = (8 * a * c - 3 * pow(b, 2)) / 8 * pow(a, 2);
	double q = (8*pow(a, 2)*d + pow(b, 3) - 4 * a * b * c)/ 8*pow(a, 3);
	double r = ((16*a*pow(b, 2)*c - 64*pow(a, 2)*b*d - 3* pow(b, 4)+256*pow(a, 3)*e)/256*pow(a, 4));

	if (q == 0)
	{
		result.roots[0] = sqrt((-p - sqrt(pow(p, 2) - 4 * r))/2);
		result.roots[1] = -result.roots[0];
		result.roots[2] = sqrt((-p + sqrt(pow(p, 2) - 4 * r)) / 2);
		result.roots[3] = -result.roots[2];
	}
	else
	{

	}
	
	return result;
}


int main(int argc, char* argv[])
{


	return 0;
}

