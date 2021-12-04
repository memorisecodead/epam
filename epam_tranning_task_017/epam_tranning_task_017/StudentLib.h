#pragma once
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <iostream>
#include "myVector.h"

struct Student
{
	Student();
	explicit Student(std::string name, std::string surname, unsigned int age,
		std::string group, std::string faculty);
	explicit Student(const Student & st);

	Student & operator=(const Student & st);
	friend std::ostream& operator<<
		(std::ostream & out, const Student & st);

	void setAge(unsigned int age);
	const unsigned int & getAge() const;

	void outputLog(const char* mess);

	Student * dataPush(Student * st);

	~Student();

private:
	std::string m_name;
	std::string m_surname;
	unsigned int m_age;
	std::string m_group;
	std::string m_faculty;
};

bool compareAge(Student* rhs, Student* lhs);