#pragma once
#include <iostream>

class Item
{
public:
	Item() = default;
	~Item();
	Item(unsigned int weight, double price, std::string item);
	const Item operator+ (double dvalue);
	bool operator!= (Item r_it);
	friend bool operator<(Item & r_it, Item & l_it);

	unsigned int s_weight;
	double s_price;
	std::string s_item;
	/*unsigned int s_count_of_item;*/
};