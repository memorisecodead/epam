#include <iostream>
#include <algorithm>
#include <vector>
#include "StudentLib.h"
#include "myVector.h"

int main()
{
	try
	{
		Student st[10];
		dataPush(st);

		DataStructure::MyVector<Student*> students_vc;

		for (size_t i = 0; i < 10; ++i)
		{
			students_vc.push_back(&st[i]);
		}
		
		for (auto i = students_vc.begin(); i != students_vc.end(); ++i)
		{
			std::cout <<  (*i)->getAge() << std::endl;
		}

		std::sort(students_vc.begin(), students_vc.end(), compareAge);

		for (auto i : students_vc)
		{
			std::cout << (i)->getAge() << std::endl;
		}

		students_vc.clear();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
