#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "myVector.h"

class myString
{
public:
	myString();

	explicit myString(const char * const s_string);
	myString(const myString & other);
	myString(myString && other) noexcept;
	~myString() noexcept;

	myString& operator=(const myString& v);
	friend std::ostream & operator<<
		(std::ostream & out, const myString & ms);

	const char * data() const noexcept;
	char * data() noexcept;

	unsigned int const & size() const;

private:
	char * s_string;
	unsigned int s_size;
	void outputLog(const char * mess);
};
