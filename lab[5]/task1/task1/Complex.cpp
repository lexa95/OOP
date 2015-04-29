#include "stdafx.h"
#include "Complex.h"


double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

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

CComplex const operator+(CComplex const& num1, CComplex const& num2)
{
	return CComplex(num2.Re() + num1.Re(), num2.Im() + num1.Im());
}

//CComplex operator+(CComplex const& num1, double const& num2)
//{
//	return num1 + CComplex(num2);
//}

//CComplex operator+(double const& num1, CComplex const& num2)
//{
//	return num2 + num1;
//}

CComplex CComplex::operator+()
{
	return CComplex(m_real, m_image);
}

CComplex const operator-(CComplex const& num1, CComplex const& num2)
{
	return CComplex(num1.Re() - num2.Re(), num1.Im() - num2.Im());
}

//CComplex operator-(CComplex const& num1, double const& num2)
//{
//	return num1 - CComplex(num2);
//}

//CComplex operator-(double const& num1, CComplex const& num2)
//{
//	return CComplex(num1) - num2;
//}

CComplex CComplex::operator-()
{
	return CComplex(-m_real, -m_image);
}

CComplex const operator*(CComplex const& num1, CComplex const& num2)
{
	return CComplex((num1.Re() * num2.Re() - num1.Im() * num2.Im()), (num1.Re() * num2.Im() + num1.Im() * num2.Re()));
}

//CComplex operator*(CComplex const& num1, double const& num2)
//{
//	return num1 * CComplex(num2);
//}

//CComplex operator*(double const& num1, CComplex const& num2)
//{
//	return CComplex(num1) * num2;
//}


CComplex const operator/(CComplex const& num1, CComplex const& num2)
{
	return CComplex((num1.Re() * num2.Re() + num1.Im() * num2.Im()) / (pow(num2.Re(), 2) + pow(num2.Im(), 2)), (num2.Re() * num1.Im() - num2.Im() * num1.Re()) / (pow(num2.Re(), 2) + pow(num2.Im(), 2)));
}

//CComplex operator/(CComplex const& num1, double const& num2)
//{
//	return num1 / CComplex(num2);
//}

//CComplex operator/(double const& num1, CComplex const& num2)
//{
//	return CComplex(num1) / num2;
//}


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

std::ostream& operator<<(std::ostream& os, CComplex const& num)
{
	if (num.Im() >= 0)
	{
		os << num.Re() << '+' << num.Im() << 'i';
	}
	else
	{
		os << num.Re() << num.Im() << 'i';
	}
	return os;
}

std::istream& operator>>(std::istream& is, CComplex & num)
{
	std::string value, str_num;
	double real = 0, image = 0;
	is >> value;
	bool err;

	if (value.size() == 1)
	{
		real = StringToDouble(value.c_str(), err);
		if (err)
		{
			std::cout << "error input" << std::endl;
		}
	}
	else
	{
		str_num += value[0];
		for (size_t i = 1; i < value.size(); i++)
		{
			if (value[i] == 'i')
			{
				image = StringToDouble(str_num.c_str(), err);
				if (err)
				{
					std::cout << "error input" << std::endl;
				}
				str_num = "";
			}
			else if (value[i] == '-' || value[i] == '+')
			{
				real = StringToDouble(str_num.c_str(), err);
				if (err)
				{
					std::cout << "error input" << std::endl;
				}
				str_num = value[i];
			}
			else
			{
				str_num += value[i];
			}
		}
	}

	num = CComplex(real, image);
	return is;
}

CComplex::~CComplex()
{
}
