#include "stdafx.h"
#include "Body.h"


CBody::CBody(double density, double volume)
		:m_density(density), m_volume(volume)
{
	m_weight = density * volume;
}

void CBody::ShowDate() const
{
	std::cout << "Density = " << m_density << std::endl;
	std::cout << "Volume  = " << m_volume  << std::endl;
	std::cout << "Weight  = " << m_weight  << std::endl;
	std::cout << "=======================" << std::endl;
}

CBody::~CBody()
{
}
