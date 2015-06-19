// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMyArray.h"
#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;

int main(int argc, char* argv[])
{	
	CMyArray<std::string> arr;
	arr.Add("1234567890");
	arr.Add("abcdifj");
	cout << arr[0] << endl;
	return 0;
}

