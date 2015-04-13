#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>

class CBody
{
public:
	CBody(double density, double volume);
	~CBody();

	void ShowDate()const;
	double m_density, m_volume, m_weight;
};

class CSphere : public CBody
{
public:
	CSphere(double radius, double density)
		: m_radius(radius) , CBody(density, Volume(radius))
	{
	}
private:
	double Volume(double radius)
	{
		return (pow(radius, 3) * 4 * M_PI)/3;
	}
	double m_radius;
};

class CParallelepiped : public CBody
{
public:
	CParallelepiped(double width, double height, double depth, double density)
		: m_width(width), m_height(height), m_depth(depth), CBody(density, Volume(width, height, depth))
	{}

private:
	double Volume(double width, double height, double depth)
	{
		return width * height * depth;
	}
	double m_width, m_height, m_depth;
};

class CCone : public CBody
{
public:
	CCone(double radius, double height, double density) 
		: m_radius(radius), m_height(height), CBody(density, Volume(radius, height))
	{
	}
	
private:
	double Volume(double radius, double height)
	{
		return M_PI * pow(radius, 2) * height / 3;
	}
	double m_radius, m_height;
};

class CCylinder : public CBody
{
public:
	CCylinder(double radius, double height, double density)
		: m_radius(radius), m_height(height), CBody(density, Volume(radius, height))
	{}

private:
	double Volume(double radius, double height)
	{
		return M_PI * pow(radius, 2) * height;
	}
	double m_radius, m_height;
};

class CCompound : public CBody
{
public:
	CCompound(CBody main) :CBody(main)
	{
		m_array.push_back(main);
	};
	void AddObject(CBody object)
	{
		m_array.push_back(object);
		UpdateDate();
	}
	
private:
	void UpdateDate()
	{
		double density = 0;
		double volume = 0;
		double weight = 0;

		for (size_t i = 0; i < m_array.size(); i++)
		{
			density += m_array[i].m_density;
			volume  += m_array[i].m_volume;
			weight  += m_array[i].m_weight;
		}
		m_density = density / m_array.size();
		m_volume = volume;
		m_weight = weight;
	}
	std::vector<CBody> m_array;
};