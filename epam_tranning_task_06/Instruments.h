#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <array>
#include <string_view>

std::array<std::string, 5>::iterator foundIt;

void Foo(std::vector<int>& v, std::function<void(int)> fx)
{
	for (auto el : v)
	{
		fx(el);
	}
}

void SortOfVector(std::vector<int>& v)
{
	std::sort(v.begin(), v.end(), [](int a, int b)
		{
			return a > b;
		});
}

void foundOfStr(std::array<std::string, 5> & myArr, std::array<std::string, 5>::iterator foundIt)
{
	if (foundIt == myArr.end())
	{
		std::cout << "No words :(" 
			<< std::endl << std::endl;
	}
	else
	{
		std::cout << "Found " << *foundIt 
			<< std::endl << std::endl;
	}
}

template <typename T>
void pushOfVector(std::vector<T>& v, unsigned int & SIZE)
{
	for (auto i = 0; i < SIZE; ++i)
	{
		v[i] = rand() % 100 - 50;
	}
}

//template <typename T>
//void sortOfvector(std::vector<T> & v, unsigned int & SIZE)
//{
//	unsigned int countswap = 0;
//	for (int i = 1; i < SIZE; ++i)
//	{
//		for (int j = 0; j < SIZE - 1; ++j)
//		{
//			if (v[j] < v[j + 1])
//			{
//				int temp = v[j + 1];
//				v[j + 1] = v[j];
//				v[j] = temp;
//				++countswap;
//			}
//		}
//	}
//	std::cout << countswap << " :count of swap in vector"
//		<< std::endl << std::endl;
//}