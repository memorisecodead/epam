#pragma once
#include <iostream>
#include "myVector.h"
#include "Note.h"

enum ChooseEdit
{
	Name = 1,
	Surname,
	MarkOfCar,
	TaxiNums
};

class TaxiCustom
{
public:
	TaxiCustom();
	void addNote(Note note);
	void editNote(const unsigned int & index);
	void printNoteOfTaxi(const unsigned int & index);
	void printInf(const unsigned int & index);
	void printResult(const unsigned int & index);
	void choiceEdit(const unsigned int & ch_index, const unsigned int & index);
	bool localeOfTaxi(unsigned int & index);
	bool freeTaxi(unsigned int & index);
	void deleteNote(const unsigned int & index);
	void printAllTaxis();
	Note * getNotes();
	const unsigned int & getSizeOfNote();

private:
	Note * notes;
	bool tripOfTaxi;
	unsigned int m_countOfDriver;
};