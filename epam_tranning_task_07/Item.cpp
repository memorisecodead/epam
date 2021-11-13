#include "Item.h"

Item::~Item()
{
}

Item::Item(unsigned int weight, double price, std::string item)
	:s_weight(weight), s_price(price), s_item(item)/*, s_count_of_item(count_of_item)*/
{

}

const Item Item::operator+(double dvalue)
{
	this->s_price += dvalue;
	return *this;
}

bool Item::operator!=(Item r_it)
{
	return this->s_weight != r_it.s_weight && this->s_price != r_it.s_price;
}

bool operator<(Item& r_it, Item& l_it)
{
	return l_it.s_weight < r_it.s_weight && l_it.s_price < r_it.s_price;
}
