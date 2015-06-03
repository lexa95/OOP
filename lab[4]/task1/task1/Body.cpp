#include "stdafx.h"
#include "Body.h"


CBody::CBody(double density, double volume)
		:m_density(density), m_weight(density * volume)
{
}

void CBody::ShowDate(std::ostream & output) const
{
	output << "Density = " << GetDensity() << std::endl;
	output << "Volume  = " << GetVolume() << std::endl;
	output << "Weight  = " << GetWeight() << std::endl;
}

double CBody::GetWeight() const
{
	return m_weight;
}

double CBody::GetDensity()const
{
	return m_density;
}

CBody::~CBody()
{
}
