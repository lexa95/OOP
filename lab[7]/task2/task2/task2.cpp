// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMyArray.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{	
	CMyArray<int> ar;
	ar.Add(10);
	cout << ar[0] << endl;
	return 0;
}

