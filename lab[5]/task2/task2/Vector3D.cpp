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

//double CVector3D::GetLenth()const
//{
//	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
//}

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

CVector3D operator+()
{
	return CVector3D(x, y, z);
}

CVector3D operator-()
{
	return CVector3D(-x, -y, -z);
}