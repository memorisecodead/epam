#include <iostream>
#include "Instruments.h"

int main()
{
	srand(time(NULL));
	unsigned int SIZE = 10;
	std::vector<int> v(10);
	std::string strfind{ 0 };
	const unsigned int count = 5;
	pushOfVector(v, SIZE);
	int kValue = 0;

	std::cout << "The Vector with random values: " << std::endl;
	SortOfVector(v);

	Foo(v, [&](int a)
		{
			std::cout << "Anonimous values of foo: " << a << std::endl;
		});

	std::cout << std::endl;
	std::cout << "Write of your str: " << std::endl;
	std::getline(std::cin, strfind);
	
	std::array<std::string, count> arrOfStr{"banana","cake","murshmellow","cherry","purple"};

	auto foundStr
	{
		std::find_if(arrOfStr.begin(),arrOfStr.end(),[&](std::string str)
			{
				return (str.find(strfind) != std::string::npos);
			})
	};

	foundOfStr(arrOfStr, foundIt);

	std::vector<int> vv{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int>::iterator it = vv.begin();

	//for (int i = 0; i < SIZE; ++i)
	//{
	//	vv[i] = rand() % 10;
	//}

	SortOfVector(vv);

	std::cout << "Enter a K position to change vector: "
		<< std::endl << std::endl;
	std::cin >> kValue;

	vv.erase(it, it + kValue);

	Foo(vv, [&](int a)
		{
			std::cout << "Anonimous values of foo: " << a << std::endl;
		});

	return 0;
}