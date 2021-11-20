#pragma once
#include <iostream>
#include "Note.h"
#include "customQueue.h"

class Users
{
public:
	Users();
	void addNote(Note note);
	void deleteNote(const unsigned int & index);
	void frequentBuyers(Note * note);
	void infrequentBuyers(Note * note);

	std::string getName();
	std::string getSurname();
	std::string getPatronymic();
	std::string getEmail();
	unsigned int countOfPurch();
	unsigned int summOfPurch();

	~Users();

private:
	Note * u_notes;
	unsigned int u_size = 0;
};