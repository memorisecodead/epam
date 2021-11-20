#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cassert>

template <class T>
class myVector
{
public:

	myVector();
	myVector(unsigned int & size);
	myVector(const myVector& v);
	~myVector();

	class myIterator
	{
	public:
		myIterator(const myVector<T>* v, int index);
		const T& operator*() const;
		myIterator& operator++();
		/*myIterator& operator++(T) { myIterator r(*this); ++it_index; return r; }*/
		bool operator!=(const myIterator& it) const;
	private:
		const myVector<T>* it_vector;
		int it_index = 0;
	};

	myVector& operator=(const myVector& v);
	/*bool operator!=(myVector& rls, myVector& lls);*/
	T getIndex(const T& value) const;
	T& operator[](T index) const;
	T size() const;
	bool empty();

	void push_back(T & value); // dd
	myVector insert(const int index, T & value); // dd
	bool pop_back(unsigned int & index); // dd
	myVector find(myVector<T> & v, int value);
	void clear();

	void summOfMassPastMinEl();
	void shakerSort(int& size);
	void sortOfShell(int& size);

	void showVector();
	void printSorted(T * v, int& size);

	myIterator begin() const;
	myIterator end() const;

protected:
	unsigned int m_capacity;
	T * m_arr;
	unsigned int m_size;
};


template<class T>
myVector<T>::~myVector()
{
	clear();
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
void myVector<T>::printSorted(T* v, int& size)
{
	std::cout << "Sort of vector:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

template<class T>
typename myVector<T>::myIterator myVector<T>::begin() const
{
	return myVector<T>::myIterator{ this, 0 };
}

template<class T>
typename myVector<T>::myIterator myVector<T>::end() const
{
	return myVector<T>::myIterator{ this, m_size };
}

template<class T>
myVector<T>& myVector<T>::operator=(const myVector& v)
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
void myVector<T>::push_back(T & value)
{
	if (m_size == m_capacity)
	{
		int capacity = m_capacity * 2;
		T* bufArr = new T[capacity];
		for (auto i = 0; i < m_size; ++i)
		{
			bufArr[i] = m_arr[i];
		}
		delete[] bufArr;
		m_arr = bufArr;
		m_capacity = capacity;
	}
	
	m_arr[m_size + 1] = value;
}

template<class T>
myVector<T> myVector<T>::insert(const int index, T & value)/*(const T & index, T && value)*/
{
	T * current = new T[m_size];

	for (int i = 0; i < m_size; ++i)
	{
		current[i] = m_arr[i];
	}

	delete [] m_arr;
	m_arr = nullptr;

	m_arr = new T[m_size + 1];

	for (int i = 1; i < index; ++i)
	{
		m_arr[i] = current[i];
	}

	++m_size;
	m_arr[m_size - 1] = value;

	delete[] current;
	current = nullptr;

	return *this;
}

template<class T>
bool myVector<T>::pop_back(unsigned int & index)
{
	if (index > m_size || empty())
	{
		--m_size;
		return false;
	}
	for (auto i = index; i < m_size; ++i)
	{
		std::swap(m_arr[i], m_arr[i + 1]);
	}
	/*
	if (!(m_arr = static_cast<T*>(realloc(m_arr, (m_size + 1) * sizeof(T)))))
	{
		throw std::cout << "Memory allocation error" << std::endl;
		--m_size;
		return true;
	}*/

	//if (empty())
	//{
	//	return 0;
	//}
	return true;
	//--m_size;
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
void myVector<T>::summOfMassPastMinEl()
{
	int min = 0;
	int sum = 0;
	for (int i = 0; i < m_size; ++i)
	{
		if (m_arr[i] < m_arr[0])
		{
			m_arr[0] = m_arr[i];
			min = i;
		}
	}

	for (int i = 0; i < m_size - min; ++i)
	{
		sum += m_arr[i];
	}
	std::cout << "Summ of values of massive:" << std::setw(4)
		<< sum << "\nMinimal element: " << std::setw(4) << m_arr[0] << std::endl;
}

template<class T>
void myVector<T>::shakerSort(int & size)
{
	int left, right, i;
	left = 0;
	right = size - 1;
	while (left <= right)
	{
		for (i = right; i >= left; i--)
		{
			if (m_arr[i - 1] > m_arr[i]) {
				std::swap(m_arr[i - 1], m_arr[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++)
		{
			if (m_arr[i - 1] > m_arr[i]) {
				std::swap(m_arr[i - 1], m_arr[i]);
			}
		}
		--right;
	}

	printSorted(m_arr, size);
}

template<class T>
void myVector<T>::sortOfShell(int& size)
{
	int d, i, j, count;
	d = size;
	d = d / 2;

	while (d > 0)
	{
		for (i = 0; i < size - d; ++i)
		{
			j = i;
			while (j >= 0 && m_arr[j] > m_arr[j + d])
			{
				count = m_arr[j];
				m_arr[j] = m_arr[j + d];
				m_arr[j + d] = count;
				--j;
			}
		}
		d = d / 2;
	}

	printSorted(m_arr, size);
	std::cout << std::endl;
}

template<class T>
void myVector<T>::clear()
{
	m_arr = nullptr;
	m_size = 0;
}

template<class T>
myVector<T> myVector<T>::find(myVector<T>& v, int value)
{
	for (auto i : v)
	{
		if (i == value)
		{
			std::cout << "In vector element is find: " << value << std::endl;
			return value;
		}
	}

	std::cout << "Value isn't find!" << std::endl;

	return value;
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
	return m_size = 0 ? true : false;
}

template<class T>
myVector<T>::myVector()
{
	m_size = 0;
	m_capacity = 0;
	m_arr = new T[m_size];
}

template<class T>
myVector<T>::myVector(unsigned int & size)
{
	srand(time(NULL));
	m_arr = static_cast<T*>(malloc(size * sizeof(T)));
	m_size = size;
	m_capacity = size * 2;
	//for (int i = 0; i < size; i++)
	//{
	//	m_arr[i] = rand() % 100 - 50;
	//}
}

template<class T>
myVector<T>::myVector(const myVector& v)
{
	m_arr = static_cast<T*>(malloc(v.m_size * sizeof(T)));
	m_size = v.m_size;

	std::copy(v.m_arr, v.m_arr + m_size, v.m_arr);
}

template<class T>
myVector<T>::myIterator::myIterator(const myVector<T>* v, int index)
	: it_vector(v), it_index(index)
{
}

template<class T>
const T& myVector<T>::myIterator::operator*() const
{
	return it_vector->operator[](it_index);
}

template<class T>
typename myVector<T>::myIterator& myVector<T>::myIterator::operator++()
{
	++it_index;
	return *this;
}

template<class T>
bool myVector<T>::myIterator::operator!=(const myIterator& it) const
{
	return it_index != it.it_index;
}
