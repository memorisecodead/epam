#pragma once
#include <iostream>

class Note
{
public:
	Note() = default;
	Note(std::string name, std::string sur, std::string pat,
		std::string mail, unsigned int count, unsigned int summ);


	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	std::string m_mail;
	unsigned int m_count_of_purch;
	unsigned int m_summ_of_purch;
};