#pragma once
#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <vector>
#include "stdafx.h"

using namespace std;

class CBody
{
public:
	typedef boost::shared_ptr<CBody> SPtr;
	CBody(double density = 0, double volume = 0);
	virtual ~CBody();

	void ShowDate(std::ostream & output)const;

	double GetWeight(void)const;
	double GetDensity(void)const;

	virtual double GetVolume(void)const = 0;

	double m_density, m_weight;
};

class CSphere : public CBody
{
public:
	CSphere(double radius, double density)
		: m_radius(radius) , CBody(density)
	{
		m_weight = GetVolume() * density;
	}
	double GetVolume() const
	{
		return (pow(m_radius, 3) * 4 * M_PI) / 3;
	}
private:
	double m_radius;
};

class CParallelepiped : public CBody
{
public:
	CParallelepiped(double width, double height, double depth, double density)
		: m_width(width), m_height(height), m_depth(depth), CBody(density)
	{
		m_weight = GetVolume() * density;
	}
	virtual double GetVolume() const override
	{
		return m_width * m_height * m_depth;
	}
private:
	double m_width, m_height, m_depth;
};

class CCone : public CBody
{
public:
	CCone(double radius, double height, double density) 
		: m_radius(radius), m_height(height), CBody(density)
	{
		m_weight = GetVolume() * density;
	}
	
	double GetVolume() const
	{
		return M_PI * pow(m_radius, 2) * m_height / 3;
	}
private:
	double m_radius, m_height;
};

class CCylinder : public CBody
{
public:
	CCylinder(double radius, double height, double density)
		: m_radius(radius), m_height(height), CBody(density)
	{
		m_volume = GetVolume();
		m_weight = GetVolume() * density;
	}
	double GetVolume() const
	{ 
		return M_PI * pow(m_radius, 2) * m_height;
	}
private:
	double m_radius, m_height, m_volume;
};

class CCompound : public CBody
{
public:
	CCompound() :CBody(), m_volume(0){};
	double GetVolume() const
	{
		return m_volume;
	}

	bool AddShape(SPtr & shape)
	{
		if (!SearchForItems(shape))
		{
			UpdateDate(shape);
			return true;
		}
		return false;
	}

	bool SearchForItems(SPtr & shape)
	{
		bool isCompound = false;
		CCompound * temp = dynamic_cast<CCompound*>(shape.get());
		if (temp)
		{
			isCompound = true;
		}
		
		for (size_t i = 0; i < m_array.size(); i++)
		{
			CCompound * tempi = dynamic_cast<CCompound*>(m_array[i].get());
			if (tempi)
			{
				if (tempi->SearchForItems(shape) || m_array[i] == shape)
				{
					return true;
				}
			}
			else
			{
				if (shape == m_array[i])
				{
					return true;
				}
			}

			if (isCompound)
			{
				if (temp->SearchForItems(m_array[i]))
				{
					return true;
				}
			}
		}

		return false;
	}
	
private:
	void UpdateDate(SPtr & shape)
	{
		m_density = ((m_density * m_array.size()) + (*shape.get()).GetDensity()) / (m_array.size() + 1);
		m_volume = m_volume + (*shape.get()).GetVolume();
		m_weight = m_weight + (*shape.get()).GetWeight();
		m_array.push_back(shape);
	}
	std::vector<SPtr> m_array;
	double m_volume;
};