#include "stdafx.h"
#include "../task1/Car.h"

BOOST_AUTO_TEST_CASE(CheckCreatingClass)
{
	CCar myCar;
	BOOST_CHECK(myCar.GetSpeed() == 0);
	BOOST_CHECK(myCar.GetGear() == 0);
	BOOST_CHECK(myCar.GetDirectionOfMotion() == 0);
	BOOST_CHECK(myCar.IsTurnedOn() == false);
}

BOOST_AUTO_TEST_CASE(CheckSpeedOfChange)
{
	CCar myCar;
	BOOST_CHECK(myCar.TurnedOnEngine());
	myCar.SetGear(1);
	BOOST_CHECK(myCar.SetSpeed(20));
	myCar.SetGear(2);
	myCar.SetGear(0);
	BOOST_CHECK(!myCar.SetSpeed(21));
	BOOST_CHECK(myCar.SetSpeed(0));
	myCar.SetGear(-1);
	BOOST_CHECK(myCar.SetSpeed(20));
}

BOOST_AUTO_TEST_CASE(CheckChangesGear)
{
	CCar myCar;
	BOOST_CHECK(myCar.TurnedOnEngine());
	BOOST_CHECK(myCar.SetGear(1));
	myCar.SetSpeed(20);
	BOOST_CHECK(!myCar.SetGear(4));
	BOOST_CHECK(myCar.SetGear(2));
	BOOST_CHECK(myCar.SetGear(0));
	BOOST_CHECK(!myCar.SetGear(-1));
	myCar.SetSpeed(0);
	BOOST_CHECK(myCar.SetGear(-1));
	myCar.SetSpeed(20);
	BOOST_CHECK(!myCar.SetGear(1));
}