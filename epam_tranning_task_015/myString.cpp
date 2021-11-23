#include "myString.h"

myString::myString()
	:s_string(nullptr),s_size(0)
{
}

myString::myString(const char* const s_string)
{
	std::cout << "String(const char *const c_string)\n";
	s_size = strlen(s_string) + 1;
	this->s_string = new char[s_size];
	strcpy(this->s_string, s_string);
}

myString::myString(const myString& other)
{
	std::cout << "String(const String& other)\n";
	s_string = new char[other.s_size];
	strcpy(s_string, other.s_string);
	s_size = other.s_size;
}

myString::~myString() noexcept
{
	std::cout << "~String()\n";
	delete[] s_string;
}

myString & myString::operator=(const myString& v)
{
	if (this == & v)
	{
		return *this;
	}

	s_string = v.s_string;
	return *this;
}

myString::myString(myString&& other) noexcept
{
	std::cout << "String(String&& other)\n";
	s_string = other.s_string;
	s_size = other.s_size;
	other.s_string = nullptr;
	other.s_size = 0;
}

std::ostream& operator<<(std::ostream& out, const myString& ms)
{
	out << "String: " << ms.s_string 
		<< std::endl;

	return out;
}
