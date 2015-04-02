#pragma once

#include "stdafx.h"

class CCar
{
public:
	CCar();
	~CCar();
	
	const int maxSpeed = 150;

	const int ago     = -1;
	const int stand   = 0;
	const int forward = 1;

	const int reverse = -1;
	const int neutral = 0;
	const int first   = 1;
	const int second  = 2;
	const int third   = 3;
	const int fourth  = 4;
	const int fifth   = 5;

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
	int m_gear, m_speed, m_directionOfMotion;
	bool m_isTurnedOn;
};

