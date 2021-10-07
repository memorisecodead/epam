#include "myInstit.h"

EducInstit::EducInstit()
	:m_count_of_people(0),m_score (0.0)
{

}

EducInstit::~EducInstit()
{
	m_count_of_people = 0;
	m_score = 0.0;
}

unsigned int& EducInstit::getPeople()
{
	return m_count_of_people;
}

void EducInstit::setPeople(unsigned int people)
{
	m_count_of_people = people;
}

double& EducInstit::getScore()
{
	return m_score;
}

void EducInstit::setScore(unsigned int score)
{
	m_score = score;
}

double EducInstit::averageScore()
{
	system("pause");
	system("cls");
	double averageScore = 0;
	int countOfSubject = 0;
	std::cout << "Enter a count of subject:" << std::endl;
	std::cin >> countOfSubject;
	std::cout << "Average score of people:" << std::endl;
	averageScore = m_score / countOfSubject;
	std::cout << averageScore << " average score of people" << std::endl;
	return averageScore;
	system("pause");
}

unsigned int EducInstit::generalCountOfPeople()
{
	system("pause");
	system("cls");
	unsigned int generaPeople = 0;
	unsigned int peopleInClass = 0;
	std::cout << "Enter a count of people in class:" << std::endl;
	std::cin >> peopleInClass;
	std::cout << "General count of people:" << std::endl;
	generaPeople = m_count_of_people / peopleInClass;
	std::cout << generaPeople << " general count of people in class" << std::endl;
	return generaPeople;
	system("pause");
}
