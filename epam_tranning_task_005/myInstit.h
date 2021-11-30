#pragma once
#include <iostream>

class EducInstit
{
public:
	EducInstit();
	~EducInstit();
	unsigned int& getPeople();
	void setPeople(unsigned int people);
	double& getScore();
	void setScore(unsigned int score);

	virtual double averageScore();
	virtual unsigned int generalCountOfPeople();
private:
	unsigned int m_count_of_people;
	double m_score;
};
