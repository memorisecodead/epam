#include "Introdusted.h"

MyClass::MyClass()
	: m_arr(), m_size(10)
{

}

bool MyClass::evenValues(int i)
{
	return ((i % 2) == 0);
}

//int& MyClass::operator[](const int index)
//{
//	return m_arr[index];
//}

void translateToFarengeit(double inputValue)
{
	std::cout << ((inputValue - 32) / 1.8) << " | ";
}

bool evenValues(int i)
{
	return ((i % 2) == 0);;
}

bool MyClass::operator[](const int index)
{
	return ((index % 2) == 0);
}
