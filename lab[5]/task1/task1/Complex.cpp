#include "stdafx.h"
#include "Complex.h"


CComplex::CComplex(int x, int y)
		:m_x(x), m_y(y)
{
}

int CComplex::GetX() const
{
	return m_x;
}

int CComplex::GetY() const
{
	return m_y;
}

CComplex CComplex::operator +(CComplex const& num)
{
	return CComplex(m_x + num.GetX(), m_y + num.GetY());
}

CComplex::~CComplex()
{
}
