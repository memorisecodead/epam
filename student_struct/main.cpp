#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "Student.h"

enum class ChoiceType
{
	AddNote = 1,
	EditNote,
	RemoveNote,
	SortNote,
	SearchNotes,
	PrintAllNotes,
	Exit
};

int main()
{
	Student student_obj;
	unsigned int choose = 0;

	std::fstream student_info;
	student_info.open("info.txt", std::ios::in | std::ios::out);
	if (!student_info.is_open())
	{
		std::cout << "Coudnt open the file." << std::endl;
		exit(EXIT_FAILURE);
	}

	while (true)
	{
		std::cout <<
			"Student\n"
			"---------------\n"
			"1. Add note.\n"
			"2. Edit note.\n"
			"3. Remove note\n"
			"4. Sort notes.\n"
			"5. Search notes\n"
			"6. Print all notes\n"
			"7. Exit.\n"
			"---------------\n\n"
			"Select menu item: ";

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> choose;
		switch (choose)
		{
			case (unsigned int)(ChoiceType::AddNote) :
			{
				system("cls");
				unsigned int humans_count;
				std::cout << "Enter amount of persons: ";
				std::cin >> humans_count;
				std::cout << std::endl;
				Note note;

				for (int i = 0; i < humans_count; ++i)
				{
					std::cout << "Name:\t";
					std::cin >> note.m_name;
					std::cout << "Surname:\t";
					std::cin >> note.m_surname;
					std::cout << "Patronymic:\t";
					std::cin >> note.m_patronymic;
					std::cout << "E-Mail:\t";
					std::cin >> note.m_mail;
					std::cout << "Phone number:\t";
					std::cin >> note.m_number;
					student_obj.add_note(note);
				}
				system("pause");
				system("cls");
			}
			break;

			case(unsigned int)(ChoiceType::EditNote) :
			{
				system("cls");
				unsigned int index;
				unsigned int c_index;
				std::cout << "Enter the index of note: ";
				std::cin >> index;
				std::cout << std::endl;
				std::cout << "Editing by: 1.Name 2.Surname 3.Patronymic 4.Mail 5.Number\n\nSelect:\t";
				std::cin >> c_index;
				std::cout << std::endl;


				if (index > student_obj.get_size() || index < student_obj.get_size())
				{
					std::cout << "out of notes range.\n";
					break;
				}
				else
				{

					student_obj.choice_edit(c_index, index - 1);
				}
				system("pause");
				system("cls");
			}
			break;

			case (unsigned int)(ChoiceType::SearchNotes) :
			{
				system("cls");
				std::cout << "Enter the index of note: ";
				unsigned int index;
				std::cin >> index;
				std::cout << std::endl;
				std::cout << "Choose a search by: 1.Name 2.Surname 3.Patronymic 4.E-mail 5. Phonenumber\n\n";
				int search;
				std::cout << "Select a search: ";
				std::cin >> search;
				std::string search_fields;
				std::cout << "Written the word for search: ";
				std::cin >> search_fields;
				student_obj.search_field(index, search, search_fields);
				system("pause");
				system("cls");
			}
			break;

			case (unsigned int)(ChoiceType::SortNote) :
			{
				student_obj.notes_sort();
			}

			case (unsigned int)(ChoiceType::PrintAllNotes) :
			{
				student_obj.print_all_notes();
			}
			break;

			case (unsigned int)(ChoiceType::RemoveNote) :
			{
				system("cls");
				unsigned int index;
				std::cout << "Enter the index of note: ";
				std::cin >> index;
				std::cout << std::endl;
				student_obj.delete_note(index);
				system("pause");
				system("cls");
			}
			break;

			case (unsigned int)(ChoiceType::Exit) :
			{
				return 0;
			}
			break;
		}
	}
	student_info.close();
	return 0;

}