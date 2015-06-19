#include "stdafx.h"
#include "..\task3\MyStringList.h"
#include <iostream>
#include <string>

using namespace std;

BOOST_AUTO_TEST_CASE(Test)
{
	CMyStringList list; 
	list.Append("1111111111");

	BOOST_CHECK(list.End() == list.Begin());
	BOOST_CHECK((*list.End()) == "1111111111");
}

BOOST_AUTO_TEST_CASE(EmptyLIst)
{
	CMyStringList list;
	bool isError = false;

	try
	{
		list.End();
	}
	catch (logic_error const)
	{
		isError = true;
	}

	BOOST_CHECK(isError);
}

BOOST_AUTO_TEST_CASE(TestRemove)
{
	CMyStringList list;
	list.Append("1");
	list.Append("2");
	list.Append("3");
	list.Append("4");
	list.Append("5");

	auto it = list.Begin();
	list.Remove(it);
	BOOST_CHECK(*list.Begin() == "2");
	it = list.End();
	list.Remove(it);
	BOOST_CHECK(*list.End() == "4");

	it = list.Begin();
	it++;
	list.Remove(it);
	BOOST_CHECK(*list.Begin() == "2");
	BOOST_CHECK(*list.End() == "4");
}

BOOST_AUTO_TEST_CASE(TestInsert)
{
	CMyStringList list;
	list.Append("1");
	list.Append("2");
	list.Append("3");
	list.Append("4");
	list.Append("5"); 

	auto it = list.Begin();
	list.Insert(it, "#1");
	BOOST_CHECK((*list.Begin()++) == "#1");
	it = list.End();
	list.Insert(it, "#2");
	BOOST_CHECK(*list.End() == "#2");
}

BOOST_AUTO_TEST_CASE(TestAppend)
{
	CMyStringList list;
	list.Append("1");
	list.Append("2");
	BOOST_CHECK((*list.Begin()) == "1");
	BOOST_CHECK((*list.End()) == "2");
}

BOOST_AUTO_TEST_CASE(TestMoving)
{
	CMyStringList list;
	list.Append("1");
	list.Append("2");

	auto It = list.Begin();
	It++;
	BOOST_CHECK(*It == *list.End());
	It--;
	BOOST_CHECK(*It == *list.Begin());

	bool isError = false;
	try
	{
		It--;
	}
	catch (out_of_range &)
	{
		isError = true;
	}
	BOOST_CHECK(isError);
}