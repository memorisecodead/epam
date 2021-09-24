#pragma once
#include <iostream>
#include <string>
#include <cassert> 
#include <iomanip>

enum ChooseEdit
{
	RemainingZero = 0,
	RemainingOne, 
	RemainingTwo,
	RemainingThree
};

struct Student
{
	std::string name;
	std::string surname;
	float score[3];
};

	Student* setStudentData(Student * student_obj, unsigned int & count)
	{
		std::cout << "How many students do you want to add?\n";
		std::cin >> count;

		if (count >= 5 && count < 60)
		{
			std::cout << "Continue..";
			system("cls");
		}
		else
		{
			assert(count < 0 && "You couldn't add less 0");
		}

		student_obj = new Student[count];

		for (int i = 0; i < count; ++i)
		{
			std::cout << "Student# " << i + 1 << std::endl;

			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Name: " << std::setw(3) << std::endl;
			std::getline(std::cin,student_obj[i].name);
			std::cout << "Surname: " << std::setw(3) << std::endl;
			std::getline(std::cin,student_obj[i].surname);
			std::cout << "Score: "<< std::setw(3) << std::endl;
			for (int j = 0; j < 3; ++j)
			{
				std::cin >> student_obj[i].score[j];
			}
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "\n\n";
		}
		return student_obj;
	}
	
	void showData(Student * student_obj, unsigned int & count)
	{
		system("cls");
		std::cout << "---List of Student's---\n\n";
		for (int i = 0; i < count; ++i)
		{
			std::cout << "Student# " << i + 1 << std::endl;

			std::cout << "Name: " << std::setw(3) << student_obj[i].name << std::endl;
			std::cout << "Surname: " << std::setw(3) << student_obj[i].surname << std::endl;
			for (int j = 0; j < 3; ++j)
			{
				std::cout << "Score: " << std::setw(3) << student_obj[i].score[j] << std::endl;
			}
			std::cout << "\n\n";
		}
	}

	void countOfLenght(Student * student_obj, unsigned int & count)
	{
		system("cls");
		float summ = 0;
		float average[10]{};
		int countOfSurname = 0;
		for (int i = 0; i < count; ++i)
		{
			int countOfSurname = student_obj[i].surname.length() % 4;
			
			switch (countOfSurname)
			{
				case (unsigned int)(ChooseEdit::RemainingZero) :
				{
					for (int j = 0; j < 3; ++j)
					{
						summ += student_obj[i].score[j];
					}
					average[i] = summ / 3;
					std::cout <<"Average score " << std::setw(2) << i + 1 << "#: " << average[i] << std::endl;
				}
				break;
				case (unsigned int)(ChooseEdit::RemainingOne) :
				{
					float max = student_obj[i].score[0];
					for (int j = 0; j < 3; ++j)
					{
						if (student_obj[i].score[j] > max)
						{
							max = student_obj[i].score[j];
						}
					}
					std::cout <<"Maximal score " <<std::setw(2) << i + 1 <<"#: " << max << std::endl;
				}
				break;
				case (unsigned int)(ChooseEdit::RemainingTwo) :
				{
					float min = student_obj[i].score[0];
					for (int j = 0; j < 3; ++j)
					{
						if (student_obj[i].score[j] < min)
						{
							min = student_obj[i].score[j];
						}
					}
					std::cout <<"Minimal score " << std::setw(2) << i + 1 << "#: " << min << std::endl;
				}
				break;
				case (unsigned int)(ChooseEdit::RemainingThree) :
				{
					for (int j = 0; j < 3; ++j)
					{
						summ += student_obj[i].score[j];
					}
					average[i] = summ;
					std::cout <<"Sum of scores " << std::setw(2) << i + 1 << "#: " << summ << std::endl;
				}
				break;
			}
			}
		system("pause");
	}