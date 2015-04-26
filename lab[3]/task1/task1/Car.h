#pragma once

#include "stdafx.h"

class CCar
{
public:
	CCar();
	~CCar();
	
	const int maxSpeed = 150;
	std::map<int, std::vector<int>> speedRange;

	bool TurnedOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

	std::map<int, std::vector<int>> GetSpeedRange() const;
	int GetSpeed() const;
	int GetGear() const;
	int GetDirectionOfMotion() const;
	bool IsTurnedOn() const;

private:
	enum StateOfMotion
	{
		ago     = -1,
		stand   =  0,
		forward =  1,
	};

	enum GearBox
	{
		reverse = -1,
		neutral = 0,
		first   = 1,
		second  = 2,
		third   = 3,
		fourth  = 4,
		fifth   = 5,
	};

	int m_directionOfMotion;
	StateOfMotion m_speed;
	GearBox m_gear;
	bool m_isTurnedOn;
};

