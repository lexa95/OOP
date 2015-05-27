#include "stdafx.h"
#include "Body.h"


CBody::CBody(double density, double volume)
		:m_density(density), m_volume(volume)
{
	m_weight = density * volume;
}

void CBody::ShowDate(std::ostream & output) const
{
	output << "Density = " << m_density << std::endl;
	output << "Volume  = " << m_volume << std::endl;
	output << "Weight  = " << m_weight << std::endl;
}

double CBody::GetWeight() const
{
	return m_weight;
}

double CBody::GetDensityt()const
{
	return m_density;
}

double CBody::GetVolume()const
{
	return m_volume;
}

CBody::~CBody()
{
}
