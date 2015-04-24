#pragma once
class CComplex
{
public: 
	CComplex(int x, int y);
	int GetX() const;
	int GetY() const;

	CComplex operator +(CComplex const& num);
	~CComplex();
private:
	int m_x, m_y;
};

