#include "stdafx.h"
#include "../task5/ParseURL.h"

BOOST_AUTO_TEST_CASE(ChackResultGetStringToSubstring)
{
	std::string line = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
	BOOST_CHECK(GetStringToSubstring(line, "://") == "http");
	BOOST_CHECK(GetStringToSubstring(line, "/") == "http:");
	BOOST_CHECK(GetStringToSubstring(line, "www") == "http://");
	BOOST_CHECK(GetStringToSubstring(line, ".com") == "http://www.mysite");
	BOOST_CHECK(GetStringToSubstring(line, "docs") == "http://www.mysite.com/");
	BOOST_CHECK(GetStringToSubstring(line.substr(strlen("http://")), "/") == "www.mysite.com");
}