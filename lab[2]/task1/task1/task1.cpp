#include "stdafx.h"
#include "ProcessVectors.h"

using namespace std;

void PrintArray(const vector<double> numbers)
{
	for (auto number : numbers)
	{
		cout << number << ' ';
	}
}

int main(int argc, char* argv[])
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
		
	PrintArray(ProcessVector(numbers));

	_getch();
	return 0;
}