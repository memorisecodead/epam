#include "TaxiCustom.h"

TaxiCustom::TaxiCustom()
	:notes(nullptr),tripOfTaxi(false),m_countOfDriver(0)
{
}

void TaxiCustom::addNote(Note note)
{
	if (notes == nullptr)
	{
		notes = new Note[++m_countOfDriver];
		notes[0] = note;
		
		std::cout << "The fist note of taxi is added: " << notes[0].m_name << " | "
			<< notes[0].m_surname << " | " << notes[0].m_mark_of_car
			<< " | " << notes[0].m_taxi_num << std::endl;
	}
	else
	{
		Note * temp_note = new Note[m_countOfDriver];
		
		for (auto i = 0; i < m_countOfDriver; ++i)
		{
			temp_note[i] = notes[i];
		}
		delete [] notes;
		notes = nullptr;

		notes = new Note[m_countOfDriver + 1];

		for (auto i = 0; i < m_countOfDriver; ++i)
		{
			notes[i] = temp_note[i];
		}
		++m_countOfDriver;
		notes[m_countOfDriver - 1] = note;

		std::cout << m_countOfDriver << " note of taxi is added: " << notes[m_countOfDriver - 1].m_name
			<< " | " << notes[m_countOfDriver - 1].m_surname << " | " << notes[m_countOfDriver - 1].m_mark_of_car
			<< " | " << notes[m_countOfDriver - 1].m_taxi_num << std::endl;

		delete[] temp_note;
		temp_note = nullptr;
	}
}

void TaxiCustom::editNote(const unsigned int& index)
{
	printInf(index);
	std::cin >> notes[index].m_name >> notes[index].m_surname 
		>> notes[index].m_mark_of_car >> notes[index].m_taxi_num;
	printResult(index);
}

void TaxiCustom::printNoteOfTaxi(const unsigned int & index)
{
	std::cout << "\nInfo of taxi note " << index + 1 << ":\n"
		<< "Name:" << std::setw(4) << notes[index].m_name <<
		"Surname:" << std::setw(4) << notes[index].m_surname <<
		"Mark of car:" << std::setw(4) << notes[index].m_mark_of_car <<
		"Taxi nums:" << std::setw(4) << notes[index].m_taxi_num << std::endl;
}

void TaxiCustom::printInf(const unsigned int& index)
{
	std::cout << "\nInfo note #" << index + 1 << " :\n" << notes[index].m_name 
		<< std::endl << notes[index].m_surname << std::endl 
		<< notes[index].m_mark_of_car << std::endl << notes[index].m_taxi_num 
		<< std::endl;

	std::cout << "Edit note #" << index + 1 << ":\n";
}

void TaxiCustom::printResult(const unsigned int& index)
{
	std::cout << "Edited note:\n " << notes[index].m_name
		<< std::endl << notes[index].m_surname << std::endl
		<< notes[index].m_mark_of_car << std::endl << notes[index].m_taxi_num
		<< std::endl;

	std::cout << "\nEdit was complete.\n";
}

