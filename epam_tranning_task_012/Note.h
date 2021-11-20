#pragma once
#include <iostream>
#include <string>

class Note
{
public:
	Note() = default;
	Note(std::string name, std::string surname, std::string	mark, unsigned int taxinum);
	~Note();

	unsigned int m_taxi_num;
	std::string m_mark_of_car;
	std::string	m_name;
	std::string m_surname;
};