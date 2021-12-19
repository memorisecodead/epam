#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Note.h"

Note::Note(std::string name, std::string surname, std::string patronymic, std::string mail, std::string number)
	: m_name(name), m_surname(surname), m_patronymic(patronymic), m_mail(mail), m_number(number)
{
}
