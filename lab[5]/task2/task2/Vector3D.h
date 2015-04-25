#pragma once

#include <fstream>
#include <math.h>
#include <float.h>
#include <string>
#include <vector>

class CVector3D
{
public:
	CVector3D();
	CVector3D(double x0, double y0, double z0);
	
	double GetLength()const;
	void Normalize();
	
	double GetX()const;
	double GetY()const;
	double GetZ()const;

	CVector3D operator+();
	CVector3D operator-();

	friend CVector3D operator+(CVector3D const& vector1, CVector3D const& vector2);
	friend CVector3D operator-(CVector3D const& vector1, CVector3D const& vector2);

	CVector3D operator+=(CVector3D const& vector);
	CVector3D operator-=(CVector3D const& vector);
	
	friend CVector3D operator*(CVector3D const& vector1, double const& num);
	friend CVector3D operator*(double const& num, CVector3D const& vector2);

	friend CVector3D operator/(CVector3D const& vector1, double const& num);
	friend CVector3D operator/(double const& num, CVector3D const& vector2);
	
	CVector3D operator*=(double const& num);
	CVector3D operator/=(double const& num);

	friend bool operator==(CVector3D const& vector1, CVector3D const& vector2);
	friend bool operator!=(CVector3D const& vector1, CVector3D const& vector2);

	friend std::ostream& operator<<(std::ostream& os, CVector3D const& num);
	friend std::istream& operator>>(std::istream& is, CVector3D & num);

	double x, y, z;
};

