#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>
#include <deque>

namespace pointer
{
	template<class T>
	class SmartPointer
	{
	public:
		using Allocator = pointer::SmartPointer<T>;
	public:
		SmartPointer();
		SmartPointer(T* obj);

		void allocateObj(unsigned int size);
		void deallocateObj(void* pointer, unsigned int size);

		T* operator->();
		T& operator*();

		~SmartPointer();

	private:
		unsigned int m_available = 0;
		unsigned int m_allocations = 0;
		T* m_obj;
		void outputLog(const char* mess);
	};
}

template<class T>
pointer::SmartPointer<T>::SmartPointer()
	:m_obj{nullptr},m_available{0},m_allocations{0}
{
}

template<class T>
pointer::SmartPointer<T>::SmartPointer(T * obj)
	:m_obj{ obj }
{
}

template<class T>
void pointer::SmartPointer<T>::allocateObj(unsigned int size)
{
	auto memory = m_obj;
	m_available -= size;
	m_obj += size;
	++m_allocations;
	return memory;
}

template<class T>
void pointer::SmartPointer<T>::deallocateObj(void* pointer, unsigned int size)
{
	auto memory = (T*)pointer;
	if (memory + size == m_obj)
	{
		m_obj = memory;
		m_available += size;
	}
}

template<class T>
T* pointer::SmartPointer<T>::operator->()
{
	return m_obj;
}

template<class T>
inline T& pointer::SmartPointer<T>::operator*()
{
	return *m_obj;
}

template<class T>
pointer::SmartPointer<T>::~SmartPointer()
{
	delete[] m_obj;
}

template<class T>
void pointer::SmartPointer<T>::outputLog(const char * mess)
{
	std::cout << "[" << this << "] "
		<< mess << "\n";
}

