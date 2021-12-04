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
		Student* st = new Student[10];

		st = st->dataPush(st);

		//std::vector<Student*> students_vc{ &st[0],&st[1] };

		//for (auto i = students_vc.begin(); i != students_vc.end(); ++i)
		//{
		//	std::cout << (*i)->getAge();
		//}

		//std::sort(students_vc.begin(), students_vc.end(), compareAge);

		/*std::vector<Student*> vsST{ &st[0],&st[1],&st[2],&st[3],&st[4]
			,&st[5],&st[6],&st[7],&st[8],&st[9]};*/

		myVector<Student*> vSt;

		vSt.push_back(&st[0]);
		vSt.push_back(&st[1]);
		vSt.push_back(&st[2]);

		std::sort(vSt.begin(), vSt.end(), compareAge);

		for (auto i = vSt.begin(); i != vSt.end(); ++i)
		{
			std::cout << (*i)->getAge() << std::endl;
		}
	
		vSt.clear();
		delete[] st;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
