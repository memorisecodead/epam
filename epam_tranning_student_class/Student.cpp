#include "Student.h"

#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Student.h"


Student::Student()
{
	notes = nullptr;
	size = 0;
}

void Student::add_note(Note note)
{
	if (notes == nullptr)
	{
		notes = new Note[++size];
		notes[0] = note;
		std::cout << "1 note is added:\n" << notes[0].m_name << " " << notes[0].m_surname << " " << notes[0].m_patronymic << " " <<
			notes[0].m_mail << " " << notes[0].m_number << std::endl << std::endl;
	}
	else
	{
		Note* temp_notes = new Note[size];

		for (int i = 0; i < size; ++i)
		{
			temp_notes[i] = notes[i];
		}

		delete[] notes;
		notes = nullptr;

		notes = new Note[size + 1];

		for (int i = 0; i < size; ++i)
		{
			notes[i] = temp_notes[i];
		}

		notes[size] = note;

		std::cout << size + 1 << " Note is added:\n " << notes[size].m_name << " " << notes[size].m_surname << " " << notes[size].m_patronymic << " " <<
			notes[size].m_mail << " " << notes[size].m_number << std::endl << std::endl;

		++size;

		delete[] temp_notes;
		temp_notes = nullptr;
	}


}

void Student::edit_note(const unsigned int& index)
{
	print_inf(index);
	/*std::cout << "Info note #" << index + 1 << ":\n" << notes[index].m_name << std::endl << notes[index].m_surname << std::endl <<
		notes[index].m_patronymic << std::endl << notes[index].m_mail << std::endl << notes[index].m_number << std::endl;

	std::cout << "Edit note #" << index + 1 << ":\n";*/
	std::cin >> notes[index].m_name >> notes[index].m_surname >> notes[index].m_patronymic >> notes[index].m_mail >> notes[index].m_number;

	print_result(index);
	//std::cout << "Edited note:\n " << notes[index].m_name << std::endl << notes[index].m_surname << std::endl <<
	//	notes[index].m_patronymic << std::endl << notes[index].m_mail << std::endl << notes[index].m_number << std::endl;
	//
	//std::cout << "\nEdit was complete.\n";

}

void Student::print_note(const unsigned int& index)
{
	std::cout << "\nInfo note #" << index + 1 << " :\n" << notes[index].m_name << std::endl << notes[index].m_surname << std::endl <<
		notes[index].m_patronymic << std::endl << notes[index].m_mail << std::endl << notes[index].m_number << std::endl;
}

void Student::print_inf(const unsigned int& index)
{
	std::cout << "\nInfo note #" << index + 1 << " :\n" << notes[index].m_name << std::endl << notes[index].m_surname << std::endl <<
		notes[index].m_patronymic << std::endl << notes[index].m_mail << std::endl << notes[index].m_number << std::endl;

	std::cout << "Edit note #" << index + 1 << ":\n";

}

void Student::print_result(const unsigned int& index)
{
	std::cout << "Edited note:\n " << notes[index].m_name << std::endl << notes[index].m_surname << std::endl <<
		notes[index].m_patronymic << std::endl << notes[index].m_mail << std::endl << notes[index].m_number << std::endl;

	std::cout << "\nEdit was complete.\n";

}

void Student::print_all_notes()
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::endl;
		std::cout << "Note:\n " << notes[i].m_name << std::endl << notes[i].m_surname << std::endl <<
			notes[i].m_patronymic << std::endl << notes[i].m_mail << std::endl << notes[i].m_number << std::endl << std::endl;
	}
}

void Student::search_field(const unsigned int& index, const unsigned int& search, std::string& search_fields)
{
	system("cls");

	while (search < 1 && search > 5)
	{
		std::cout << "Enter number from 1 to 5!\n";
	}
	switch (search)
	{
		case (unsigned int)(ChooseEdit::Name) :
		{

			for (int i = 0; i < size; ++i)
			{
				if (notes->m_name == search_fields)
				{
					print_note(index);
				}
				else
				{
					std::cout << "Notes not found\n";
				}
			}

		}
		break;
		case (unsigned int)(ChooseEdit::Surname) :
		{
			for (int i = 0; i < size; ++i)
			{
				if (notes->m_surname == search_fields)
				{
					print_note(index);
				}
				else
				{
					std::cout << "Notes not found\n";
				}
			}
		}
		break;

		case (unsigned int)(ChooseEdit::Patrynomic) :
		{
			for (int i = 0; i < size; ++i)
			{
				if (notes->m_patronymic == search_fields)
				{
					print_note(index);
				}
				else
				{
					std::cout << "Notes not found\n";
				}
			}
		}
		break;

		case (unsigned int)(ChooseEdit::E_mails) :
		{
			for (int i = 0; i < size; ++i)
			{
				if (notes->m_mail == search_fields)
				{
					print_note(index);
				}
				else
				{
					std::cout << "Notes not found\n";
				}
			}
		}
		break;

		case (unsigned int)(ChooseEdit::Numbers) :
		{
			for (int i = 0; i < size; ++i)
			{
				if (notes->m_number == search_fields)
				{
					print_note(index);
				}
				else
				{
					std::cout << "Notes not found\n";
				}
			}
		}
		break;

		default:
		{
			std::cout << "Then you cannot find your notes, remember your note!\n";
		}
	}

}

