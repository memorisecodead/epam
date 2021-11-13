#pragma once
#include <iostream>
#include <string>


struct Student
{
	std::string m_name;
	std::string m_surname;
	std::string m_mail;
	std::string m_faculty;

	friend std::ostream& operator<<(std::ostream& fout, const Student& st);
};


struct StudentS
{
	std::string m_name;
	std::string m_surname;
	std::string m_faculty;
	std::string m_mail;

	friend std::ostream& operator<<(std::ostream& fout, const StudentS& st);
};

Student* setStudentData(Student* st_obj, unsigned int& count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << "Student #" << i + 1 << std::endl;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Name: " << std::endl;
		std::getline(std::cin, st_obj[i].m_name);
		std::cout << "Surname: " << std::endl;
		std::getline(std::cin, st_obj[i].m_surname);
		std::cout << "E-mail: " << std::endl;
		std::getline(std::cin, st_obj[i].m_mail);
		std::cout << "Faculty: " << std::endl;
		std::getline(std::cin, st_obj[i].m_faculty);
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "\n\n\n";
	}

	return st_obj;
}


StudentS* setStudentSData(StudentS* st_obj, unsigned int& count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << "StudentS #" << i + 1 << std::endl;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Name: " << std::endl;
		std::getline(std::cin, st_obj[i].m_name);
		std::cout << "Surname: " << std::endl;
		std::getline(std::cin, st_obj[i].m_surname);
		std::cout << "Faculty: " << std::endl;
		std::getline(std::cin, st_obj[i].m_faculty);
		std::cout << "E-mail: " << std::endl;
		std::getline(std::cin, st_obj[i].m_mail);
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "\n\n\n";
	}

	return st_obj;
}

std::ostream& operator<<(std::ostream& fout, const Student& st)
{
	fout << st.m_name << " | " << st.m_surname << " | " << st.m_faculty << " | " << st.m_mail << std::endl;

	return fout;
}

std::ostream& operator<<(std::ostream& fout, const StudentS& st)
{
	fout << st.m_name << " | " << st.m_surname << " | " << st.m_mail  << " | " << st.m_faculty << std::endl;

	return fout;
}

void Foo(Student& st, unsigned int& SIZE)
{
	Student* temp_st = new Student[SIZE];
	temp_st = setStudentData(temp_st, SIZE);

	StudentS* temp_stS = new StudentS[SIZE];
	temp_stS = setStudentSData(temp_stS, SIZE);

	system("cls");
	std::cout << std::endl;
	std::cout << "Access the first student from an array using pointer dereferencing" << std::endl;
	std::cout << *&temp_st[0] << std::endl;

	std::cout << std::endl;
	std::cout << "Calculate the size of memory occupied by an array of students" << std::endl;
	std::cout << "Student " << sizeof(Student) / sizeof(std::string) << " bytes" << std::endl;
	std::cout << "StudentS " << sizeof(StudentS) / sizeof(std::string) << " bytes" << std::endl;


	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "Student: " << temp_st[i] << " Adress: " << &temp_st[i] << " Count++: " << i
			<< std::endl;
	}

	std::cout << std::endl;
	std::cout << "Create a structure with the same set of fields, " <<
		"but a different sequence. Compare the sizes of structures." << std::endl
		<< "Print to the console the addresses of each field for both structures." << std::endl
		<< "Draw conclusions." << std::endl << std::endl;

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "Student: " << temp_st[i] << " Adress: " << &temp_st[i] << " ++Count: " << i
			<< std::endl;

		std::cout << "StudentS: " << temp_stS[i] << " Adress: " << &temp_stS[i] << " ++Count: " << i
			<< std::endl;
	}

	system("pause");
	delete[] temp_st;
	temp_st = nullptr;
	delete[] temp_stS;
	temp_stS = nullptr;
}