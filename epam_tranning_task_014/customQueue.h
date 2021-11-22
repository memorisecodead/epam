#pragma once
#include <iostream>
#include "ErrorHeader.h"
#include "Users.h"
#include <fstream>

template <typename T>
class customQueue
{
public:
	customQueue();
	void pushValue(T & index);
	void popValue();
	void printQueue();
	unsigned int frontValue();
	unsigned int backValue();

	bool isEmpty();
	unsigned int sizeOfQueue();
	unsigned int ReferenceSize(unsigned int & size);
	~customQueue();

private:
	T * q_arr;
	unsigned int q_fbeg;
	unsigned int q_rend;
	unsigned int q_size = 10;
}; 


template <typename T>
customQueue<T>::customQueue()
{
	q_arr = new T[q_size];
	q_fbeg = q_rend = 0;
}

template <typename T>
void customQueue<T>::pushValue(T & index)
{
	if (q_rend + 1 == q_fbeg || (q_rend + 1 == q_size && !q_fbeg))
	{
		std::cout << "Queue is full!" << std::endl;
	}

	++q_rend;

	if (q_rend == q_size)
	{
		q_rend = 0;
	}
	else
	{
		q_arr[q_rend] = index;
	}
}

template <typename T>
void customQueue<T>::popValue()
{
	T el_q = 0;
	el_q = q_arr[q_rend];

	if (q_rend >= q_fbeg)
	{
		q_fbeg = 0;
		q_rend = 0;
	}
	else
	{
		++q_rend;
	}

	std::cout << std::endl
		<< "Value is delete: " << el_q
		<< std::endl;

	try
	{
		if (q_rend >= q_size)
		{
			throw std::invalid_argument("bad area!");
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << " Going outside the area!" << std::endl;
		exit(EXIT_FAILURE);
	}

}

template <typename T>
void customQueue<T>::printQueue()
{
	for (int i = q_fbeg + 1; i < q_rend + 1; ++i)
	{
		std::cout << " " << q_arr[i];
	}
}

template <typename T>
unsigned int customQueue<T>::frontValue()
{
	return q_arr[q_fbeg + 1];
}

template <typename T>
unsigned int customQueue<T>::backValue()
{
	return q_arr[q_rend];
}

template <typename T>
bool customQueue<T>::isEmpty()
{
	if (q_rend == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
unsigned int customQueue<T>::sizeOfQueue()
{
	unsigned int temp_s = 0;
	for (int i = q_fbeg; i < q_rend; ++i)
	{
		++temp_s;
	}
	std::cout << "Size of queue: " << temp_s << std::endl;
	return temp_s;
}

template <typename T>
unsigned int customQueue<T>::ReferenceSize(unsigned int& size)
{
	try
	{
		if (size >= q_size)
		{
			throw std::invalid_argument("bad area!");
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << " Going outside the area!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Size of queue: " << q_size << std::endl << std::endl;
	return q_size;
}

template <typename T>
customQueue<T>::~customQueue()
{
	q_arr = nullptr;
	q_fbeg = 0;
	q_rend = 0;
	q_size = 0;
}
