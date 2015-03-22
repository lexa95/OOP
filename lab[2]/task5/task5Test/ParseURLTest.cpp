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

BOOST_AUTO_TEST_CASE(ChackResulParseURL)
{
	Protocol protocol;
	int port;
	std::string host;
	std::string document;
	BOOST_CHECK(!ParseURL("http://", protocol, port, host, document));
	BOOST_CHECK(!ParseURL("http://ewerwer", protocol, port, host, document));
	BOOST_CHECK(ParseURL("http://google.com", protocol, port, host, document));
	BOOST_CHECK(ParseURL("http://www.google.com/page", protocol, port, host, document));
	BOOST_CHECK(protocol == HTTP);
	BOOST_CHECK(port == 80);
	BOOST_CHECK(host == "www.google.com");
	BOOST_CHECK(document == "/page");
}

BOOST_AUTO_TEST_CASE(ChackResuUpperCase)
{
	BOOST_CHECK(UpperCase("cat") == "CAT");
	BOOST_CHECK(UpperCase("cAt") == "CAT");
	BOOST_CHECK(UpperCase("test") == "TEST");
	BOOST_CHECK(UpperCase("tESt") == "TEST");
}
