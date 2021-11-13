#pragma once
#include <iostream>
#include <iomanip>

class Carrier
{
public:
	Carrier();
	~Carrier();
	unsigned int& getWay();
	void setWay(unsigned int way);
	unsigned int& getHuman();
	void setHuman(unsigned int human);
	double& GetPriceOfWay();
	void setPrice(double price);
	unsigned int& getPlace();
	void setPlace(unsigned int place);

	virtual unsigned int  averageCountOfHuman();
	virtual double generalPriceOfCarrier();
private:
	unsigned int m_way;
	unsigned int m_count_of_human;
	double m_count_of_price;
	unsigned int m_count_of_place;

};