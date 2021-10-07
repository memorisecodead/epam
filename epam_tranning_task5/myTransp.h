#pragma once
#include <iostream>

class Transoprt
{
public:
	Transoprt();
	~Transoprt();
	double & getBenzo();
	void setBenzo(double bezno);
	double& getPriceOfWay();
	void setPriceOfWay(double price);
	unsigned int& getPlace();
	void setPlace(unsigned int place);

	virtual double averageBezno();
	virtual double generalPriceOfWay();
private:
	double m_benzo;
	double m_price_of_way;
	unsigned int m_place;
};