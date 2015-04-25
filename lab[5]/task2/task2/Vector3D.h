#pragma once

#include <fstream>

class CVector3D
{
public:
	// Конструирует нулевой вектор
	CVector3D();
	// Конструирует вектор с заданными координатами
	
	CVector3D(double x0, double y0, double z0);
	// Возвращает длину вектора
	double GetLength()const;
	// Нормализует вектор (приводит его к единичной длине)
	void Normalize();
	// Другие методы и операции класса
	// В данном случа

	CVector3D operator+();
	CVector3D operator-();

	friend CVector3D operator+(CVector3D const& vector1, CVector3D const& vector2);
	friend CVector3D operator-(CVector3D const& vector1, CVector3D const& vector2);

	CVector3D operator+=(CVector3D const& vector);
	CVector3D operator-=(CVector3D const& vector);
	
	friend CVector3D operator*(CVector3D const& vector1, CVector3D const& vector2);
	friend CVector3D operator/(CVector3D const& vector1, CVector3D const& vector2);
	
	CVector3D operator*=(CVector3D const& vector);
	CVector3D operator/=(CVector3D const& vector);

	friend bool operator==(CVector3D const& num1, CVector3D const& num2);
	friend bool operator!=(CVector3D const& num1, CVector3D const& num2);

	friend std::ostream& operator<<(std::ostream& os, CVector3D const& num);
	friend std::istream& operator>>(std::istream& is, CVector3D & num);

	double x, y, z;
};

