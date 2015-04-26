#include "stdafx.h"
#include "../task2/Rectangle.h"

BOOST_AUTO_TEST_CASE(CheckCreationClass)
{
	CRectangle rect(1, 1, 2, 1);
	BOOST_CHECK(rect.GetLeft() == 1);
	BOOST_CHECK(rect.GetTop() == 1);
	BOOST_CHECK(rect.GetWidth() == 2);
	BOOST_CHECK(rect.GetHight() == 1);
	BOOST_CHECK(rect.GetRight() == 3);
	BOOST_CHECK(rect.GetBottom() == 2);
	BOOST_CHECK(rect.GetPerimeter() == 6);
	BOOST_CHECK(rect.GetArea() == 2);
}

BOOST_AUTO_TEST_CASE(CheckIntersect)
{
	CRectangle rect1(5, 2, 9, 5);
	CRectangle rect2(11, 5, 14, 4);
	BOOST_CHECK(rect2.Intersect(rect1));
	BOOST_CHECK(rect1.Intersect(rect2));

	CRectangle rect3(5, 2, 9, 5);
	CRectangle rect4(1, 5, 14, 4);
	BOOST_CHECK(rect4.Intersect(rect3));
	BOOST_CHECK(rect3.Intersect(rect4));

	CRectangle rect5(5, 2, 9, 5);
	CRectangle rect6(14, 5, 14, 4);
	BOOST_CHECK(!rect5.Intersect(rect6));
	BOOST_CHECK(!rect6.Intersect(rect5));
}

BOOST_AUTO_TEST_CASE(CheckSetFunctions)
{
	CRectangle rect(0, 0, 4, 5);
	rect.SetLeft(1);
	BOOST_CHECK(rect.GetLeft() == 1);
	rect.SetLeft(2);
	BOOST_CHECK(rect.GetLeft() == 2);

	rect.SetTop(1);
	BOOST_CHECK(rect.GetTop() == 1);
	rect.SetTop(2);
	BOOST_CHECK(rect.GetTop() == 2);

	rect.SetWidth(1);
	BOOST_CHECK(rect.GetWidth() == 1);
	rect.SetWidth(2);
	BOOST_CHECK(rect.GetWidth() == 2);

	rect.SetHight(1);
	BOOST_CHECK(rect.GetHight() == 1);
	rect.SetHight(2);
	BOOST_CHECK(rect.GetHight() == 2);
}

BOOST_AUTO_TEST_CASE(CheckMoveFunctions)
{
	CRectangle rect(0, 0, 4, 4);
	rect.Move(1, 1);

	BOOST_CHECK(rect.GetTop() == 1);
	BOOST_CHECK(rect.GetLeft() == 1);
	BOOST_CHECK(rect.GetBottom() == 5);
	BOOST_CHECK(rect.GetRight() == 5);
}

BOOST_AUTO_TEST_CASE(CheckScaleFunctions)
{
	CRectangle rect(0, 0, 4, 4);
	rect.Scale(2, 2);

	BOOST_CHECK(rect.GetTop() == 0);
	BOOST_CHECK(rect.GetLeft() == 0);
	BOOST_CHECK(rect.GetBottom() == 8);
	BOOST_CHECK(rect.GetRight() == 8);
}





