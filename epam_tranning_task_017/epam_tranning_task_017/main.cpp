#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <iostream>
#include <algorithm>
#include "StudentLib.h"
#include "myVector.h"
#include <vector>

int main()
{
	Student * st = new Student[10];

	st = st->dataPush(st);
	/*std::vector<Student*> vsST{ &st[0],&st[1],&st[2],&st[3],&st[4]
		,&st[5],&st[6],&st[7],&st[8],&st[9]};*/
	myVector<Student> vSt(st);
	
	std::sort(vSt.begin(),vSt.end(), compareAge);

	for (auto i = vSt.begin(); i != vSt.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	/*bool(*fpointer)(Student * rhs, Student * lhs)  = compareAge;*/

	vSt.clear();
	delete[] st;
	return 0;
}
