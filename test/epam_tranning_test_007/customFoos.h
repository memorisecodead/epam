#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

void fillArray(std::vector<int>& v, const unsigned int& count)
{
	for (auto i = 0; i < count; ++i)
	{
		v[i] = rand() % 10;
	}
	std::cout << "Fill is complete." 
		<< std::endl;
}

void showArray(std::vector<int> & v)
{
	for (auto v_i : v)
	{
		std::cout << " " << v_i;
	}
	std::cout << "Print is complete."
		<< std::endl;
}

template<class InIter, class Value>
InIter myFind(InIter first, InIter last, const Value & val)
{
	while (first != last) 
	{
		if (*first == val)
		{	
			return first;
		}
		
		++first;
	}
	std::cout << "myFind is complete."
		<< std::endl;
	return last;
}

template <class InIter,class Pred>
bool myFind_all(InIter first, InIter last, Pred pred)
{
	while (first != last)
	{
		if (!pred(*first))
		{
			return false;
		}
		++first;
	}
	
	return true;
}

template <class InIter,class Pred>
InIter myFind_of(InIter first, InIter last, Pred pred)
{
	while (first != last) 
	{
		if (!pred(*first))
		{
			return first;
		}
		++first;
	}
	return last;
}

template <class InIter, class Pred>
InIter myFind_if(InIter first,InIter last, Pred pred)
{
	while (first != last) 
	{
		if (pred(*first))
		{
			return first;
		}

		++first;
	}
	return last;
}

void foo()
{
	std::vector<int> v_1(10);
	fillArray(v_1, 10);

	std::for_each(v_1.begin(), v_1.end(), [](const int x)
		{
			std::cout << " " << x;
			return x;
		});
	std::cout << "\nFor_each is complete."
		<< std::endl;

	auto result = std::find(v_1.begin(), v_1.end(),4);
	if (result == v_1.end())
	{
		std::cout << "Value isn't find! " 
			<< std::endl;
	}
	else
	{
		std::cout << "Value is find!" 
			<< std::endl;
	}

	auto res_1 = myFind(v_1.begin(), v_1.end(), 4);
	if (res_1 == v_1.end())
	{
		std::cout << "Value isn't find! " 
			<< std::endl;
	}
	else
	{
		std::cout << "Value is find!" 
			<< std::endl;
	}

	auto evens = [](int x)
	{
		return x % 2 == 0;
	};

	std::find_if(v_1.begin(), v_1.end(), evens);
	std::cout << "Find_if is complete."
		<< std::endl;

	auto div_13 = [](int x)
	{
		return x % 13 == 0;
	};

	std::find_if_not(v_1.begin(), v_1.end(), div_13);
	std::cout << "Find_if_not is complete."
		<< std::endl;

	std::string s{ "Hello!" };
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) -> unsigned char
		{
			std::cout << std::toupper(c)
				<< " ";
			return std::toupper(c);
		});
	std::cout << std::endl
		<< "Transform is complete."
		<< std::endl;

	std::vector<unsigned int> v_ui;
	std::transform(s.begin(), s.end(), std::back_inserter(v_ui),
		[](unsigned char c) -> std::size_t
		{
			std::cout <<
				c << " ";
			return c;
		});
	std::cout << std::endl
		<< "Transform is complete."
		<< std::endl;

	myFind_all(v_1.begin(), v_1.end(), evens);
	std::cout << "myFind_all is complete."
		<< std::endl;

	auto res_2 = myFind_if(v_1.begin(), v_1.end(), div_13);

	if (res_2 == v_1.end())
	{
		std::cout << "Value isn't find! "
			<< std::endl;
	}
	else
	{
		std::cout << "Value is find!" 
			<< std::endl;
	}
	std::cout << "myFind_if is complete."
		<< std::endl;

	auto res_3 = myFind_of(v_1.begin(), v_1.end(), evens);

	if (res_3 == v_1.end())
	{
		std::cout << "Value isn't find! " 
			<< std::endl;
	}
	else
	{
		std::cout << "Value is find!" 
			<< std::endl;
	}
	std::cout << "myFind_of is complete."
		<< std::endl;
}