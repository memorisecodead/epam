#include "Note.h"

Note::Note(std::string name, std::string surname, std::string mark, unsigned int taxinum)
	:m_name(name),m_surname(surname),m_mark_of_car(mark),m_taxi_num(taxinum)
{
}

Note::~Note()
{
	m_name = " ";
	m_surname = " ";
	m_mark_of_car = " ";
	m_taxi_num = 0;
}
