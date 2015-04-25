#include "stdafx.h"
#include "Complex.h"
#include <math.h>
#include <float.h>

CComplex::CComplex(double real, double image)
		:m_real(real), m_image(image)
{
}

double CComplex::Re() const
{
	return m_real;
}

double CComplex::Im() const
{
	return m_image;
}

double CComplex::GetArgument()const		
{
	return sqrt(pow(m_real, 2) + pow(m_image, 2));
}

double CComplex::GetMagnitude()const
{
	return atan(m_real / m_image);
}


CComplex operator+(CComplex const& num1, CComplex const& num2)
{
	return CComplex(num2.Re() + num1.Re(), num2.Im() + num1.Im());
}

CComplex operator+(CComplex const& num1, double const& num2)
{
	return num1 + CComplex(num2);
}

CComplex operator+(double const& num1, CComplex const& num2)
{
	return num2 + num1;
}

CComplex CComplex::operator+()
{
	return CComplex(m_real, m_image);
}


CComplex operator-(CComplex const& num1, CComplex const& num2)
{
	return CComplex(num1.Re() - num2.Re(), num1.Im() - num2.Im());
}

CComplex operator-(CComplex const& num1, double const& num2)
{
	return num1 - CComplex(num2);
}

CComplex operator-(double const& num1, CComplex const& num2)
{
	return CComplex(num1) - num2;
}

CComplex CComplex::operator-()
{
	return CComplex(-m_real, -m_image);
}


CComplex operator*(CComplex const& num1, CComplex const& num2)
{
	return CComplex((num1.Re() * num2.Re() - num1.Im() * num2.Im()), (num1.Re() * num2.Im() + num1.Im() * num2.Re()));
}

CComplex operator*(CComplex const& num1, double const& num2)
{
	return num1 * CComplex(num2);
}

CComplex operator*(double const& num1, CComplex const& num2)
{
	return CComplex(num1) * num2;
}


CComplex operator/(CComplex const& num1, CComplex const& num2)
{
	return CComplex((num1.Re() * num2.Re() + num1.Im() * num2.Im()) / (pow(num2.Re(), 2) + pow(num2.Im(), 2)), (num2.Re() * num1.Im() - num2.Im() * num1.Re()) / (pow(num2.Re(), 2) + pow(num2.Im(), 2)));
}

CComplex operator/(CComplex const& num1, double const& num2)
{
	return num1 / CComplex(num2);
}

CComplex operator/(double const& num1, CComplex const& num2)
{
	return CComplex(num1) / num2;
}


CComplex CComplex::operator+=(CComplex const& num)
{
	*this = *this + num;
	return *this;
}

CComplex CComplex::operator-=(CComplex const& num)
{
	*this = *this - num;
	return *this;
}

CComplex CComplex::operator*=(CComplex const& num)
{
	*this = *this * num;
	return *this;
}

CComplex CComplex::operator/=(CComplex const& num)
{
	*this = *this / num;
	return *this;
}

bool operator==(CComplex const& num1, CComplex const& num2)
{
	return (fabs(num1.Re() - num2.Re()) < DBL_MIN) && (fabs(num1.Im() - num2.Im()) < DBL_MIN);
}

bool operator!=(CComplex const& num1, CComplex const& num2)
{
	return !(num1 == num2);
}

CComplex::~CComplex()
{
}
