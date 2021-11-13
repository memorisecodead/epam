#include <iostream>
#include "myShop.h"

Shop::Shop()
	: m_nameshop(" "), m_character(" "), m_id(0)
{
}

Shop::~Shop()
{
	m_nameshop = "Deleted name";
	m_character = "Deleted info";
	m_id = 0;
}

std::string& Shop::getNameShop()
{
	return m_nameshop;
}

void Shop::setNameShop(std::string nameshop)
{
	m_nameshop = nameshop;
}

std::string& Shop::getCharacter()
{
	return m_character;
}

void Shop::setCharacter(std::string character)
{
	m_character = character;
}

unsigned int& Shop::getId()
{
	return m_id;
}

void Shop::setId(unsigned int id)
{
	m_id = id;
}

void Shop::printInfo()
{
	std::cout << "ShopName: " << std::setw(4) << m_nameshop << std::endl;
	std::cout << "Characteristics of shop: " << std::setw(4) << m_character << std::endl;
	std::cout << "Id of shop: " << std::setw(4) << m_id << std::endl;
}
