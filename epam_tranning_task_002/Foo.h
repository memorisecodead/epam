#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

class MyString
{
public:

	MyString();
	~MyString();
	MyString(const char * ptr);
	const char * getStr() const;
	int getLength() const;
	void swapOfString(std::string& s, unsigned int& count);
	std::ostream & showStr(std::ostream& os) const;

	friend std::ostream& operator << (std::ostream& os, const MyString& s)
	{
		return s.showStr(os);
	}

protected:
	char * str;
	int count;

};
