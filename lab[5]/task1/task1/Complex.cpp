#include "stdafx.h"
#include "Complex.h"
#include <math.h>

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

CComplex CComplex::operator +(CComplex const& num)
{
	return CComplex(m_real + num.Re(), m_image + num.Im());
}

CComplex CComplex::operator +(double const& num)
{
	return (CComplex(num) + *this);
}

CComplex::~CComplex()
{
}
