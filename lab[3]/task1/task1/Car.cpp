#include "stdafx.h"
#include "Car.h"


CCar::CCar() 
		:m_gear(neutral), m_isTurnedOn(false),
		m_directionOfMotion(stand), m_speed(StateOfMotion(0))
{
	speedRange[reverse] = { 0, 20 };
	speedRange[neutral] = { 0, maxSpeed };
	speedRange[first]   = { 0, 30 };
	speedRange[second]  = { 20, 50 };
	speedRange[third]   = { 30, 60 };
	speedRange[fourth]  = { 40, 90 };
	speedRange[fifth]   = { 50, maxSpeed };
}

bool CCar::TurnedOnEngine()
{
	if (!m_isTurnedOn)
	{
		m_isTurnedOn = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if (m_isTurnedOn && m_gear == neutral && m_speed == 0)
	{
		m_isTurnedOn = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::SetGear(int gear)
{
	if (!(gear >= -1 && gear <= 5))
	{
		return false;
	}
	
	else if (gear == m_gear)
	{
		return true;
	}

	else if (m_speed >= speedRange[gear][0] && m_speed <= speedRange[gear][1])
	{
		if (gear == reverse)
		{
			if ((m_gear == neutral && m_speed == 0) || (m_gear == first && m_speed == 0))
			{
				m_gear = GearBox(gear);
				return true;
			}
		}
		else if (m_gear == reverse && gear == first)
		{
			if (m_speed == 0)
			{
				m_gear = GearBox(gear);
				return true;
			}
		}
		else if (m_gear == neutral && gear == first)
		{
			if (m_directionOfMotion == stand || m_directionOfMotion == forward)
			{
				m_gear = GearBox(gear);
				return true;
			}
		}
		else
		{
			m_gear = GearBox(gear);
			return true;
		}
	}
	
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (!m_isTurnedOn)
	{
		return false;
	}

	if (speed >= speedRange[m_gear][0] && speed <= speedRange[m_gear][1])
	{
		if (m_gear == neutral && m_speed < speed)
		{
			return false;
		}
		else
		{
			if (speed == 0)
			{
				m_directionOfMotion = stand;
			}
			else if (m_gear > 0)
			{
				m_directionOfMotion = forward;
			}
			else
			{
				m_directionOfMotion = ago;
			}

			m_speed = StateOfMotion(speed);
			return true;
		}
	}
	return false;
}

int CCar::GetSpeed()const
{
	return m_speed;
}

int CCar::GetGear()const
{
	return m_gear;
}

int CCar::GetDirectionOfMotion()const
{
	return m_directionOfMotion;
}

bool CCar::IsTurnedOn()const
{
	return m_isTurnedOn;
}

std::map<int, std::vector<int>> CCar::GetSpeedRange() const
{
	return speedRange;
}

CCar::~CCar()
{
}
