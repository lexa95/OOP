#include "stdafx.h"
#include "../task7/ReadFromFile.h"

BOOST_AUTO_TEST_CASE(EmptyFileProducesEmptySet)
{
	std::set<std::string> database;
	BOOST_CHECK(ReadFromFile(database, "EmplyFile.txt", AddNameToSet));
	BOOST_CHECK(database.empty());
}

BOOST_AUTO_TEST_CASE(IncorrectFileNameProducesFalse)
{
	std::set<std::string> database;
	BOOST_CHECK(!ReadFromFile(database, "", AddNameToSet));
}

BOOST_AUTO_TEST_CASE(CheckingTheResult)
{
	std::set<std::string> database;
	std::set<std::string> result;
	result.insert("line1");
	result.insert("line2");
	result.insert("line3");
	BOOST_CHECK(ReadFromFile(database, "TestFile.txt", AddNameToSet));
	BOOST_CHECK(database == result);
}