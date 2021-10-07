#pragma once
#include <iostream>
#include <iomanip>

class Human
{
public:
	Human();
	~Human();
	std::string & getName();
	void setName(std::string name);
	std::string & getSurName();
	void setSurName(std::string surname);
	unsigned int & getAge();
	void setAge(unsigned int age);

	void printInfo();
	virtual void printUnicPhraze()
	{
		std::cout << "Hello Everyone!" << std::endl;
	} 

private:
	std::string m_name;
	std::string m_surname;
	unsigned int m_age;
};

