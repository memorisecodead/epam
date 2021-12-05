#pragma once
#include <iostream>
#include <iomanip>
#include <iterator>

template <class T>
class Iterator;

#pragma region("Vector implementation")
template <class T>
class myVector
{
public:
	
	using value_type = T;
	using pointer_type = T*;
	using reference_type = T&;
	using difference_type = std::ptrdiff_t;
	using iterator = Iterator<myVector<T>>;
	using const_iterator = Iterator<const myVector<T>>;

public:
	myVector();
	myVector(unsigned int& size);
	myVector(T* obj);
	myVector(const myVector& v);

	//TBD
	//myVector& operator=(const myVector& v);
	myVector& operator=(const T& v);
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
	myVector insert(const int index, T& value); // dd+

	void showVector();

	iterator begin() { return iterator(m_arr); }
	iterator end() { return iterator(m_arr + m_size); }

	const_iterator cbegin() const { return const_iterator(m_arr); }
	const_iterator cend() const { return const_iterator(m_arr + m_size); }

	void clear();
	~myVector();
private:
	T* m_arr;
	std::size_t  m_capacity;
	std::size_t m_size;
};

template<class T>
myVector<T>::~myVector()
{
	clear();
	delete[] m_arr;
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

//template<class T>
//myVector<T>& myVector<T>::operator=(const myVector& v)
//{
//	std::swap(*this, v);
//	return *this;
//}

template<class T>
myVector<T>& myVector<T>::operator=(const T& v)
{
	std::swap(*this, v);
	return *this;
}

template<class T>
const T& myVector<T>::operator[](int index) const
{
	if (index < 0 && index >= m_size)
		throw std::exception("Index out of range!");
	return m_arr[index];
}

template<class T>
T& myVector<T>::operator[](T index)
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
void myVector<T>::push_back(T& value)
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
myVector<T> myVector<T>::insert(const int index, T& value)
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
void myVector<T>::pop_back()
{
	if (m_size > 0)
	{
		m_arr[--m_size].~T();
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
myVector<T>::myVector(unsigned int& size)
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
myVector<T>::myVector(T* obj)
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
#pragma endregion

template <class T>
class Iterator
{
public:

 	using value_type = typename T::value_type;
	using pointer = value_type*;
	using reference = value_type&;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::random_access_iterator_tag;

	Iterator(pointer ptr = nullptr)
	: m_ptr{ ptr }
	{}
	Iterator(const Iterator<T>& rawIterator) = default;

	Iterator<T>& operator=(const Iterator<T>& rawIterator) = default;
	Iterator<T>& operator=(T* ptr) { m_ptr = ptr; return (*this); }

	pointer get_ptr() { return m_ptr; }

	const pointer get_const_ptr() const { return m_ptr; }

	bool operator==(const Iterator<T>& rawIterator)const { return (m_ptr == rawIterator.get_const_ptr()); }
	bool operator!=(const Iterator<T>& rawIterator)const { return (m_ptr != rawIterator.get_const_ptr()); }

	Iterator<T>& operator++() { ++m_ptr; return (*this); }
	Iterator<T>& operator--() { --m_ptr; return (*this); }

	Iterator<T> operator++(int offset) { auto temp(*this); ++m_ptr; return temp; }
	Iterator<T> operator--(int offset) { auto temp(*this); --m_ptr; return temp; }

	Iterator<T>& operator+=(int offset) { m_ptr += offset; return (*this); }
	Iterator<T>& operator-=(int offset) { m_ptr -= offset; return (*this); }

	Iterator<T> operator+(const difference_type& movement) { Iterator<T> it(*this);	return it += movement;}
	Iterator<T> operator-(const difference_type& movement) { Iterator<T> it(*this);	return it -= movement;}

	difference_type operator-(const Iterator<T>& rawIterator) const { return std::distance(rawIterator.get_const_ptr(), this->get_const_ptr()); }
	
	bool operator<(const Iterator<T>& other) const { return this->get_const_ptr() < other.get_const_ptr(); }
	bool operator<= (const Iterator<T>& other) const { return this->get_const_ptr() <= other.get_const_ptr(); }
	bool operator>  (const Iterator<T>& other) const { return this->get_const_ptr() >  other.get_const_ptr(); }
	bool operator>= (const Iterator<T>& other) const { return this->get_const_ptr() >= other.get_const_ptr(); }
	bool operator== (const Iterator<T>& other) const { return this->get_const_ptr() == other.get_const_ptr(); }
	bool operator!= (const Iterator<T>& other) const { return this->get_const_ptr() != other.get_const_ptr(); }

	reference operator*() { return *m_ptr; }
	const reference operator*() const { return *m_ptr; }

	pointer operator->() { return m_ptr; }
	const pointer operator->() const { return m_ptr; }

	reference operator[](int offset) { return m_ptr[offset]; }
	const reference operator[](int offset) const { return m_ptr[offset]; }

protected:
	pointer m_ptr;
};

