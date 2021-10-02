#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

template <class T>
class myVector
{
public:
	myVector();
	myVector(T & size);
	myVector(const myVector & v);
	~myVector();

	void showVector();
	myVector& operator=(const myVector& v);
	T & operator[](T index) const;
	void push_back(T && value);
	/*myVector & insert(const T & index, T && value);*/
	bool pop(const T & index);
	T getIndex(const T & value) const;
	void summOfMassPastMinEl();
	void clear();

	T size() const;
	bool empty();

protected:
	int m_capacity;
	T * m_arr;
	int m_size;
};

template<class T>
myVector<T>::~myVector()
{
	clear();
}

template<class T>
void myVector<T>::showVector()
{
	system("cls");
	std::cout << "Values of vector:" << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_arr[i] << std::endl;
	}
	system("pause");
}

template<class T>
myVector<T> & myVector<T>::operator=(const myVector & v)
{
	std::swap(*this, v);
	return *this;
}

template<class T>
T & myVector<T>::operator[](T index) const
{
	return m_arr[index];
}

template<class T>
void myVector<T>::push_back(T && value)
{
	if (m_size == m_capacity)
	{
		int capacity = m_capacity * 1.5;
		T* bufArr = new T[capacity];
		for (auto i = 0; i < m_size; ++i)
		{
			bufArr[i] = m_arr[i];
		}
		delete[] bufArr;
		m_arr = bufArr;
		m_capacity = capacity;
	}
	m_arr[m_size++] = value;
}

//template<class T>
//myVector<T> & myVector<T>::insert()/*(const T & index, T && value)*/
//{
//	
	//myVector<T>* current = new myVector<T>[m_size];
	//for (int i = 0; i < m_size; ++i)
	//{
	//	current[i] = m_arr[i];
	//}
	//current[m_size] = value;

	//delete[] m_arr;
	//m_arr = new myVector<T>[m_size + 1];
	//for (int i = 0; i < index; ++i)
	//{
	//	m_arr[i] = current[i];
	//}
	//delete[] current;
	//return *this;

template<class T>
bool myVector<T>::pop(const T& index)
{
	if (index >= size() || empty())
	{
		return false;
	}
	for (int i = index; i < size(); ++i)
	{
		std::swap(m_arr[i], m_arr[i + 1]);
	}
	if (!(m_arr = static_cast<T*>(realloc(m_arr, (size() + 1) * sizeof(T)))))
	{
		throw std::cout << "Memory allocation error" << std::endl;
		--size;
		return true;
	}
}

template<class T>
T myVector<T>::getIndex(const T& value) const
{
	for (int i = 0; i < m_size; ++i)
	{
	if (value == m_arr[i])
	{ 
		return i;
	}
	std::cout << "Item not found" << std::endl;
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
void myVector<T>::clear()
{
	m_arr = nullptr;
	m_size = 0;
}

template<class T>
T myVector<T>::size() const
{
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
	m_arr = nullptr;
	m_size = 0;
	showVector();
}

template<class T>
myVector<T>::myVector(T & size)
{
	m_arr = static_cast<T*>(malloc(size * sizeof(T)));
	m_size = size;
	for (int i = 0; i < size; i++)
	{
		m_arr[i] = rand() % 100 - 50;
	}
	showVector();
}

template<class T>
myVector<T>::myVector(const myVector& v)
{
	m_arr = static_cast<T*>(malloc(v.size() * sizeof(T)));
	m_size = v.size();

	std::copy(v.m_arr, v.m_arr + m_size, v.m_arr);
	showVector();
}