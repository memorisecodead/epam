#include "StudentLib.h"

Student::Student()
	:m_name{ "noname" }, m_surname{ "nosurname" },
	m_age{0},m_group{"unknown"},m_faculty{"unknown"}
{
	outputLog(*this,"Default Constructor");
}

Student::Student(std::string name, std::string surname, unsigned int age,
	std::string faculty, std::string group)
	: m_name(name),m_surname(surname),m_age(age),m_faculty(faculty),m_group(group)
{
	outputLog(*this,"Constructor with parametrs");
}

Student::Student(const Student & st)
{
	outputLog(*this, "Student(const Student & st)");

	m_name = st.m_name;
	m_surname = st.m_surname;
	m_age = st.m_age;
	m_faculty = st.m_faculty;
	m_group = st.m_group;
}

Student::~Student()
{
	outputLog(*this, "Destructor");

	this->m_name = " ";
	this->m_surname = " ";
	this->m_age = 0;
	this->m_group = " ";
	this->m_faculty = " ";
}

Student& Student::operator=(const Student& st)
{
	outputLog(*this, "Operator of copy");

	if (this == &st)
	{
		return *this;
	}

	m_name = st.m_name;
	m_surname = st.m_surname;
	m_age = st.m_age;
	m_faculty = st.m_faculty;
	m_group = st.m_group;

	return *this;
}

void Student::setAge(unsigned int age)
{
	this->m_age = age;
}

unsigned int& Student::getAge()
{
	return this->getAge();
}

const unsigned int & Student::getAge() const
{
	return m_age;
}

void Student::setName(std::string name)
{
	this->m_name = name;
}

std::string& Student::getName()
{
	return this->getName();
}

const std::string& Student::getName() const
{
	return m_name;
}

void Student::setSurname(std::string surname)
{
	this->m_surname = surname;
}

std::string& Student::getSurname()
{
	return this->getSurname();
}

const std::string& Student::getSurname() const
{
	return m_surname;
}

void Student::setGroup(std::string group)
{
	this->m_group = group;
}

std::string& Student::getGroup()
{
	return this->getGroup();
}

const std::string& Student::getGroup() const
{
	return m_group;
}

void Student::setFaculty(std::string faculty)
{
	this->m_faculty = faculty;
}

std::string& Student::getFaculty()
{
	return this->getFaculty();
}

const std::string& Student::getFaculty() const
{
	return m_faculty;
}

std::ostream& operator<<(std::ostream& out, const Student& st)
{
	out << st.m_name << " | " << st.m_surname << " | " << st.m_age
		<< " | " << st.m_faculty << " | " << st.m_group << "\n";

	return out;
}

bool compareAge (Student * rhs, Student * lhs)
{
	/*outputLog("Functor for comapare of student's ages");*/
	return (*rhs).getAge() >  (*lhs).getAge();
}

void dataPush(Student* st)
{
	system("pause");
	system("cls");

	st[0].setName("Stas");
	st[0].setSurname("Apollo");
	st[0].setAge(18);
	st[0].setFaculty("Computer physics");
	st[0].setGroup("CP_21");


	//st[1].m_name = "Sasha";
	//st[1].m_surname = "Apollo";
	//st[1].m_age = 19;
	//st[1].m_faculty = "Computer physics";
	//st[1].m_group = "CP_41";

	//st[2].m_name = "Daniel";
	//st[2].m_surname = "Pollo";
	//st[2].m_age = 17;
	//st[2].m_faculty = "Computer physics";
	//st[2].m_group = "CP_11";

	//st[3].m_name = "Sasha";
	//st[3].m_surname = "Drain";
	//st[3].m_age = 21;
	//st[3].m_faculty = "Computer physics";
	//st[3].m_group = "CP_71";

	//st[4].m_name = "Sasha";
	//st[4].m_surname = "Apollo";
	//st[4].m_age = 20;
	//st[4].m_faculty = "Computer physics";
	//st[4].m_group = "CP_51";

	//st[5].m_name = "Kristen";
	//st[5].m_surname = "Bird";
	//st[5].m_age = 20;
	//st[5].m_faculty = "Computer physics";
	//st[5].m_group = "CP_51";

	//st[6].m_name = "Akamir";
	//st[6].m_surname = "Bagrov";
	//st[6].m_age = 18;
	//st[6].m_faculty = "Computer physics";
	//st[6].m_group = "CP_41";

	//st[7].m_name = "Arina";
	//st[7].m_surname = "Paraskevich";
	//st[7].m_age = 19;
	//st[7].m_faculty = "Computer physics";
	//st[7].m_group = "CP_41";

	//st[8].m_name = "Sergey";
	//st[8].m_surname = "Mlager";
	//st[8].m_age = 26;
	//st[8].m_faculty = "Computer physics";
	//st[8].m_group = "CP_101";

	//st[9].m_name = "Sasha";
	//st[9].m_surname = "Apollo";
	//st[9].m_age = 28;
	//st[9].m_faculty = "Computer physics";
	//st[9].m_group = "CP_121";
}

void outputLog(Student & st,const char * mess)
{
	std::cout << "[" << &st << "] "
		<< mess << "\n";
}