void Student::notes_sort()
{
	Note temp;
	// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (notes[j].m_name > notes[j + 1].m_name) {
				// меняем элементы местами
				temp = notes[j];
				notes[j] = notes[j + 1];
				notes[j + 1] = temp;
			}
		}
	}
	print_all_notes();

}

void Student::delete_note(const unsigned int& index)
{
	if (index > size || index < size)
	{
		std::cout << "You coudn't delete note\n";
		return;
		system("cls");
	}
	else
	{
		Note* newest_note = new Note[size - 1]{};

		for (int i = 0; i < size; ++i)
		{
			if (index - 1 != i)
			{
				newest_note[i] = notes[i];
			}
		}
		delete[] notes;
		notes = newest_note;

		std::cout << size + 1 << "Note is deleted.\n";
		--size;
	}
}

void Student::choice_edit(const unsigned int& c_index, const unsigned int& index)
{
	switch (c_index)
	{
		case (unsigned int)(ChooseEdit::Name) :
		{
			std::cout << "\nEdit Name.\n\n";
			print_note(index);
			std::cout << "Edit note #" << index + 1 << ":\n\n";
			std::cout << "Enter new Name:\t";
			std::cin >> notes[index].m_name;
			std::cout << "\n\nEdited note:\n";
			std::cout << "_________________\n";
			print_note(index);

			std::cout << "\nEdit was complete.\n";
			system("pause");
			system("cls");
		}
		break;
		{
			case (unsigned int)(ChooseEdit::Surname) :
				std::cout << "\nEdit Surname.\n\n";
				print_note(index);
				std::cout << "Edit note #" << index + 1 << ":\n\n";
				std::cout << "Enter new Surname:\t";
				std::cin >> notes[index].m_surname;
				std::cout << "\n\nEdited note:\n";
				std::cout << "_________________\n";
				print_note(index);

				std::cout << "\nEdit was complete.\n";
				system("pause");
				system("cls");
		}
		break;
		case (unsigned int)(ChooseEdit::Patrynomic) :
		{
			std::cout << "\nEdit Patrynomic.\n\n";
			print_note(index);
			std::cout << "Edit note #" << index + 1 << ":\n\n";
			std::cout << "Enter new Patrynomic:\t";
			std::cin >> notes[index].m_patronymic;
			std::cout << "\n\nEdited note:\n";
			std::cout << "_________________\n";
			print_note(index);

			std::cout << "\nEdit was complete.\n";
			system("pause");
			system("cls");

		}
		break;
		case (unsigned int)(ChooseEdit::E_mails) :
		{
			std::cout << "\nEdit E_mails.\n\n";
			print_note(index);
			std::cout << "Edit note #" << index + 1 << ":\n\n";
			std::cout << "Enter new E_mails:\t";
			std::cin >> notes[index].m_mail;
			std::cout << "\n\nEdited note:\n";
			std::cout << "_________________\n";
			print_note(index);

			std::cout << "\nEdit was complete.\n";
			system("pause");
			system("cls");
		}
		break;
		case (unsigned int)(ChooseEdit::Numbers) :
		{
			std::cout << "\nEdit Numbers.\n\n";
			print_note(index);
			std::cout << "Edit note #" << index + 1 << ":\n\n";
			std::cout << "Enter new Numbers:\t";
			std::cin >> notes[index].m_mail;
			std::cout << "\n\nEdited note:\n";
			std::cout << "_________________\n";
			print_note(index);

			std::cout << "\nEdit was complete.\n";
			system("pause");
			system("cls");
		}
		break;
	}
}

Note* Student::get_notes()
{
	return notes;
}

const unsigned int& Student::get_size()
{
	return size;
}
