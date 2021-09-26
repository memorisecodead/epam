#pragma once
#include <iostream>
#include <string>
#include <iomanip>

void swapOfString(std::string& s, unsigned int& count)
{
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