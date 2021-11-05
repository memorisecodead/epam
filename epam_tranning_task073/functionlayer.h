#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum Choose
{
	Name = 1,
	Surname,
	Year,
	Salary,
	Position,
	MonthOfBirthday,
	Day
};

struct Employee
{
	float s_salary;
	int s_year;
	int s_day;
	std::string s_month;
	std::string s_name;
	std::string s_surname;
	std::string s_position;
	std::string s_sex;
};

Employee * setInfo(Employee * empl_obj, unsigned int & index)
{
	empl_obj = new Employee [index];
	for (int i = 0; i < index; ++i)
	{
		std::cout << "Emplooyer #" << i + 1 << std::endl;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Name: " << std::endl;
		std::getline(std::cin ,empl_obj[i].s_name);
		std::cout << "Surname: " << std::endl;
		std::getline(std::cin, empl_obj[i].s_surname);
		std::cout << "Sex: " << std::endl;
		std::getline(std::cin, empl_obj[i].s_sex);
		std::cout << "Position: " << std::endl;
		std::getline(std::cin, empl_obj[i].s_position);
		std::cout << "Day: " << std::endl;
		std::cin >> empl_obj[i].s_day;
		std::cout << "Year: " << std::endl;
		std::cin >> empl_obj[i].s_year;
		std::cout << "Month of birthday: " << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, empl_obj[i].s_month);
		std::cout << "Salary: " << std::endl;
		std::cin >> empl_obj[i].s_salary;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "\n\n\n";
	}

	return empl_obj;
}

void showInfo(Employee * empl_obj, unsigned int & index)
{
	system("pause");
	system("cls");
	std::cout << "\n\n---List of Employeer's---\n\n";
	for (int i = 0; i < index; i++)
	{
		std::cout << "Employee #" << i + 1 << std::endl;
		std::cout << "Name: " << std::endl;
		std::cout << empl_obj[i].s_name << std::endl;
		std::cout << "Surname: " << std::endl;
		std::cout << empl_obj[i].s_surname << std::endl;
		std::cout << "Sex: " << std::endl;
		std::cout << empl_obj[i].s_sex << std::endl;
		std::cout << "Position: " << std::endl;
		std::cout << empl_obj[i].s_position << std::endl;
		std::cout << "Salary: " << std::endl;
		std::cout << empl_obj[i].s_salary << std::endl;
		std::cout << "Day: " << std::endl;
		std::cout << empl_obj[i].s_day << std::endl;
		std::cout << "Year: " << std::endl;
		std::cout << empl_obj[i].s_year << std::endl;
		std::cout << "Month of birthday: " << std::endl;
		std::cout << empl_obj[i].s_month << std::endl;
		std::cout << "\n";
	}
	std::cout << "\n";
}

