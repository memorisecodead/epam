#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <functional>
#include <list>

class MyClass
{
public:
	MyClass();
	bool evenValues(int i);
	/*int& operator[] (const int index);*/
	bool operator[](const int index);
private:
	unsigned int m_size;
	int m_arr[];
};

