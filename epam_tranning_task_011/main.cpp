#include <iostream>
#include "TaxiCustom.h"

enum class ChoiceType
{
	AddNote = 1,
	EditNote,
	RemoveNote,
	DepartureTaxi,
	ReleaseOfTaxi,
	PrintAllTaxiNotes,
	Exit
};

int main()
{
	unsigned int choose = 0;
	unsigned int index = 3;

	TaxiCustom taxi_obj;

	myVector<Note> vnt(static_cast<unsigned int&&>(index));

	Note note0("Stas", "Apollo", "BMW", 6666);
	Note note1("Sasha", "Unnior", "BMW", 9999);
	Note note2("Alexa", "Paragraph", "Audi", 6969);

	while (true) //;;
	{
		std::cout <<
			"Taxi:\n"
			"-------------\n"
			"1. Add note.\n"
			"2. Edit note.\n"
			"3. Remove note.\n"
			"4. Departure taxi.\n"
			"5. Realease of taxi.\n"
			"6. Print all taxi notes.\n"
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
			/*	unsigned int humans_count;*/
				//std::cout << "Enter amount of persons: ";
				//std::cin >> humans_count;
				//std::cout << std::endl;
				//
				//for (auto i = 0; i < humans_count; ++i)
				//{
				//	/*std::cout << "Name:\t";
				//	std::cin >> note.m_name;
				//	std::cout << "Surname:\t";x
				//	std::cin >> note.m_surname;
				//	std::cout << "Mark of car:\t";
				//	std::cin >> note.m_mark_of_car;
				//	std::cout << "Taxi nums:\t";
				//	std::cin >> note.m_taxi_num;*/
				//	
				//	
				//}
				taxi_obj.addNote(note0);
				taxi_obj.addNote(note1);
				taxi_obj.addNote(note2);

				vnt.push_back(note0);
				vnt.push_back(note1);
				vnt.insert(0, note2);

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
				std::cout << "Editing by: 1.Name 2.Surname 3.Mark of car 4.Taxi number \n\nSelect:\t";
				std::cin >> c_index;
				std::cout << std::endl;

				if (index > taxi_obj.getSizeOfNote() || index < taxi_obj.getSizeOfNote())
				{
					std::cout << "out of notes range.\n";
					break;
				}
				else
				{
					taxi_obj.choiceEdit(c_index, index - 1);
				}
				system("pause");
				system("cls");
			}
			break;

			case(unsigned int)(ChoiceType::RemoveNote) :
			{
				system("cls");
				unsigned int index;
				std::cout << "Enter the index of note: ";
				std::cin >> index;
				std::cout << std::endl;
				taxi_obj.deleteNote(index);
				vnt.pop_back(index);
				
				system("pause");
				system("cls");
			}
			break;

			case(unsigned int)(ChoiceType::DepartureTaxi) :
			{
				system("cls");
				
				unsigned int count = 0;
				std::cout << "Enter a index of driver:" 
					<< std::endl;
				std::cin >> count;

				taxi_obj.localeOfTaxi(count);
				system("pause");
				system("cls");
			}
			break;

			case (unsigned int)(ChoiceType::ReleaseOfTaxi) :
			{
				system("cls");

				unsigned int count = 0;
				std::cout << "Enter a index of driver:"
					<< std::endl;
				std::cin >> count;

				taxi_obj.freeTaxi(count);
				system("pause");
				system("cls");
			}
			break;

			case(unsigned int)(ChoiceType::PrintAllTaxiNotes) :
			{
				system("cls");
				taxi_obj.printAllTaxis();
				system("pause");
				system("cls");
			}
			break;

			case(unsigned int)(ChoiceType::Exit) :
			{
				return 0;
			}
			break;
		}
	}
}