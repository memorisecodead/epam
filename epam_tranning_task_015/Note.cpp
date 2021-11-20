#include "Note.h"

Note::Note(std::string name, std::string sur, std::string pat,
	std::string mail, unsigned int count, unsigned int summ)
	:m_name(name),m_surname(sur),m_patronymic(pat),m_mail(mail),m_count_of_purch(count),m_summ_of_purch(summ)
{
}