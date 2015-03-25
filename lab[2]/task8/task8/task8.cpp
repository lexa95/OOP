#include "stdafx.h"
#include "ExpandTemplate.h"

using namespace std;

int main(int argc, char* argv[])
{
	string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
	map<string, string> params;
	params["%USER_NAME%"] = "Ivan Petrov";
	params["{WEEK_DAY}"] = "Friday";
	ExpandTemplate(tpl, params);

	system("PAUSE");
	return 0;
}