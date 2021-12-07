#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include "StudentLib.h"
#include "myVector.h"

int main()
{
	try
	{
		/*Student* st = new Student[10];
		dataPush(st);*/
		Student st1;
		Student st2;

		dataPush(&st1);
		dataPush(&st2);

		DataStructure::MyVector<Student*> students_vc;
		students_vc.push_back(&st1);
		students_vc.push_back(&st2);
		
		for (auto i = students_vc.begin(); i != students_vc.end(); ++i)
		{
			std::cout <<  (*i)->getAge() << std::endl;
		}

		std::sort(students_vc.begin(), students_vc.end(), compareAge);

		students_vc.clear();
		/*delete[] st;*/
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
