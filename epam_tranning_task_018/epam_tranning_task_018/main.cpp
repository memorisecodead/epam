#include <iostream>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "SmartPointer.h"

using a_string = std::basic_string<char, std::char_traits<char>, Allocator<char>>;
template <class T> using a_vector = std::vector<T, Allocator<T>>;
template <class T> using a_deque = std::deque<T, Allocator<T>>;
template <class T> using a_list = std::list<T, Allocator<T>>;
template <class K> using a_set = std::set<K, std::less<K>, Allocator<K>>;
template <class K, class V> using a_map = std::map<K, V, std::less<K>, Allocator<std::pair<const K, V>>>;
template <class K> using a_unordered_set = std::unordered_set<K, std::hash<K>, std::equal_to<K>, Allocator<K>>;
template <class K, class V> using a_unordered_map = std::unordered_map<K, std::hash<K>, std::equal_to<K>, Allocator<std::pair<const K, V>>>;


int main()
{
	SmartPointer<char> sm;
	Allocator<char> smartpointer_allocator(sm);
	a_vector<int> v_int({ 1, 2, 3 }, smartpointer_allocator);

	

	return 0;
}