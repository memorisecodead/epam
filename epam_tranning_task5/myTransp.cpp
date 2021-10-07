#include "myTransp.h"

Transoprt::Transoprt()
	: m_benzo(0), m_price_of_way(0.0), m_place(0)
{
}

Transoprt::~Transoprt()
{
	m_benzo = 0.0;
	m_price_of_way = 0.0;
	m_place = 0;
}

double& Transoprt::getBenzo()
{
	return m_benzo;
}

void Transoprt::setBenzo(double bezno)
{
	m_benzo = bezno;
}

double& Transoprt::getPriceOfWay()
{
	return m_price_of_way;
}

void Transoprt::setPriceOfWay(double price)
{
	m_price_of_way = price;
}

unsigned int& Transoprt::getPlace()
{
	return m_place;
}

void Transoprt::setPlace(unsigned int place)
{
	m_place = place;
}

double Transoprt::averageBezno()
{
	system("pause");
	system("cls");
	double averageBenzo = 0;
	double way = 1000.00;
	std::cout << "Average Bezno of 1 kilometer:" << std::endl;
	averageBenzo = (m_benzo * m_price_of_way) / way;
	std::cout << averageBenzo << " (L) average benzo" << std::endl;
	return averageBenzo;
	system("pause");
}

double Transoprt::generalPriceOfWay()
{
	system("pause");
	system("cls");
	double generalPrice = 0;
	std::cout << "General price of Way:" << std::endl;
	generalPrice = (m_place + m_benzo) / m_price_of_way;
	std::cout << m_price_of_way << " $ general price of way" << std::endl;
	return generalPrice;
	system("pause");
}
