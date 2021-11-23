#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "myVector.h"

class myString
{
public:
	myString();
	explicit myString(const char * const s_string);
	myString(const myString& other);
	myString(myString && other) noexcept;
	~myString() noexcept;

	myString& operator=(const myString& v);
	friend std::ostream& operator<<
		(std::ostream& out, const myString& ms);

private:
	char * s_string;
	size_t s_size;
};
