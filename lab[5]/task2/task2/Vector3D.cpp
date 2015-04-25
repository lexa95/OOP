#include "stdafx.h"
#include "Vector3D.h"


CVector3D::CVector3D()
			:x(0), y(0), z(0)
{
}

CVector3D::CVector3D(double x0, double y0, double z0)
			:x(x0), y(y0), z(z0)
{
}

double CVector3D::GetLength()const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void CVector3D::Normalize()
{
	double len = GetLength();
	x /= len;
	y /= len;
	x /= len;
}

double CVector3D::GetX()const
{
	return x;
}

double CVector3D::GetY()const
{
	return y;
}

double CVector3D::GetZ()const
{
	return z;
}

CVector3D CVector3D::operator+()
{
	return CVector3D(x, y, z);
}

CVector3D CVector3D::operator-()
{
	return CVector3D(-x, -y, -z);
}

bool operator==(CVector3D const& vector1, CVector3D const& vector2)
{
	return ((fabs(vector1.GetX() - vector2.GetX())  < DBL_MIN) 
		&& (fabs(vector1.GetY()  - vector2.GetY())  < DBL_MIN) 
		&& (fabs(vector1.GetZ()  - vector2.GetZ())  < DBL_MIN));
}

bool operator!=(CVector3D const& vector1, CVector3D const& vector2)
{
	return !(vector1 == vector2);
}

CVector3D operator+(CVector3D const& vector1, CVector3D const& vector2)
{
	return CVector3D(vector1.GetX() + vector2.GetX(), vector1.GetY() + vector2.GetY(), vector1.GetZ() + vector2.GetZ());
}

CVector3D operator-(CVector3D const& vector1, CVector3D const& vector2)
{
	return CVector3D(vector1.GetX() - vector2.GetX(), vector1.GetY() - vector2.GetY(), vector1.GetZ() - vector2.GetZ());
}