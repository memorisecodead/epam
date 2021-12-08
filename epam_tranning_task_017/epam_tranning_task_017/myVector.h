#pragma once
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <cassert>

#include "IteratorTraits.h"

namespace DataStructure
{
	template<class T>
	using Iterator = IteratorTraits::Iterator<T>;

	template <class T>
	class MyVector
	{
	public:

		using value_type = T;
		using pointer_type = T*;
		using reference_type = T&;
		using difference_type = std::ptrdiff_t;
		using iterator = Iterator<MyVector<T>>;
		using const_iterator = Iterator<const MyVector<T>>;

	public:
		MyVector();
		MyVector(unsigned int size); //UPD
		MyVector(unsigned int size, const T& obj); //UPD
		MyVector(const MyVector& v);
		MyVector(const MyVector&& v);

		void reAlloc();

		//TBD
		DataStructure::MyVector<T>& operator=(const DataStructure::MyVector<T>& v);
		DataStructure::MyVector<T>& operator=(const DataStructure::MyVector<T>&& v); //UPD
		MyVector& operator=(const T& v);
		const T& operator[](int index) const;
		T& operator[](T index);
		MyVector<T>& operator=(std::initializer_list<T> v); //UPD

		T size() const;
		unsigned int capacity() const;
		T getIndex(const T& value) const;
		bool empty();
		T & frontValue(); //UPD
		T & backValue(); //UPD

		void push_back(T& value); //UPD
		void push_back(T&& value); //UPD
		template<class ...Args>
		T& emplace_back(Args &&... args);
		void pop_back();
		void insert(IteratorTraits::Iterator<T> index, unsigned int size, const T& value);
		MyVector<T> insert(const int index, T& value);
		void assign(unsigned int size, const T& value);
		void reserve(unsigned int capacity);

		void showVector();

		iterator begin() { return iterator(m_arr); }
		iterator end() { return iterator(m_arr + m_size); }

		const_iterator cbegin() const { return const_iterator(m_arr); }
		const_iterator cend() const { return const_iterator(m_arr + m_size); }

		void clear();
		~MyVector();
	private:
		T* m_arr;
		unsigned int m_capacity;
		unsigned int m_size;
	};

	template<class T>
	MyVector<T>::~MyVector()
	{
		clear();
		delete[] m_arr;
	}

	template<class T>
	void MyVector<T>::showVector()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << m_arr[i] << std::endl;
		}
	}

	template<class T>
	DataStructure::MyVector<T>& MyVector<T>::operator=(const DataStructure::MyVector<T>& v)
	{
		if (this == &v)
		{
			return *this;
		}

		m_arr = v.m_arr;
		m_size = v.m_size;
		m_capacity = v.m_capacity;
	}

	template<class T>
	DataStructure::MyVector<T>& MyVector<T>::operator=(const DataStructure::MyVector<T>&& v)
	{
		std::swap(m_size, v.m_size);
		std::swap(m_capacity, v.m_capacity);
		std::swap(m_arr, v.m_arr);

		return *this;
	}

	template<class T>
	MyVector<T>& MyVector<T>::operator=(const T& v)
	{
		std::swap(*this, v);
		return *this;
	}

	template<class T>
	const T& MyVector<T>::operator[](int index) const
	{
		if (index < 0 && index >= m_size)
			throw std::exception("Index out of range!");
		return m_arr[index];
	}

	template<class T>
	T& MyVector<T>::operator[](T index)
	{
		return operator[](index);
	}

	template<class T>
	MyVector<T>& MyVector<T>::operator=(std::initializer_list<T> v)
	{
		assign(v.begin(), v.end());
		return *this;
	}

	template<class T>
	void MyVector<T>::push_back(T & value)
	{
		if (m_size == m_capacity)
		{
			m_capacity <<= 2;
			reAlloc();
		}
		m_arr[m_size] = value;
		++m_size;
	}

	template<class T>
	void MyVector<T>::push_back(T&& value)
	{
		if (m_size == m_capacity)
		{
			m_capacity <<= 2;
			reAlloc();
		}
		m_arr[m_size] = std::move(value);
		++m_size;
	}

	template<class T>
	MyVector<T> MyVector<T>::insert(const int index, T& value)
	{
		T* current = new T[m_capacity];

		for (int i = 0; i < m_size; ++i)
		{
			current[i] = m_arr[i];
		}

		delete[] m_arr;
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
	void MyVector<T>::assign(unsigned int size, const T& value)
	{
		std::fill(size, value);
	}

	template<class T>
	void MyVector<T>::reserve(unsigned int capacity)
	{
		if (capacity > m_capacity)
		{
			m_capacity = capacity;
			reAlloc();
		}
	}
	template<class T>
	void MyVector<T>::pop_back()
	{
		if (m_size > 0)
		{
			m_arr[--m_size].~T();
		}
	}

	template<class T>
	void MyVector<T>::insert(IteratorTraits::Iterator<T> index, unsigned int size, const T& value)
	{
		std::fill(index, size, value);
	}

	template<class T>
	T MyVector<T>::getIndex(const T& value) const
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
	void MyVector<T>::clear()
	{
		for (auto i = 0; i < m_size; ++i)
		{
			m_arr[i].~T();
		}

		m_size = 0;
	}

	template<class T>
	T MyVector<T>::size() const
	{
		std::cout << "Size of vector:" << std::setw(4) << m_size
			<< std::endl << std::endl;
		return m_size;
	}

	template<class T>
	bool MyVector<T>::empty()
	{
		return m_size == 0 ? true : false;
	}

	template<class T>
	MyVector<T>::MyVector()
	{
		m_size = 0;
		m_capacity = 4;
		m_arr = new T[m_capacity];
	}

	template<class T>
	MyVector<T>::MyVector(unsigned int size)
	{
		m_capacity = size;
		m_size = size;
		m_arr = new T[size];
	}

	template<class T>
	MyVector<T>::MyVector(unsigned int size, const T & obj)
	{
		m_size = size;
		m_capacity = size;
		m_arr = new T[size];
		for (unsigned int i = 0; i < size; ++i)
		{
			m_arr[i] = obj;
		}
	}

	template<class T> //upd
	MyVector<T>::MyVector(const MyVector& v)
	{
		m_size = v.m_size;
		m_capacity = v.m_capacity;
		m_arr = new T[m_size];

		for (unsigned int i = 0; i < m_size; ++i)
		{
			m_arr[i] = v.m_arr[i];
		}
	}

	template<class T>
	MyVector<T>::MyVector(const MyVector&& v)
		:m_size(std::move(v.m_size)), m_capacity(std::move(v.m_capacity)),
		m_arr(std::move(v.m_arr))
	{
	}

	template<class T>
	void MyVector<T>::reAlloc()
	{
		T* temp_arr = new T[m_capacity];
		std::memcpy(temp_arr, m_arr, m_size * sizeof(T));
		delete[] m_arr;
		m_arr = temp_arr;
	}

	template<class T>
	template<class ...Args>
	T& MyVector<T>::emplace_back(Args && ...args)
	{
		if (m_size >= m_capacity)
		{
			reAlloc(m_capacity + m_capacity / 2);
		}

		new (&m_arr[++m_size]) T(std::forward<T>(args)...);
		return m_arr[++m_size];
	}

	template<class T>
	T& MyVector<T>::frontValue()
	{	
		return m_arr[0];
	}

	template<class T>
	T& MyVector<T>::backValue()
	{
		return m_arr[m_size - 1];
	}

	template<class T>
	unsigned int MyVector<T>::capacity() const
	{
		return m_capacity;
	}
}
