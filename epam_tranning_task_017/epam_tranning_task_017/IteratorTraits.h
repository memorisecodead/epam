#pragma once

namespace IteratorTraits
{
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

		Iterator<T>& operator++() { ++m_ptr; return (*this); }
		Iterator<T>& operator--() { --m_ptr; return (*this); }

		Iterator<T> operator++(int offset) { auto temp(*this); ++m_ptr; return temp; }
		Iterator<T> operator--(int offset) { auto temp(*this); --m_ptr; return temp; }

		Iterator<T>& operator+=(int offset) { m_ptr += offset; return (*this); }
		Iterator<T>& operator-=(int offset) { m_ptr -= offset; return (*this); }

		Iterator<T> operator+(const difference_type& offset) { Iterator<T> it(*this);	return it += offset; }
		Iterator<T> operator-(const difference_type& offset) { Iterator<T> it(*this);	return it -= offset; }

		difference_type operator-(const Iterator<T>& other) const { return std::distance(other.get_const_ptr(), this->get_const_ptr()); }

		bool operator==(const Iterator<T>& other)const { return (this->get_const_ptr() == other.get_const_ptr()); }
		bool operator!=(const Iterator<T>& other)const { return (this->get_const_ptr() != other.get_const_ptr()); }
		bool operator<(const Iterator<T>& other) const { return this->get_const_ptr() < other.get_const_ptr(); }
		bool operator<= (const Iterator<T>& other) const { return this->get_const_ptr() <= other.get_const_ptr(); }
		bool operator>  (const Iterator<T>& other) const { return this->get_const_ptr() > other.get_const_ptr(); }
		bool operator>= (const Iterator<T>& other) const { return this->get_const_ptr() >= other.get_const_ptr(); }

		reference operator*() { return *m_ptr; }
		const reference operator*() const { return *m_ptr; }

		pointer operator->() { return m_ptr; }
		const pointer operator->() const { return m_ptr; }

		reference operator[](int offset) { return m_ptr[offset]; }
		const reference operator[](int offset) const { return m_ptr[offset]; }

	protected:
		pointer m_ptr;
	};
}
