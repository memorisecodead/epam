#pragma once
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cassert>
#include <iterator>

template <class Vector>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, Vector>
{
public:
 	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
	using Valueñategory = std::random_access_iterator_tag;
	using Difference_type = std::ptrdiff_t;
public:
	VectorIterator(PointerType ptr)
	:m_ptr{ ptr }
	{
	}

	VectorIterator& operator++()
	{
		++m_ptr;
		return *this;
	}
	VectorIterator& operator++(int index)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}
	VectorIterator& operator--()
	{
		--m_ptr;
		return *this;
	}
	VectorIterator& operator--(int index)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	Difference_type operator+ (VectorIterator v) const { return m_ptr + v.m_ptr; }
	friend std::ptrdiff_t operator- (VectorIterator v, VectorIterator _v);

	ReferenceType operator[](int index) { return *(m_ptr + index); }
	ReferenceType operator* () { return *m_ptr; }
	PointerType operator->() { return m_ptr; }

	bool operator==(const VectorIterator& other) const { return m_ptr == other.m_ptr; }
	bool operator!=(const VectorIterator& other) const { return !(*this == other); }
	bool operator< (const VectorIterator& other) const { return	*m_ptr < *other.m_ptr; }
private:
	PointerType m_ptr;
};

template <class T>
class myVector
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<myVector<T>>;
public:
	myVector();
	myVector(unsigned int && size);
	myVector(T * obj);
	myVector(const myVector & v);

	myVector& operator=(const myVector& v);
	myVector& operator=(const T & v);
	T& operator[](T index) const;
	T& operator=(const T * v);
	const T& operator[](unsigned int index) const;

	T getIndex(const T& value) const;
	T size() const;
	bool empty();

	void push_back(T & value);
	void push_back(T && value);
	template<class ...Args>
	T& emplace_back(Args &&... args);
	void pop_back();
	myVector insert(const int index, T & value); // dd+

	void showVector();

	Iterator begin() { return Iterator(m_arr); }
	Iterator end() { return Iterator(m_arr + m_size); }

	void clear();
	~myVector();
private:
	T * m_arr;
	unsigned int m_capacity;
	unsigned int m_size;
};

template<class T>
myVector<T>::~myVector()
{
	clear();
	delete [] m_arr;
}

template<class T>
void myVector<T>::showVector()
{
	std::cout << "Values of vector:" << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_arr[i] << std::endl;
	}
}

template<class T>
myVector<T>& myVector<T>::operator=(const myVector& v)
{
	std::swap(*this, v);
	return *this;
}

template<class T>
myVector<T>& myVector<T>::operator=(const T& v)
{
	std::swap(*this, v);
	return *this;
}

template<class T>
T& myVector<T>::operator[](T index) const
{
	return m_arr[index];
}

template<class T>
T& myVector<T>::operator=(const T* v)
{
	std::swap(*this, *v);
	return *this;
}

template<class T>
const T& myVector<T>::operator[](unsigned int index) const
{
	if (index >= m_size)
	{
		assert("index better than size!");
	}
	return m_arr[index];
}

template<class T>
void myVector<T>::push_back(T & value)
{
	if (m_size >= m_capacity)
	{
		auto capacity = m_capacity * 2;
		
		T * result = new T[capacity];

		for (auto i = 0; i < m_size; ++i)
		{
			result[i] = m_arr[i];
		}

		delete[] m_arr;
		m_arr = result;

		m_capacity = capacity;
	}

	m_arr[++m_size] = value;	
}

template<class T>
void myVector<T>::push_back(T&& value)
{
	if (m_size >= m_capacity)
	{
		auto capacity = m_capacity * 2;

		T* result = new T[capacity];

		for (auto i = 0; i < m_size; ++i)
		{
			result[i] = m_arr[i];
		}

		delete[] m_arr;
		m_arr = result;

		m_capacity = capacity;
	}

	m_arr[++m_size] = value;
}

template<class T>
myVector<T> myVector<T>::insert(const int index, T & value)
{
	T * current = new T[m_capacity];

	for (int i = 0; i < m_size; ++i)
	{
		current[i] = m_arr[i];
	}

	delete [] m_arr;
	m_arr = nullptr;

	m_arr = new T[m_capacity + 1];

	for (int i = 1; i < index; ++i)
	{
		m_arr[i] = current[i];
	}

	++m_size;
	m_arr[m_capacity - 1] = value;

	delete[] current;
	current = nullptr;

	return *this;
}

template<class T>
void myVector<T>::pop_back()
{
	if (m_size > 0)
	{
		m_arr[--m_size].~T();
	}
}

template<class T>
T myVector<T>::getIndex(const T & value) const
{
	for (int i = 0; i < m_size; ++i)
	{
		if (value == m_arr[i])
		{
			return i;
		}
		std::cout << "Index not found" << std::endl;
	}

}

template<class T>
void myVector<T>::clear()
{
	std::cout << "Destrucor of vector.\n";
	for (auto i = 0; i < m_size; ++i)
	{
		m_arr[i].~T();
	}

	m_size = 0;
}

template<class T>
T myVector<T>::size() const
{
	std::cout << "Size of vector:" << std::setw(4) << m_size
		<< std::endl << std::endl;
	return m_size;
}

template<class T>
bool myVector<T>::empty()
{
	return m_size == 0 ? true : false;
}

template<class T>
myVector<T>::myVector()
{
	m_size = 0;
	m_capacity = m_size * 2;
	m_arr = new T[m_capacity];
}

template<class T>
myVector<T>::myVector(unsigned int && size)
{
	m_size = size;
	m_capacity = size * 2;
	m_arr = new T[m_capacity];

	for (auto i = 0; i < size; i++)
	{
		m_arr[i] = i;
	}
}

template<class T>
myVector<T>::myVector(T * obj)
{
	m_size = 10;
	m_capacity = m_size * 2;
	m_arr = new T[m_capacity];

	for (auto it = 0; it < m_size; ++it)
	{
		m_arr[it] = obj[it] ;
	}
}

template<class T>
myVector<T>::myVector(const myVector& v)
{
	m_size = v.m_size;
	m_arr = new T[m_capacity];

	std::copy(v.m_arr, v.m_arr + m_size, v.m_arr);
}

template<class T>
template<class ...Args>
T& myVector<T>::emplace_back(Args && ...args)
{
	if (m_size >= m_capacity)
	{
		auto capacity = m_capacity * 2;

		T* result = new T[capacity];

		for (auto i = 0; i < m_size; ++i)
		{
			result[i] = m_arr[i];
		}

		delete[] m_arr;
		m_arr = result;

		m_capacity = capacity;
	}

	new (&m_arr[++m_size]) T(std::forward<T>(args)...);
	return m_arr[++m_size];
}

template<typename T>
std::ptrdiff_t operator-(VectorIterator<T> v, VectorIterator<T> _v) 
{
	return v.m_ptr - _v.m_ptr; 
}