#pragma once
class CComplex
{
public: 
	CComplex(double real = 0, double image = 0);

	double Re() const;
	double Im() const;
	double GetArgument()const;
	double GetMagnitude()const;

	CComplex operator +(CComplex const& num);
	CComplex operator +(double const& num);
	~CComplex();
private:
	double m_real, m_image;
};

