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
	char name[30];
	char surname[40];
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
			std::cout << "Name:\t" << std::endl;
			std::cin.getline(student_obj[i].name, '\n');
			std::cout << "Surname:\t" << std::endl;
			std::cin.getline(student_obj[i].surname, '\n');
			std::cout << "Score:\t" << std::endl;
			for (int j = 0; j < 3; ++j)
			{
				std::cin >> student_obj[i].score[j];
			}
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "\n\n\n";
		}
		return student_obj;
	}
	
	void showData(Student * student_obj, unsigned int & count)
	{
		system("cls");
		std::cout << "---List of Student's---\n";
		for (int i = 0; i < count; ++i)
		{
			std::cout << "Student# " << i + 1 << std::endl;

			std::cout << "Name:\t" << student_obj[i].name << std::endl;
			std::cout << "Surname:\t" << student_obj[i].surname << std::endl;
			for (int j = 0; j < 3; ++j)
			{
				std::cout << "Score:\t" << student_obj[i].score[j] << std::endl;
			}
		}
	}

	void countOfLenght(Student * student_obj, unsigned int & count)
	{
		float summ = 0;
		float average[3]{};
		int countOfSurname = 0;
		for (int i = 0; i < count; ++i)
		{
			int countOfSurname = strlen(student_obj[i].surname) % 4;
			
			switch (countOfSurname)
			{
				case (unsigned int)(ChooseEdit::RemainingZero) :
				{
					for (int j = 0; j < 3; ++j)
					{
						summ += student_obj[i].score[j];
					}
					average[i] = summ / 3;
					std::cout <<"Average score:\t" << i + 1 << ' ' << average[i] << std::endl;
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
					std::cout <<"Maximal score:\t" << i + 1 <<' ' << max << std::endl;
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
					std::cout <<"Minimal score:\t" << i + 1 <<' '<< min << std::endl;
				}
				break;
				case (unsigned int)(ChooseEdit::RemainingThree) :
				{
					for (int j = 0; j < 3; ++j)
					{
						summ += student_obj[i].score[j];
					}
					average[i] = summ;
					std::cout <<"Sum of scores:\t" << ' ' << average[i] << std::endl;
				}
				break;
			}
			}
	}