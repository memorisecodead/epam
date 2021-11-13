#include <iostream>
#include "myHuman.h"

Human::Human()
	: m_name(" "),m_surname(" "), m_age(0)
{
}

Human::~Human()
{
	m_name = " ";
	m_surname = " ";
	m_age = 0;
}

std::string & Human::getName()
{
	return m_name;
}

void Human::setName(std::string name)
{
	m_name = name;
}

std::string & Human::getSurName()
{
	return m_surname;
}

void Human::setSurName(std::string surname)
{
	m_surname = surname;
}

unsigned int & Human::getAge()
{
	return m_age;
}

void Human::setAge(unsigned int age)
{
	m_age = age;
}

void Human::printInfo()
{
	std::cout << "Name: " << std::setw(4) << m_name << std::endl;
	std::cout << "Surname: " << std::setw(4) << m_surname << std::endl;
	std::cout << "Age: " << std::setw(4) << m_age << std::endl;
}
