#include <iostream>
#include <vector>
#include <algorithm>
#include "myVector.h"
#include "Timer.h"

int main()
{
	int count = 10;
	myVector<int> v(10);
	std::vector<int> v_default(10);

	v.fill_array(v, 10);

	for (auto i = 0; i < count; ++i)
	{
		v_default[i] = rand() % 10;
	}

	v.size();
	v.shakerSort(count);
	v.sortOfShell(count);

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

	v.find(v,4);

	return 0;
}