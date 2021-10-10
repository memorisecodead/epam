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
	myVector & operator=(const myVector & v);
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

template <class T>
class DynamicVector : public myVector<T>
{
public:
	/*using DynamicVector<T>::m_size;
	using DynamicVector<T>::m_capacity;*/
	/*using DynamicVector<T>::m_arr;*/

	DynamicVector()
	{
		m_column = 0;
		this->m_size = 0;
		m_dvarr = nullptr;
		this->m_capacity = 0;
	}

	DynamicVector(T& size, T& column)
	{
		srand(time(NULL));
		m_dvarr = new T * [size];
		this->m_size = size;
		m_column = column;

		T** arr = new T * [size];

		for (int i = 0; i < size; i++)
		{
			m_dvarr[i] = new T[column];
		}

		for (int i = 0; i < size; ++i)
		{
			arr[i] = new T[column];

		}

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				arr[i][j] = rand() % 100 - 50;
			}
		}

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				m_dvarr[i][j] = arr[i][j];
			}

		}

		delete[] arr;

		showDynamicVector();
	}

	~DynamicVector()
	{
		for (int i = 0; i < this->m_size; ++i)
		{
			delete[] m_dvarr[i];
		}
		this->m_size = 0;
		this->m_capacity = 0;
	}

	void showDynamicVector()
	{
		system("pause");
		system("cls");
		std::cout << "Values of DynamicVector:" << std::endl;
		for (int i = 0; i < this->m_size; i++)
		{
			for (int j = 0; j < m_column; j++)
			{
				std::cout << std::setw(4) << m_dvarr[i][j] << " ";
			}
			std::cout << std::endl;
		}
		system("pause");
	}

	template<typename T>
	friend void determOfNegative(DynamicVector<T>& v)
	{
		int max = 0, min = 0;
		int maxI = 0, maxJ = 0;
		int i = 0;
		int j = 0;
		int count = 0;

		v.m_dvarr[0][0] = max;
		for (i = 0; i < v.m_size; ++i)
		{
			for (j = 0; j < v.m_size; ++j)
			{
				if (((!i) && (!j)) || (v.m_dvarr[i][j] > max))
				{
					max = v.m_dvarr[i][j];
					maxI = i;
					maxJ = j;
				}
			}
		}
		v.m_dvarr[maxI][maxJ] = v.m_dvarr[0][0];
		v.m_dvarr[0][0] = max;
		for (count = 1; i < v.m_size; ++count)
		{
			max = v.m_dvarr[0][1];
			for (j = 0; j < v.m_size; ++j)
			{
				for (int k = 0; k < v.m_size; ++k)
				{
					if (((i != j) || ((i >= count) && (j >= count)))
						&& (v.m_dvarr[i][j] > max))
					{
						max = v.m_dvarr[i][j];
						maxI = i;
						maxJ = j;
					}
				}
			}
			v.m_dvarr[maxI][maxJ] = v.m_dvarr[v.m_size][v.m_size];
			v.m_dvarr[v.m_size][v.m_size] = max;
		}
		v.showDynamicVector();
		for (i = 0; i < v.m_size; ++i)
		{
			int count = 0;
			for (j = 0; j < v.m_size; ++j)
			{
				if (v.m_dvarr[i][j] < 0)
				{
					++count;
				}
			}
			if (count == v.m_size)
			{
				std::cout << "Line #" << i + 1 << " has no negative values" << std::endl;
				system("pause");
			}
		}
	}
	
protected:
	int m_column;
	T** m_dvarr;

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
myVector<T>& myVector<T>::operator=(const myVector & v)
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
bool myVector<T>::pop(const T & index)
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
		--m_size;
		return true;
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
	m_capacity = 0;
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
}

template<class T>
myVector<T>::myVector(const myVector & v)
{
	m_arr = static_cast<T*>(malloc(v.size() * sizeof(T)));
	m_size = v.size();

	std::copy(v.m_arr, v.m_arr + m_size, v.m_arr);
}

//template<class T>
//DynamicVector<T>::DynamicVector()
//{
//	m_column = 0;
//	m_size = 0;
//	m_dvarr = nullptr;
//	m_capacity = 0;
//}

//template<class T>
//DynamicVector<T>::DynamicVector(T & size, T & column)
//{
//	srand(time(NULL));
//	m_dvarr = new T * [size];
//	m_size = size;
//	m_column = column;
//
//	T** arr = new T * [size];
//
//	for (int i = 0; i < size; i++)
//	{
//		m_dvarr[i] = new T[column];
//	}
//
//	for (int i = 0; i < size; ++i)
//	{
//		arr[i] = new T[column];
//	
//	}
//
//	for (int i = 0; i < size; ++i)
//	{
//		for (int j = 0; j < column; ++j)
//		{
//			arr[i][j] = rand() % 100 - 50;
//		}
//	}
//
//	for (int i = 0; i < size; ++i)
//	{
//		for (int j = 0; j < column; ++j)
//		{
//			m_dvarr[i][j]= arr[i][j];
//		}
//		
//	}
//
//	delete[] arr;
//
//	showDynamicVector();
//}

//template<class T>
//DynamicVector<T>::~DynamicVector()
//{
//	for (int i = 0; i < m_size; ++i)
//	{
//		delete[] m_dvarr[i];
//	}
//	m_size = 0;
//	m_capacity = 0;
//}

//template<class T>
//void DynamicVector<T>::showDynamicVector()
//{
//	system("cls");
//	for (int i = 0; i < m_size; i++)
//	{
//		for (int j = 0; j < m_column; j++)
//		{
//			std::cout <<std::setw(3) << m_dvarr[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//	system("pause");
//}