void TaxiCustom::choiceEdit(const unsigned int& ch_index, const unsigned int& index)
{
	switch (ch_index)
	{
		case (unsigned int)(ChooseEdit::Name) :
		{
			std::cout << "\nEdit name.\n\n";
			printNoteOfTaxi(index);
			std::cout << "Edit note #" << index + 1 << ":\n\n";
			std::cout << "Enter new Name:\t";
			std::cin >> notes[index].m_name;
			std::cout << "\n\nEdited note:\n";
			std::cout << "_________________\n";
			printNoteOfTaxi(index);

			std::cout << "\nEdit was complete.\n";
			system("pause");
			system("cls");
		}
		break;
		{
			case (unsigned int)(ChooseEdit::Surname) :
				std::cout << "\nEdit surname.\n\n";
				printNoteOfTaxi(index);
				std::cout << "Edit note #" << index + 1 << ":\n\n";
				std::cout << "Enter new Surname:\t";
				std::cin >> notes[index].m_surname;
				std::cout << "\n\nEdited note:\n";
				std::cout << "_________________\n";
				printNoteOfTaxi(index);

				std::cout << "\nEdit was complete.\n";
				system("pause");
				system("cls");
		}
		break;
		case (unsigned int)(ChooseEdit::MarkOfCar) :
		{
			std::cout << "\nEdit mark of car.\n\n";
			printNoteOfTaxi(index);
			std::cout << "Edit note #" << index + 1 << ":\n\n";
			std::cout << "Enter new Patrynomic:\t";
			std::cin >> notes[index].m_mark_of_car;
			std::cout << "\n\nEdited note:\n";
			std::cout << "_________________\n";
			printNoteOfTaxi(index);

			std::cout << "\nEdit was complete.\n";
			system("pause");
			system("cls");

		}
		break;
		case (unsigned int)(ChooseEdit::TaxiNums) :
		{
			std::cout << "\nEdit Taxi nums.\n\n";
			printNoteOfTaxi(index);
			std::cout << "Edit note #" << index + 1 << ":\n\n";
			std::cout << "Enter new E_mails:\t";
			std::cin >> notes[index].m_taxi_num;
			std::cout << "\n\nEdited note:\n";
			std::cout << "_________________\n";
			printNoteOfTaxi(index);

			std::cout << "\nEdit was complete.\n";
			system("pause");
			system("cls");
		}
		break;
	}
}

bool TaxiCustom::localeOfTaxi(unsigned int & index)
{
	unsigned int taxiCode = 0;
	std::cout << "Departure taxi:" << std::endl;
	std::cout << "Enter a taxi nums:" << std::setw(3);
	std::cin >> taxiCode;

	if (taxiCode != notes[index].m_taxi_num)
	{
		std::cout << notes[index].m_name << " driver don't in a trip!"
			<< std::endl;
		tripOfTaxi = 0;
	}
	else
	{
		std::cout << notes[index].m_name << " Driver in a trip."
			<< std::endl;
		tripOfTaxi = 1;
	}

	return tripOfTaxi;
}

bool TaxiCustom::freeTaxi(unsigned int & index)
{
	unsigned int taxiCode = 0;
	std::cout << "Taxi release:" << std::endl;
	std::cout << "Enter a taxi nums:" << std::setw(3);
	std::cin >> taxiCode;

	if (taxiCode != notes[index].m_taxi_num)
	{
		std::cout << notes[index].m_name << " Taxi don't free!"
			<< std::endl;
		tripOfTaxi = 0;
	}
	else
	{
		std::cout << notes[index].m_name << " Taxi free."
			<< std::endl;
		tripOfTaxi = 1;
	}

	return tripOfTaxi;
}

void TaxiCustom::deleteNote(const unsigned int & index)
{
	if (index > m_countOfDriver)
	{
		std::cout << "You coudn't delete note\n";
		return;
		system("cls");
	}
	else
	{
		Note * newest_note = new Note[m_countOfDriver - 1]{};

		for (auto i = 0; i < m_countOfDriver; ++i)
		{
			if (index - 1 != i)
			{
				newest_note[i] = notes[i];
			}
		}
		delete[] notes;
		notes = newest_note;

		std::cout << m_countOfDriver + 1 << "Note is deleted.\n";
		--m_countOfDriver;
	}
}

void TaxiCustom::printAllTaxis()
{
	for (auto i = 0; i < m_countOfDriver; ++i)
	{
		std::cout << std::endl;
		std::cout << "Note: " << i + 1 << std::endl
			<< notes[i].m_name << std::endl << notes[i].m_surname 
			<< std::endl << notes[i].m_mark_of_car << std::endl << notes[i].m_taxi_num
			<< std::endl << std::endl;
	}
}

Note * TaxiCustom::getNotes()
{
	return notes;
}

const unsigned int & TaxiCustom::getSizeOfNote()
{
	return m_countOfDriver;
}
