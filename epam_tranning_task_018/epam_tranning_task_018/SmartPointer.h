#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>
#include <deque>

template<class T>
class SmartPointer
{
public:
	SmartPointer();
	SmartPointer(T * obj);

	void allocateObj(unsigned int size);
	void deallocateObj(void * pointer, unsigned int size);

	T * operator->();
	T & operator*();

	~SmartPointer();

private:
	unsigned int m_available = 0;
	unsigned int m_allocations = 0;
	T* m_obj;
	void outputLog(const char* mess);
};

template <class AllocatorType>
class Allocator
{
public:

	using value_type = AllocatorType;
	using Traits = std::allocator_traits<Allocator<AllocatorType>>;
	using size_type = typename std::allocator<AllocatorType>::size_type;
	using difference_type = typename std::allocator<AllocatorType>::difference_type;
	using pointer = typename std::allocator<AllocatorType>::pointer;
	using const_pointer = typename std::allocator<AllocatorType>::const_pointer;
	// "reference" не входит Allocator Requirements,
	// но libstdc++ думает что она всегда работает с std::allocator.
	using reference = typename std::allocator<AllocatorType>::reference;
	using const_reference = typename std::allocator<AllocatorType>::const_reference;

	Allocator();
	template<class T> explicit Allocator(SmartPointer<T> & pointer);
	template <class T> Allocator(const Allocator<T> & other);

	AllocatorType* allocateObj(unsigned int size);
	void deallocateObj(AllocatorType* p, unsigned int size);

	template <class T> void destroyAllocator(T * pointer);
	template <class T> class rebind { using otherAlloc = Allocator<T>; };

private:
	SmartPointer<AllocatorType> * m_sm;
};

template<class T>
SmartPointer<T>::SmartPointer()
	:m_obj{nullptr},m_available{0},m_allocations{0}
{
}

template<class T>
SmartPointer<T>::SmartPointer(T * obj)
	:m_obj{ obj }
{
}

template<class T>
void SmartPointer<T>::allocateObj(unsigned int size)
{
	auto memory = m_obj;
	m_available -= size;
	m_obj += size;
	++m_allocations;
	return memory;
}

template<class T>
void SmartPointer<T>::deallocateObj(void* pointer, unsigned int size)
{
	auto memory = (T*)pointer;
	if (memory + size == m_obj)
	{
		m_obj = memory;
		m_available += size;
	}
}

template<class T>
T* SmartPointer<T>::operator->()
{
	return m_obj;
}

template<class T>
inline T& SmartPointer<T>::operator*()
{
	return *m_obj;
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
	delete[] m_obj;
}

template<class T>
void SmartPointer<T>::outputLog(const char * mess)
{
	std::cout << "[" << this << "] "
		<< mess << "\n";
}

template<class AllocatorType>
Allocator<AllocatorType>::Allocator()
	:m_sm{ nullptr }
{
}

template<class AllocatorType>
AllocatorType* Allocator<AllocatorType>::allocateObj(unsigned int size)
{
	return (AllocatorType*)m_sm->allocateObj(size * sizeof(AllocatorType));
}

template<class AllocatorType>
void Allocator<AllocatorType>::deallocateObj(AllocatorType* p, unsigned int size)
{
	m_sm->deallocateObj(p, size * sizeof(AllocatorType));
}

template<class AllocatorType>
template<class T>
Allocator<AllocatorType>::Allocator(SmartPointer<T>& pointer)
	:m_sm{ &pointer }
{

}

template<class AllocatorType>
template<class T>
Allocator<AllocatorType>::Allocator(const Allocator<T>& other)
	:m_sm{ other.m_sm }
{
}

template<class AllocatorType>
template<class T>
void Allocator<AllocatorType>::destroyAllocator(T* pointer)
{
	std::allocator<T>().destroy(AllocatorType);
}
