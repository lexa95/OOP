#pragma once
#include <string>

class CUniversity
{
public:
	CUniversity(std::string name);
	bool SetName(std::string name);
	~CUniversity();
private:
	std::string m_name;
};