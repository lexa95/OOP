#include "stdafx.h"
#include "../task8/ExpandTemplate.h"
using namespace std;

BOOST_AUTO_TEST_CASE(TestExpandTemplateResult1)
{
	string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
	map<string, string> params;
	params["%USER_NAME%"] = "Ivan Petrov";
	params["{WEEK_DAY}"] = "Friday";
	BOOST_CHECK(ExpandTemplate(tpl, params) == "Hello, Ivan Petrov. Today is Friday.");
}

BOOST_AUTO_TEST_CASE(TestExpandTemplateResult2)
{
	string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
	map<string, string> params;
	params["%USER_NAME%"] = "Super %USER_NAME% {WEEK_DAY}";
	params["{WEEK_DAY}"] = "Friday. {WEEK_DAY}";
	BOOST_CHECK(ExpandTemplate(tpl, params) == "Hello, Super %USER_NAME% {WEEK_DAY}. Today is Friday. {WEEK_DAY}.");
}

BOOST_AUTO_TEST_CASE(TestExpandTemplateResult3)
{
	string const tpl = "-AABBCCCCCABC+";
	map<string, string> params;
	params["A"] = "[a]";
	params["AA"] = "[aa]";
	params["B"] = "[b]";
	params["BB"] = "[bb]";
	params["C"] = "[c]";
	params["CC"] = "[cc]";
	
	BOOST_CHECK(ExpandTemplate(tpl, params) == "-[aa][bb][cc][cc][c][a][b][c]+");
}

BOOST_AUTO_TEST_CASE(TestExpandTemplateEmptyData)
{
	string const tpl = "";
	string const tpl1 = "23 23 24";
	map<string, string> params;
	map<string, string> params1;
	params["%USER_NAME%"] = "Ivan Petrov";
	params["{WEEK_DAY}"] = "Friday";
	BOOST_CHECK(ExpandTemplate(tpl, params) == "");
	BOOST_CHECK(ExpandTemplate(tpl1, params1) == tpl1);
}