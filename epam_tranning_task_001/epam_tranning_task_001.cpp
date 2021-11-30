#include <iostream>
#include "Student.h"

int main()
{
	unsigned int countSt = 0;

	Student* st = nullptr;

	st = setStudentData(st, countSt);
	showData(st, countSt);
	countOfLenght(st, countSt);
	showData(st, countSt);

	delete [] st;
	
	return 0;
}