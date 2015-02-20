#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <assert.h>

using namespace std;


bool IsOverflow(unsigned long long num)
{
	unsigned int maximum = -1;
	return num > maximum;
}

void TestIsOverflow()
{
	unsigned long long test_val = 4294967295;
	assert(0 == IsOverflow(test_val));
	assert(0 == IsOverflow(1));
	assert(1 == IsOverflow(test_val + 1));
	assert(0 == IsOverflow(test_val - 1));
}

unsigned Fib(int n, bool & err)
{
	unsigned prev = 0;
	unsigned next = 1;
	err = false;

	for (int i(0); i < n ; i++)
	{
		if (IsOverflow(unsigned long long(next) + unsigned long long(prev)))
		{
			err = true;
			return prev;
		}
		next += prev;
		prev = next - prev;
	}
	return prev;
}

void TectFib()
{
	bool err;
	assert(0 == Fib(0, err));
	assert(1 == Fib(1, err));
	assert(1 == Fib(2, err));
	assert(2 == Fib(3, err));
	assert(3 == Fib(4, err));
	assert(5 == Fib(5, err));
}

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

void PrintFib(int n)
{	
	int i = 2;
	int num;
	bool err;

	cout << 1;
	while (num = Fib(i, err))
	{
		if (err)
		{
			cout << " OVERFLOW";
			return;
		}
		if ((i-1) % 5 == 0)
		{
			cout << endl;
		}
		else
		{
			cout << ',';
		}
		cout << num;
		i++;
	}
}

int main(int argc, char* argv[])
{
	TestIsOverflow();
	TectFib();

	if (argc != 2)
	{
		cout << "wrong number of arguments." << endl;
		_getch();
		return 1;
	}

	bool err;
	int val = StringToInt(argv[1], err);
	if (err)
	{
		std::cout << "number contains invalid characters." << std::endl;
		_getch();
		return 1;
	}

	if (val < 1)
	{
		std::cout << "number less than one." << std::endl;
		_getch();
		return 1;
	}

	PrintFib(val);

	_getch();
	return 0;
}
