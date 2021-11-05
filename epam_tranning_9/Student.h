#pragma once
#include "Note.h"

enum  ChooseEdit
{
	Name = 1,
	Surname,
	Patrynomic,
	E_mails,
	Numbers
};

class Student
{
public:

	Student();
	void add_note(Note note);
	void edit_note(const unsigned int& index);
	void print_note(const unsigned int& index);
	void print_inf(const unsigned int& index);
	void print_result(const unsigned int& index);
	void choice_edit(const unsigned int& c_index, const unsigned int& index);
	void delete_note(const unsigned int& index);
	void search_field(const unsigned int& index, const unsigned int& search, std::string& search_fields);
	void notes_sort();
	void print_all_notes();
	Note* get_notes();
	const unsigned int& get_size();

private:
	Note* notes;
	unsigned int size;
};