void sortInfo(Employee* empl_obj, unsigned int & index)
{
	system("pause");
	system("cls");
	unsigned int choose = 0;
	std::cout << "Choose how do you can sort Emplooyer?" << std::endl
		<< "1. Name\n"
		"2. Surname\n"
		"3. Date of born\n"
		"4. Salary\n"
		"5. Position on work\n"
		"6. Month of birthday\n";
	std::cout << "Choose:";
	std::cin >> choose;
	std::cout << std::endl;

	switch (choose)
	{
		case (unsigned int) (Choose::Name):
		{
			Employee temp;
			for (int i = 0; i < index - 1; ++i)
			{
				for (int j = 0; j < index - i - 1; ++j)
				{
					if (empl_obj[j].s_name > empl_obj[j + 1].s_name)
					{
						temp = empl_obj[j];
						empl_obj[j] = empl_obj[j + 1];
						empl_obj[j + 1] = temp;
					}
				}
			}
			
		}
		break;

		case (unsigned int)(Choose::Surname) :
		{
			Employee temp;
			for (int i = 0; i < index - 1; ++i)
			{
				for (int j = 0; j < index - i - 1; ++j)
				{
					if (empl_obj[j].s_surname > empl_obj[j + 1].s_surname)
					{
						temp = empl_obj[j];
						empl_obj[j] = empl_obj[j + 1];
						empl_obj[j + 1] = temp;
					}
				}
			}
		}
		break;

		case (unsigned int)(Choose::Position) :
		{
			Employee temp;
			for (int i = 0; i < index - 1; ++i)
			{
				for (int j = 0; j < index - i - 1; ++j)
				{
					if (empl_obj[j].s_position > empl_obj[j + 1].s_position)
					{
						temp = empl_obj[j];
						empl_obj[j] = empl_obj[j + 1];
						empl_obj[j + 1] = temp;
					}
				}
			}
		}
		break;

		case (unsigned int)(Choose::Salary) :
		{
			Employee temp;
			for (int i = 0; i < index - 1; ++i)
			{
				for (int j = 0; j < index - i - 1; ++j)
				{
					if (empl_obj[j].s_salary > empl_obj[j + 1].s_salary)
					{
						temp = empl_obj[j];
						empl_obj[j] = empl_obj[j + 1];
						empl_obj[j + 1] = temp;
					}
				}
			}
		}
		break;

		case (unsigned int)(Choose::Year) :
		{
			Employee temp;
			for (int i = 0; i < index - 1; ++i)
			{
				for (int j = 0; j < index - i - 1; ++j)
				{
					if (empl_obj[j].s_year > empl_obj[j + 1].s_year)
					{
						temp = empl_obj[j];
						empl_obj[j] = empl_obj[j + 1];
						empl_obj[j + 1] = temp;
					}
				}
			}
		}
		break;

		case (unsigned int)(Choose::MonthOfBirthday) :
		{
			Employee temp;
			for (int i = 0; i < index - 1; ++i)
			{
				for (int j = 0; j < index - i - 1; ++j)
				{
					if (empl_obj[j].s_month > empl_obj[j + 1].s_month)
					{
						temp = empl_obj[j];
						empl_obj[j] = empl_obj[j + 1];
						empl_obj[j + 1] = temp;
					}
				}
			}

		}
		break;

		case (unsigned int)(Choose::Day) :
		{
			Employee temp;
			for (int i = 0; i < index - 1; ++i)
			{
				for (int j = 0; j < index - i - 1; ++j)
				{
					if (empl_obj[j].s_day > empl_obj[j + 1].s_day)
					{
						temp = empl_obj[j];
						empl_obj[j] = empl_obj[j + 1];
						empl_obj[j + 1] = temp;
					}
				}
			}

		}
		break;
	}
}

void monthOfBirthday(Employee * empl_obj, unsigned int & index)
{
	system("pause");
	std::string temp_strOfBirhday;

	std::cout << "Enter a month of birthday for found a worker:" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::getline(std::cin, temp_strOfBirhday);

	for (int i = 0; i < index; ++i)
	{
		if (empl_obj[i].s_month == temp_strOfBirhday)
		{
			std::cout <<"Employee: " << empl_obj[i].s_name << std::endl;
		}
		else
		{
			std::cout << " ";
		}
	}
	system("pause");
}

