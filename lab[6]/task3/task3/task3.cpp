// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyStringList.h"

using namespace std;

int main()
{
	CMyStringList list;
	list.Append("1");
	list.Append("2");
	list.Append("3");
	list.Append("4");
	list.Append("5");

	auto it = list.Begin();
	list.Remove(it);
	/*BOOST_CHECK(*list.Begin() == "2");*/
	cout << *list.Begin() << endl;
	it = list.End();
	list.Remove(it);
	cout << *list.End() << endl;

	return 0;
}

