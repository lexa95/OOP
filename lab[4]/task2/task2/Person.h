#pragma once
#include "University.h"
#include <string>
#include <iostream>

class CPerson
{
public:
	CPerson(bool isMan, int age, int growth, int weigth, std::string name);

	bool SetGender(bool const & isMan);
	bool SetAge(int const & age);
	bool SetGrowth(int const & growth);
	bool SetName(std::string const & name);
	bool SetWeight(int const & weight);

	void PrintDate() const;
	~CPerson();
private:
	bool m_isMan;
	int m_age, m_growth, m_weigth;
	std::string m_name;
};

class CStudent : public CPerson
{
public:
	CStudent(bool isMan, int age, int growth, int weigth, std::string name, int yearOfStudy, CUniversity const university);
	~CStudent();
	bool SetUniversity(CUniversity const university);
	bool SetYearOfStudy(int yearOfStudy);
private:
	CUniversity m_university;
	int m_yearOfStudy;
};