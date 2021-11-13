#pragma once
#include <iostream>
#include <string>

class Note
{
public:
	Note() = default;
	Note(std::string name, std::string surname, std::string patronymic, std::string mail, std::string number);

	//Note& operator[](const unsigned int& index);

	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	std::string m_mail;
	std::string m_number;
};