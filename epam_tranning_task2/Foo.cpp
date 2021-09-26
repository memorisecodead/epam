#include "Foo.h"

MyString::MyString()
{
	str = 0;
	count = 0;
}

MyString::~MyString()
{
	count = 0;
	delete [] str;
	str = nullptr;
}

MyString::MyString(const char* ptr)
	:count(strlen(ptr)),str(new char [count + 1])
{
	strcpy(str, ptr);
}

const char * MyString::getStr() const
{
	return str;
}

int MyString::getLength() const
{
	return count;
}

void MyString::swapOfString(std::string& s, unsigned int& count)
{
	char c{};
	std::cout << "Enter a word:" << std::endl;
	std::getline(std::cin, s);
	std::cout << "Enter a count of symbol(*):" << std::endl;
	std::cin >> count;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if (s.length() % 2)
	{
		for (int i = 0; i < s.length() / 2; i++)
		{
		std::swap(s[i], s[i + s.length() / 2]);
		}
	}
	else
	{
		s.insert(s.length() / 2, count, '*');
	}

	std::cout << "Your string:" << std::setw(4) << s << std::endl;
}

std::ostream & MyString::showStr(std::ostream& os) const
{
	return os << str;
}