void OlderPerson(Employee * empl_obj, unsigned int & index)
{
	system("pause");
	system("cls");

	Employee temp;
	for (int i = 0; i < index - 1; ++i)
	{
		for (int j = 0; j < index - i - 1; ++j)
		{
			if (empl_obj[j].s_year > empl_obj[j + 1].s_year)
			{
				temp = empl_obj[j];
				empl_obj[j] = empl_obj[j + 1];
				empl_obj[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < index; ++i)
	{
		if (empl_obj[i].s_year < 2000 && empl_obj[i].s_year > 1950)
		{
			std::cout << empl_obj[i].s_surname << " | " << empl_obj[i].s_year << std::endl;
		}
		else
		{
			std::cout << " ";
		}
	}
	std::cout << "For my opinion, the elder worker from 1950 - 2000 in born" << std::endl;
}
		
void startOfFoo(unsigned int& index)
{
	std::string indexInput;
	std::cout << "Enter a count of workers: "
		<< std::endl;
	std::cin >> indexInput;
	try
	{
		index = std::stoi(indexInput);
	}
	catch (std::invalid_argument)
	{
		std::cout << "You can't do it!" << std::endl;
		exit(0);
	}
}

void printEmplo(Employee* empl_obj, const unsigned int& index)
{

		std::cout << "\nInfo about Employeer's # " << index << ":\n"
			<< empl_obj[index].s_name << ", "
			<< empl_obj[index].s_surname << ", "
			<< empl_obj[index].s_sex << ", "
			<< empl_obj[index].s_day << ", "
			<< empl_obj[index].s_year << ", "
			<< empl_obj[index].s_month << ", "
			<< empl_obj[index].s_position << ", "
			<< empl_obj[index].s_salary << ". " << std::endl;
	
}

void search_field(Employee * empl_obj, const unsigned int& index)
{
	system("pause");
	system("cls");
	std::string str{};
	unsigned int search = 0;
	std::cout << "Enter your found str: " << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::getline(std::cin, str);
	std::cout << "Enter a search point:" << std::endl;
	std::cout << "Enter a number from 1 to 6\n"
		<< "1. Name\n"
		"2. Surname\n"
		"3. Date of born\n"
		"4. Salary\n"
		"5. Position on work\n"
		"6. Month of birthday\n";
	std::cout << "Choose: ";
	std::cin >> search;
		
	while (search < 1 && search > 6)
	{
		std::cout << "Enter a number from 1 to 6\n";
	}

	switch(search)
	{
		case (unsigned int)(Choose::Name) :
		{
			for (int i = 0; i < index; ++i)
			{
				if (empl_obj[i].s_name == str)
				{
					printEmplo(empl_obj, index);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		break;

		case (unsigned int)(Choose::Surname) :
		{
			for (int i = 0; i < index; ++i)
			{
				if (empl_obj[i].s_surname == str)
				{
					printEmplo(empl_obj, index);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		break;

		case (unsigned int)(Choose::Year) :
		{
			int search_int = 0;
			std::cout << "Enter a year of birthday:" << std::endl;
			std::cin >> search_int;

			for (int i = 0; i < index; ++i)
			{
				if (empl_obj[i].s_year == search_int)
				{
					printEmplo(empl_obj, index);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		break;

		case (unsigned int)(Choose::Salary) :
		{
			int search_int = 0;
			std::cout << "Enter a salary of emlooyer:" << std::endl;
			std::cin >> search_int;

			for (int i = 0; i < index; ++i)
			{
				if (empl_obj[i].s_salary == search_int)
				{
					printEmplo(empl_obj, index);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		break;

		case (unsigned int)(Choose::Position) :
		{
			for (int i = 0; i < index; ++i)
			{
				if (empl_obj[i].s_position == str)
				{
					printEmplo(empl_obj, index);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		break;

		case (unsigned int)(Choose::MonthOfBirthday) :
		{
			for (int i = 0; i < index; ++i)
			{
				if (empl_obj[i].s_month == str)
				{
					printEmplo(empl_obj, index);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		break;
	}
}

unsigned int userMenuEmpl()
{
	std::cout << "Choose :\n"
		<< "1. Input data\n"
		<< "2. Sort by lastname\n"
		<< "3. Sort by age\n"
		<< "4. Print list of people born in a given month\n"
		<< "5. Print lastname of the oldest man\n"
		<< "6. Print all lastnames starting with a given letter\n"
		<< "7. Print database\n"
		<< "8. Exit\n"
		<< "\n"
		<< "Your choice:\n";

	int choice{ -1 };
	std::cin >> choice;
	std::cout << std::endl;
	return choice;

}

void open(std::ofstream & fout)
{
	if (fout.is_open())
	{
		std::cout << "File is open." << std::endl;
	}
	else
	{
		std::cout << "Check your file." << std::endl;
		exit(0);
	}
}

int writeNote(std::ofstream& fout, Employee * empl_obj,unsigned int & index)
{
	for (int i = 0; i < index; i++)
	{
			fout << "Employee #" << i + 1 << std::endl;
			fout << "Name: " << std::endl;
			fout << empl_obj[i].s_name << std::endl;
			fout << "Surname: " << std::endl;
			fout << empl_obj[i].s_surname << std::endl;
			fout << "Sex: " << std::endl;
			fout << empl_obj[i].s_sex << std::endl;
			fout << "Position: " << std::endl;
			fout << empl_obj[i].s_position << std::endl;
			fout << "Salary: " << std::endl;
			fout << empl_obj[i].s_salary << std::endl;
			fout << "Day: " << std::endl;
			fout << empl_obj[i].s_day << std::endl;
			fout << "Year: " << std::endl;
			fout << empl_obj[i].s_year << std::endl;
			fout << "Month of birthday: " << std::endl;
			fout << empl_obj[i].s_month << std::endl;
			fout << "\n";
	}
	return 1;
}