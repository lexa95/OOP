#include "stdafx.h"
#include "Vector3D.h"

std::vector<std::string> SplitString(std::string line, std::string separator)
{
	std::vector<std::string> result;

	line += ", ";
	std::string str = "";
	size_t i = 0;
	while (i < line.size())
	{
		if (separator == line.substr(i, separator.size()))
		{
			if (str != "")
			{
				result.push_back(str);
			}
			str = "";
			i += separator.size();
		}
		else
		{
			str += line[i];
			i++;
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

/*
CVector3D operator+=(CVector3D const& vector)
{
	return	CVector3D();
}

CVector3D operator-=(CVector3D const& vector)
{
	return	CVector3D();
}
*/

CVector3D operator*(CVector3D const& vector, double const& num)
{
	return	CVector3D(vector.GetX() * num, vector.GetY() * num, vector.GetZ() * num);
}

CVector3D operator*(double const& num, CVector3D const& vector)
{
	return	CVector3D(vector.GetX() * num, vector.GetY() * num, vector.GetZ() * num);
}

CVector3D operator/(CVector3D const& vector, double const& num)
{
	return CVector3D(vector.GetX() / num, vector.GetY() / num, vector.GetZ() / num);
}

CVector3D operator/(double const& num, CVector3D const& vector)
{
	return CVector3D(vector.GetX() / num, vector.GetY() / num, vector.GetZ() / num);
}

std::ostream& operator<<(std::ostream& os, CVector3D const& vector)
{
	os << vector.GetX() << ", " << vector.GetY() << ", " << vector.GetZ();
	return os;
}

std::istream& operator>>(std::istream& is, CVector3D & num)
{
	std::string line;
	std::getline(is, line);
	double x, y, z;
	
	auto values = SplitString(line, ", ");
	if (values.size() == 3)
	{
		bool err;
		x = StringToDouble(values[0].c_str(), err);
		if (err)
		{
			return is;
		}

		y = StringToDouble(values[1].c_str(), err);
		if (err)
		{
			return is;
		}

		z = StringToDouble(values[2].c_str(), err);
		if (err)
		{
			return is;
		}

		num = CVector3D(x, y, z);
	}
	return is;
}

CVector3D CVector3D::operator*=(double const& num)
{
	this->x *= num;
	this->y *= num;
	this->z *= num;
	return *this;
}

CVector3D CVector3D::operator/=(double const& num)
{
	this->x /= num;
	this->y /= num;
	this->z /= num;
	return *this;
}

CVector3D CVector3D::operator+=(CVector3D const& vector)
{
	double len = GetLength() + vector.GetLength();
	double value = len / GetLength();
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

CVector3D CVector3D::operator-=(CVector3D const& vector)
{
	double len = GetLength() - vector.GetLength();
	double value = GetLength() / len;
	if (value > 0)
	{
		x /= value;
		y /= value;
		z /= value;
	}
	else
	{
		x = 0;
		y = 0;
		z = 0;
	}
	return *this;
}