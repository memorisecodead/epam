#include "Users.h"
#include "customQueue.h"

Users::Users()
	: u_notes(nullptr),u_size(0)
{
}

void Users::addNote(Note note)
{
	if (u_notes == nullptr)
	{
		u_notes = new Note[++u_size];
		u_notes[0] = note;

		std::cout << "The fist note of user is added: " << u_notes[0].m_name << " | "
			<< u_notes[0].m_surname << " | " << u_notes[0].m_patronymic
			<< " | " << u_notes[0].m_mail << " | " << u_notes[0].m_count_of_purch 
			<< " | " << u_notes[0].m_summ_of_purch << std::endl;
	}
	else
	{
		Note* temp_note = new Note[u_size];

		for (auto i = 0; i < u_size; ++i)
		{
			temp_note[i] = u_notes[i];
		}
		delete[] u_notes;
		u_notes = nullptr;

		u_notes = new Note[u_size + 1];

		for (int i = 0; i < u_size; ++i)
		{
			u_notes[i] = temp_note[i];
		}

		++u_size;
		u_notes[u_size - 1] = note;

		std::cout << u_size << " note of user is added: " << u_notes[u_size - 1].m_name << " | "
			<< u_notes[u_size - 1].m_surname << " | " << u_notes[u_size - 1].m_patronymic
			<< " | " << u_notes[u_size - 1].m_mail << " | " << u_notes[u_size - 1].m_count_of_purch
			<< " | " << u_notes[u_size - 1].m_summ_of_purch << std::endl;

		delete[] temp_note;
		temp_note = nullptr;
	}
}

void Users::deleteNote(const unsigned int & index)
{
	if (index > u_size || index < u_size)
	{
		std::cout << "You coudn't delete note\n";
		system("cls");
	}
	else
	{
		Note* temp_note = new Note[u_size - 1];

		for (int i = 0; i < u_size; ++i)
		{
			if (index - 1 != i)
			{
				temp_note[i] = u_notes[i];
			}
		}

		delete[] u_notes;
		u_notes = temp_note;

		std::cout << u_size - 1 << " note is deleted.\n";
		--u_size;
	}
}

void Users::frequentBuyers(Note * note)
{
	for (auto i = 0; i < 1; ++i)
	{
		if (note[i].m_summ_of_purch >= 10)
		{
			std::cout << "Frequent buyer: " << std::endl
				<< note[i].m_name << " | " << note[i].m_surname << " | "
				<< note[i].m_patronymic << " | " << note[i].m_mail
				<< note[i].m_count_of_purch << " | " << note[i].m_summ_of_purch
				<< std::endl;
		}

	}
}

void Users::infrequentBuyers(Note * note)
{
	for (auto i = 0; i < 1; ++i)
	{
		if (note[i].m_summ_of_purch < 10)
		{
			std::cout << "Infrequent buyer: " << std::endl
				<< note[i].m_name << " | " << note[i].m_surname << " | "
				<< note[i].m_patronymic << " | " << note[i].m_mail
				<< note[i].m_count_of_purch << " | " << note[i].m_summ_of_purch
				<< std::endl;
		}
	}
}

std::string Users::getName()
{
	return u_notes->m_name;
}

std::string Users::getSurname()
{
	return u_notes->m_surname;
}

std::string Users::getPatronymic()
{
	return u_notes->m_patronymic;
}

std::string Users::getEmail()
{
	return u_notes->m_mail;
}

unsigned int Users::countOfPurch()
{
	return u_notes->m_count_of_purch;
}

unsigned int Users::summOfPurch()
{
	return u_notes->m_summ_of_purch;
}

Users::~Users()
{
	u_notes = nullptr;
	u_size = 0;
}
