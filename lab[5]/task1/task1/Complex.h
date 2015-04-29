#pragma once

#include <iostream>
#include <fstream>
#include <float.h>
#include <math.h>
#include <string>

class CComplex
{
public: 
	CComplex(double real = 0, double image = 0);

	double Re() const;
	double Im() const;
	double GetArgument()const;
	double GetMagnitude()const;

	friend const CComplex operator+(CComplex const& num1, CComplex const& num2);
	//friend CComplex operator+(CComplex const& num1, double const& num2);
	//friend CComplex operator+(double const& num1, CComplex const& num2);
	CComplex operator+();

	friend const CComplex operator-(CComplex const& num1, CComplex const& num2);
	//friend CComplex operator-(CComplex const& num1, double const& num2);
	//friend CComplex operator-(double const& num1, CComplex const& num2);
	CComplex operator-();

	friend const CComplex operator*(CComplex const& num1, CComplex const& num2);
	//friend CComplex operator*(CComplex const& num1, double const& num2);
	//friend CComplex operator*(double const& num1, CComplex const& num2);


	friend const CComplex operator/(CComplex const& num1, CComplex const& num2);
	//friend CComplex operator/(CComplex const& num1, double const& num2);
	//friend CComplex operator/(double const& num1, CComplex const& num2);

	CComplex operator+=(CComplex const& num);
	CComplex operator-=(CComplex const& num);
	CComplex operator*=(CComplex const& num);
	CComplex operator/=(CComplex const& num);

	friend bool operator==(CComplex const& num1, CComplex const& num2);
	friend bool operator!=(CComplex const& num1, CComplex const& num2);

	friend std::ostream& operator<<(std::ostream& os, CComplex const& num);
	friend std::istream& operator>>(std::istream& is, CComplex & num);

	~CComplex();
private:
	double m_real, m_image;
};
