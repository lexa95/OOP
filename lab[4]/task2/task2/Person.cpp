#include "stdafx.h"
#include "Person.h"


CPerson::CPerson(bool isMan, int age, int growth, int weigth, std::string name)
		:m_isMan(isMan), m_age(age), m_growth(growth), m_weigth(weigth), m_name(name)
{
}

void CPerson::PrintDate() const
{
	std::cout << "name: " << m_name << ", growth: " << m_growth << ", age: " << m_age << ", gender: " << (m_isMan ? 'M' : 'W') << ", weigth: " << m_weigth;
}

bool CPerson::SetGender(bool const & isMan)
{
	if (m_isMan == isMan)
	{
		return false;
	}
	else
	{
		m_isMan = isMan;
		return true;
	}
}

bool CPerson::SetAge(int const & age)
{
	if (age < m_age)
	{
		return false;
	}
	else
	{
		m_age = age;
		return true;
	}
}

bool CPerson::SetGrowth(int const & growth)
{
	if (growth < m_growth)
	{
		return false;
	}
	else
	{
		m_growth = growth;
		return true;
	}
}

bool CPerson::SetName(std::string const & name)
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

bool CPerson::SetWeight(int const & weight)
{
	if (weight <= 0)
	{
		return false;
	}
	else
	{
		m_weigth = weight;
		return false;
	}
}

CPerson::~CPerson()
{
}

CStudent::CStudent(bool isMan, int age, int growth, int weigth, std::string name, int yearOfStudy, CUniversity const university)
:m_yearOfStudy(yearOfStudy), m_university(university), CPerson(isMan, age, growth, weigth, name)
{
}

CStudent::~CStudent()
{
}

bool CStudent::SetUniversity(CUniversity const university)
{
	m_university = university;
}

bool CStudent::SetYearOfStudy(int yearOfStudy)
{
	if (yearOfStudy > 6 || yearOfStudy > 1)
	{
		return false;
	}
	else
	{
		m_yearOfStudy = yearOfStudy;
		return true;
	}
}