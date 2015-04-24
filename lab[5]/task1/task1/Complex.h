#pragma once
class CComplex
{
public: 
	CComplex(double real = 0, double image = 0);

	double Re() const;
	double Im() const;
	double GetArgument()const;
	double GetMagnitude()const;

	friend CComplex operator+(CComplex const& num1, CComplex const& num2);
	friend CComplex operator+(CComplex const& num1, double const& num2);
	friend CComplex operator+(double const& num1, CComplex const& num2);
	CComplex operator+();

	friend CComplex operator-(CComplex const& num1, CComplex const& num2);
	friend CComplex operator-(CComplex const& num1, double const& num2);
	friend CComplex operator-(double const& num1, CComplex const& num2);
	CComplex operator-();

	friend CComplex operator*(CComplex num1, CComplex num2);
	friend CComplex operator*(CComplex num1, double num2);
	friend CComplex operator*(double num1, CComplex num2);

	friend CComplex operator/(CComplex num1, CComplex num2);
	friend CComplex operator/(CComplex num1, double num2);
	friend CComplex operator/(double num1, CComplex num2);

	~CComplex();
private:
	double m_real, m_image;
};

