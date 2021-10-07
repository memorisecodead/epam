#pragma once
#include <iostream>
#include <iomanip>

class Shop
{
public:
	Shop();
	~Shop();
	std::string & getNameShop();
	void setNameShop(std::string nameshop);
	std::string & getCharacter();
	void setCharacter(std::string character);
	unsigned int & getId();
	void setId(unsigned int id);

	void printInfo();
	virtual void printPhraze()
	{
		std::cout << "Say Meeeow!!" << std::endl;
	}

private:
	std::string m_nameshop;
	std::string m_character;
	unsigned int m_id;

};