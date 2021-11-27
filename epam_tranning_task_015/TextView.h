#pragma once
#include "myVector.h"
#include "myString.h"

template <class T>
class TextView 
{
public:
	explicit TextView(myString * str);

	TextView(const TextView<T> & other);
	TextView(const TextView<T> && other) noexcept;

	TextView & operator=(const TextView<T> & other);
	TextView & operator=(TextView<T> && other);
	
	~TextView() noexcept;
private:
	myString * t_str;
	void outputLog(const char * mess);
};

template<class T>
TextView<T>::TextView(myString * str)
	:t_str(str)
{
	outputLog("Constructor");
}

template<class T>
TextView<T>::TextView(const TextView<T> & other)
	:t_str(other.t_str)
{
	outputLog("Copy constructor(&)");
	std::cout << *t_str 
		<< std::endl;
}

template<class T>
TextView<T>::TextView(const TextView<T> && other) noexcept
{
	outputLog("Move constructor(&&)");
	t_str = std::move(other.t_str);
	other.t_str = nullptr;
	return *this;
}

template<class T>
TextView<T> & TextView<T>::operator=(const TextView<T> & other)
{
	outputLog("Copy assignment operator");
	TextView<T> temp_t(other);
	std::swap(t_str, temp_t.t_str);
	return * this;
}

template<class T>
TextView<T> & TextView<T>::operator=(TextView<T> && other)
{
	outputLog("Move assignment operator");
	std::swap(t_str, other.t_str);
	return * this;
}

template<class T>
TextView<T>::~TextView() noexcept
{
	outputLog("Destructor");
	if (t_str)
	{
		delete[] t_str;
	}
}

template<class T>
void TextView<T>::outputLog(const char * mess)
{
	std::cout << "[" << this << "] " 
		<< mess << "\n";
}
