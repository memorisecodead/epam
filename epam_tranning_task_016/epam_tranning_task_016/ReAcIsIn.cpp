#include "ReAcIsIn.h"

file::file(const char * filename)
:m_file_hadder{ std::fopen(filename, "w+") }
{
	if (!m_file_hadder)
	{
		throw std::runtime_error("file open failure");
	}
}

file::~file()
{
	if (std::fclose(m_file_hadder) != 0)
	{

	}
}

void file::print(const char* ch)
{
	if (std::fputs(ch, m_file_hadder) == EOF)
	{
		throw std::runtime_error("file open failure");
	}

	system("pause");
	system("cls");
	std::cout << "done."
		<< std::endl;
}
