#include "stdafx.h"
#include "University.h"


CUniversity::CUniversity(std::string name)
			:m_name(name)
{
}

bool CUniversity::SetName(std::string name)
{
	if (name == "")
	{
		return false;
	}
	else
	{
		m_name = name;
		return true;
	}
}

CUniversity::~CUniversity()
{
}
