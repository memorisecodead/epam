#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
#include "Item.h"

class Backpack
{
public:
	Backpack();
	void addBackPack(Backpack & crOfbp, unsigned int & count);
	void editOfBackPack(Item *& items, Backpack & crOfbp, unsigned int& count);
	void printOfBackPack(Item *& items, Backpack & crOfbp, unsigned int& count);
	void printAllItems(Item *& items, unsigned int & count);
	void printResult(unsigned int& count);
	Item * pushOfItems(Item* items_obj, unsigned int& count);
	void printItems(unsigned int & count);
	void pushItemsInBackpack(Item & item, unsigned int& index);
	~Backpack();

private:
	double m_pricebp;
	Backpack * m_backp;
	Item * m_item;
	unsigned int m_weightbp;
	std::string m_nametag;
};

void countOfItems(unsigned int& index);