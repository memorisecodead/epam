#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

class file
{
public:
	file(const char * filename);
	file(const file &) = delete;
	file & operator=(const file &) = delete;

	~file();

	void print(const char * ch);

private:
	std::FILE * m_file_hadder;
};
