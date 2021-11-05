#include <iostream>
#include <fstream>
#include "functionlayer.h"

int main()
{
	std::ofstream fout;
	fout.open("test.txt");
	open(fout);

	Employee* emp = nullptr;
	unsigned int index = 0;
	
	while (unsigned int select = userMenuEmpl())
	{
		switch (select)
		{
		case (unsigned int)(1):
		{
			startOfFoo(index);
			emp = setInfo(emp, index);
		}
		break;

		case (unsigned int)(2):
		{
			sortInfo(emp, index);
		}
		break;
		case (unsigned int)(3):
		{
			sortInfo(emp, index);
		}
		break;
		case (unsigned int)(4):
		{
			monthOfBirthday(emp, index);
		}
		break;
		case (unsigned int)(5):
		{
			OlderPerson(emp, index);
		}
		break;
		case (unsigned int)(6):
		{
			search_field(emp, index);
		}
		break;
		case (unsigned int)(7):
		{
			 showInfo(emp, index);
		}
		break;
		case (unsigned int)(8):
		{
			writeNote(fout, emp, index);
			fout.close();
			delete[] emp;
			exit(0);
		}
		break;
		}
	}	

	
	return 0;
}
