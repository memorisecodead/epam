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

const unsigned int& Student::getAge()
{
	return static_cast<const Student*>(this)->getAge();
}

const unsigned int & Student::getAge() const
{
	return m_age;
}

void Student::setName(std::string name)
{
	this->m_name = name;
}

const std::string& Student::getName()
{
	return static_cast<const Student*>(this)->getName();
}

const std::string& Student::getName() const
{
	return m_name;
}

void Student::setSurname(std::string surname)
{
	this->m_surname = surname;
}

const std::string& Student::getSurname()
{
	return static_cast<const Student*>(this)->getSurname();
}

const std::string& Student::getSurname() const
{
	return m_surname;
}

void Student::setGroup(std::string group)
{
	this->m_group = group;
}

const std::string& Student::getGroup()
{
	return static_cast<const Student*>(this)->getGroup();
}

const std::string& Student::getGroup() const
{
	return m_group;
}

void Student::setFaculty(std::string faculty)
{
	this->m_faculty = faculty;
}

const std::string& Student::getFaculty()
{
	return static_cast<const Student*>(this)->getFaculty();
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

	st[1].setName("Sasha");
	st[1].setSurname("Apollo");
	st[1].setAge(19);
	st[1].setFaculty("Computer physics");
	st[1].setGroup("CP_41");

	st[2].setName("Daniel");
	st[2].setSurname("Pollo");
	st[2].setAge(17);
	st[2].setFaculty("Computer physics");
	st[2].setGroup("CP_11");

	st[3].setName("Sasha");
	st[3].setSurname("Drain");
	st[3].setAge(21);
	st[3].setFaculty("Computer physics");
	st[3].setGroup("CP_71");

	st[4].setName("Sasha");
	st[4].setSurname("Apollo");
	st[4].setAge(20);
	st[4].setFaculty("Computer physics");
	st[4].setGroup("CP_51");

	st[5].setName("Kristen");
	st[5].setSurname("Bird");
	st[5].setAge(20);
	st[5].setFaculty("Computer physics");
	st[5].setGroup("CP_51");

	st[6].setName("Akamir");
	st[6].setSurname("Bagrov");
	st[6].setAge(18);
	st[6].setFaculty("Computer physics");
	st[6].setGroup("CP_41");

	st[7].setName("Arina");
	st[7].setSurname("Paraskevich");
	st[7].setAge(19);
	st[7].setFaculty("Computer physics");
	st[7].setGroup("CP_41");

	st[8].setName("Sergey");
	st[8].setSurname("Mlager");
	st[8].setAge(26);
	st[8].setFaculty("Computer physics");
	st[8].setGroup("CP_101");

	st[9].setName("Sasha");
	st[9].setSurname("Apollo");
	st[9].setAge(28);
	st[9].setFaculty("Computer physics");
	st[9].setGroup("CP_121");
}

void outputLog(Student & st,const char * mess)
{
	std::cout << "[" << &st << "] "
		<< mess << "\n";
}


