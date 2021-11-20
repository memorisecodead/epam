#include <iostream>
#include "Note.h"
#include "customQueue.h"
#include "Users.h"

enum class Choose
{
	AddNote = 1,
	frequentBuyers,
	infrequentBuyers,
	Exit
};

int main()
{
	Users user_obj;
	Note note0("Stas", "Mazur", "Sergeevich", "e33gmail.com", 66, 1000);
	Note note1("Sasha", "Apollo", "Sergeevich", "g6gmail.com", 9, 100);
	Note note2("Alina", "Devilish", "Olegovich", "h44gmail.com", 19, 9);
	Note note3("Dasha", "Katusha", "Sergeevich", "d77gmail.com", 15, 8);
	customQueue<Users> tqq;
	customQueue<Users> bqq;

	while (true)
	{
		std::cout << "User of shop:\n"
			"--------------\n"
			"1. Add note\n"
			"2. frequent buyers of shop\n"
			"3. infrequent buyers of shop\n"
			"4. Exit\n"
			"--------------\n"
			"Choose: ";

		unsigned int choose = 0;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> choose;

		switch (choose)
		{
			case(unsigned int)(Choose::AddNote) :
			{
				/*unsigned int countOfUser = 2;*/
				/*std::cout << "Enter a count of user:\n";
				std::cin >> countOfUser;*/
				system("cls");
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());

				user_obj.addNote(note0);
				user_obj.addNote(note1);
				user_obj.addNote(note2);
				user_obj.addNote(note3);

				system("pause");
				system("cls");
			}
			break;
			case (unsigned int)(Choose::frequentBuyers) :
			{
				system("cls");
				user_obj.frequentBuyers(&note0);
				user_obj.frequentBuyers(&note1);
				user_obj.frequentBuyers(&note2);
				user_obj.frequentBuyers(&note3);

				for (int i = 0; i <= 4; ++i)
				{
					tqq.pushValue(user_obj);
				}
				/*cqq.printQueue();*/

				system("pause");
				system("cls");
			}
			break;

			case(unsigned int)(Choose::infrequentBuyers) :
			{
				system("cls");
				user_obj.infrequentBuyers(&note0);
				user_obj.infrequentBuyers(&note1);
				user_obj.infrequentBuyers(&note2);
				user_obj.infrequentBuyers(&note3);

				for (int i = 0; i <= 4; ++i)
				{
					bqq.pushValue(user_obj);
				}
				system("pause");
				system("cls");
			}
			break;

			case(unsigned int)(Choose::Exit) :
			{
				return 0;
			}
			break;
		}
	}

	return 0;
}
