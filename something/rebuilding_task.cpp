#include <iostream>
#include "Introdusted.h"

void translateToFarengeit(double inputValue);
bool evenValues(int i);
void Foo(std::vector<double>& v, std::function<void(double)> fx)
{
	for (auto el : v)
	{
		fx(el);
	}
}

int main()
{
	srand(time(NULL));
	const unsigned int SIZE = 10;
	int testClass[SIZE]{};
	double farTable[]{ 69,80,90,112,667 };
	std::vector<double> farTable2{ 69,80,90,112,667 };
	std::vector<double> secondTable[5]{};
	std::list<double> ls{0};

	std::cout << "For_each: " << std::endl;
	std::for_each(farTable, farTable + 5, translateToFarengeit);
	std::cout << std::endl;

	std::cout << "Lambda expression: " << std::endl;

	Foo(farTable2, [](double a)
		{
			translateToFarengeit(a);
		});
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		testClass[i] = rand() % 100 - 50;
	}

	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << testClass[i] << " ";
	}

	int count = std::count_if(testClass, testClass + SIZE,evenValues);

	std::cout << ": Array has " << count << " even values";
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The Third Point:" << std::endl;

	std::cout << std::endl;
	std::cout << "Print values with *: " << std::endl;
	for (auto i = farTable2.begin(); i != farTable2.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Print values without *: " << std::endl;
	for (auto elem : farTable2)
	{
		std::cout << elem << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Print values with []: " << std::endl;
	for (int i = 0; i < farTable2.size(); ++i)
	{
		std::cout << farTable2[i] << std::endl;
	}

	std::cout << "Print every second element using += to determine the iteration step: " 
		<< std::endl;
	/*for (int i = 0; i < farTable2.size(); ++i)
	{
		if (farTable2.size() % 2 == 0)
		{
			std::cout << farTable2[i];
		}
	}*/
	for (auto i = farTable2.begin(); i != farTable2.end() - 1; i+=2)
	{
		std::cout << *i << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "The List: " << std::endl;
	for (int i = 0; i < SIZE; ++i)
	{
		ls.push_back(i);
		std::cout << i << " ";
	}

	return 0;
}
