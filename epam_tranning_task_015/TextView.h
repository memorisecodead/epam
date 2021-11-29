#pragma once
#include "myVector.h"
#include "myString.h"

template <class T>
class TextView 
{
public:
	TextView() noexcept;
	explicit TextView(const myString & str);

	TextView(const TextView<T> & other);
	TextView(const TextView<T> && other) noexcept;

	TextView & operator=(const TextView<T> & other);
	TextView & operator=(TextView<T> && other);
	
	~TextView() = default;
private:
	char * t_chr;
	unsigned int t_len;
	void outputLog(const char * mess);
};

template<class T>
TextView<T>::TextView() noexcept
	:t_chr{nullptr}, t_len{0}
{
	outputLog("Constructor");
}

template<class T>
TextView<T>::TextView(const myString & str)
	:t_chr{const_cast<char*>(str.data())},t_len{ str.size()}
{
	/*t_str->s_string = { const_cast<char*>(str.data()) };*/
	outputLog("Constructor with parametrs");
}

template<class T>
TextView<T>::TextView(const TextView<T> & other)
	:t_chr{other.t_chr }
{
	outputLog("Copy constructor(&)");
	std::cout << t_chr
		<< std::endl;
}

template<class T>
TextView<T>::TextView(const TextView<T> && other) noexcept
{
	outputLog("Move constructor(&&)");
	t_chr = std::move(other.t_chr);
}

template<class T>
TextView<T> & TextView<T>::operator=(const TextView<T> & other)
{
	outputLog("Copy assignment operator");
	TextView<T> temp_t(other);
	std::swap(t_chr, temp_t.t_chr);
	return * this;
}

template<class T>
TextView<T> & TextView<T>::operator=(TextView<T> && other)
{
	outputLog("Move assignment operator");
	std::swap(t_chr, other.t_chr);
	return * this;
}

//template<class T>
//TextView<T>::~TextView() noexcept
//{
//	outputLog("Destructor");
//	if (t_chr)
//	{
//		delete t_chr;
//	}
//}

template<class T>
void TextView<T>::outputLog(const char * mess)
{
	std::cout << "[" << this << "] " 
		<< mess << "\n";
}
