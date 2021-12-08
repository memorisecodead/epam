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
	const unsigned int & getAge();
	const unsigned int & getAge() const;
	void setName(std::string name);
	const std::string & getName();
	const std::string & getName() const;
	void setSurname(std::string surname);
	const std::string & getSurname();
	const std::string & getSurname() const;
	void setGroup(std::string group);
	const std::string & getGroup();
	const std::string & getGroup() const;
	void setFaculty(std::string faculty);
	const std::string & getFaculty();
	const std::string & getFaculty() const;

	~Student();

private:
	std::string m_name;
	std::string m_surname;
	unsigned int m_age;
	std::string m_group;
	std::string m_faculty;
};

bool compareAge(Student * rhs, Student * lhs);

void dataPush(Student* st);

void outputLog(Student& st, const char* mess);
