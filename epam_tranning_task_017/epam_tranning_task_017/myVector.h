#pragma once
#include <iostream>
#include <iomanip>
#include <iterator>

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
		MyVector(unsigned int& size);
		MyVector(T* obj);
		MyVector(const MyVector& v);

		//TBD
		//myVector& operator=(const myVector& v);
		MyVector& operator=(const T& v);
		const T& operator[](int index) const;
		T& operator[](T index);

		//TBD
		//T& operator=(const T* v);

		T getIndex(const T& value) const;
		T size() const;
		bool empty();

		void push_back(T& value);
		void push_back(T&& value);
		template<class ...Args>
		T& emplace_back(Args &&... args);
		void pop_back();
		MyVector insert(const int index, T& value);

		void showVector();

		iterator begin() { return iterator(m_arr); }
		iterator end() { return iterator(m_arr + m_size); }

		const_iterator cbegin() const { return const_iterator(m_arr); }
		const_iterator cend() const { return const_iterator(m_arr + m_size); }

		void clear();
		~MyVector();
	private:
		T* m_arr;
		std::size_t  m_capacity;
		std::size_t m_size;
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
		std::cout << "Values of vector:" << std::endl;
		for (int i = 0; i < m_size; i++)
		{
			std::cout << m_arr[i] << std::endl;
		}
	}

	//template<class T>
	//myVector<T>& myVector<T>::operator=(const myVector& v)
	//{
	//	std::swap(*this, v);
	//	return *this;
	//}

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

	//template<class T>
	//T& myVector<T>::operator=(const T* v)
	//{
	//	std::swap(*this, *v);
	//	return *this;
	//}

	template<class T>
	void MyVector<T>::push_back(T& value)
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
	void MyVector<T>::push_back(T&& value)
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
	void MyVector<T>::pop_back()
	{
		if (m_size > 0)
		{
			m_arr[--m_size].~T();
		}
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
		std::cout << "Destrucor of vector.\n";
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
		m_capacity = m_size * 2;
		m_arr = new T[m_capacity];
	}

	template<class T>
	MyVector<T>::MyVector(unsigned int& size)
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
	MyVector<T>::MyVector(T* obj)
	{
		m_size = 10;
		m_capacity = m_size * 2;
		m_arr = new T[m_capacity];

		for (auto it = 0; it < m_size; ++it)
		{
			m_arr[it] = obj[it];
		}
	}

	template<class T>
	MyVector<T>::MyVector(const MyVector& v)
	{
		m_size = v.m_size;
		m_arr = new T[m_capacity];

		std::copy(v.m_arr, v.m_arr + m_size, v.m_arr);
	}

	template<class T>
	template<class ...Args>
	T& MyVector<T>::emplace_back(Args && ...args)
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
}
