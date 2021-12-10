#include <iostream>
#include <vector>
#include <algorithm>
#include "myVector.h"
#include "Timer.h"

int main()
{
	unsigned int count = 10000;
	DataStructure::MyVector<int> v(count);
	std::vector<int> v_default(count);

	v.fill(v, count);

	for (auto i = 0; i < count; ++i)
	{
		v_default[i] = rand() % 10;
	}

	v.size();
	v.shakeSort(count);
	v.shellSort(count);

	{
		std::cout << std::endl;
		std::cout << "Algorithm of sort:";
		Timer tm;
		std::sort(v_default.begin(), v_default.end());
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "Algorithm of find:" << std::endl;
		Timer tm;
		auto result = std::find(v_default.begin(), v_default.end(), 4);

		if (result == v_default.end())
		{
			std::cout << "Value isn't find! " << std::endl;
		}
		else
		{
			std::cout << "Value is find!" << std::endl;
		}
	}

	v.customFind(v,4);

	return 0;
}