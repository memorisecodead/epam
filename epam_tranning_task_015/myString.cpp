#include "myString.h"

myString::myString()
	:s_string(nullptr),s_size(0)
{
	outputLog("Default constructor");
}

myString::myString(const char* const s_string)
{
	outputLog("String(const char * const c_string)");
	s_size = strlen(s_string) + 1;
	this->s_string = new char[s_size];
	strcpy(this->s_string, s_string);
}

myString::myString(const myString & other)
{
	outputLog("String(const String & other)");
	s_string = new char[other.s_size];
	strcpy(s_string, other.s_string);
	s_size = other.s_size;
}

myString::~myString() noexcept
{
	outputLog("~String()");

	delete s_string;
	s_size = 0;
}

myString & myString::operator=(const myString & v)
{
	if (this == & v)
	{
		return *this;
	}

	s_string = v.s_string;
	return *this;
}

const char * myString::data() const noexcept
{
	return this->s_string;
}

char * myString::data() noexcept
{
	return this->s_string;
}

unsigned int const & myString::size() const
{
	return this->s_size;
}

void myString::outputLog(const char * mess)
{
	std::cout << "[" << this << "] "
		<< mess << "\n";
}

myString::myString(myString && other) noexcept
{
	outputLog("String(String && other)");
	s_string = std::move(other.s_string);
	s_size = other.s_size;
}

std::ostream& operator<<(std::ostream & out,
	const myString & ms)
{
	out << "String: " << ms.s_string 
		<< std::endl;

	return out;
}
