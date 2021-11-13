#include "myCarrier.h"

Carrier::Carrier()
	: m_count_of_human(0),m_way(0),m_count_of_price(0.0),m_count_of_place(0)
{

}

Carrier::~Carrier()
{
	m_count_of_place = 0;
	m_count_of_human = 0;
	m_count_of_price = 0.0;
	m_way = 0;
}

void Carrier::setWay(unsigned int way)
{
	m_way = way;
}

unsigned int& Carrier::getHuman()
{
	return m_count_of_human;
}

void Carrier::setHuman(unsigned int human)
{
	m_count_of_human = human;
}

double& Carrier::GetPriceOfWay()
{
	return m_count_of_price;
}

void Carrier::setPrice(double price)
{
	m_count_of_price = price;
}

unsigned int& Carrier::getPlace()
{
	return m_count_of_place;
}

void Carrier::setPlace(unsigned int place)
{
	m_count_of_place = place;
}

unsigned int Carrier::averageCountOfHuman()
{
	system("pause");
	system("cls");
	double averageCount = 0;
	std::cout << "Average count of Human in Carrier:" << std::endl;
	averageCount = static_cast<double>(m_count_of_human) / m_count_of_place;
	std::cout << averageCount << " average count of human in Carrier" << std::endl;
	return averageCount;
	system("pause");
}

double Carrier::generalPriceOfCarrier()
{
	system("pause");
	system("cls");
	double generalPrice = 0;
	std::cout << "General Price of Carrier:" << std::endl;
	generalPrice = m_count_of_price / m_count_of_place;
	std::cout << generalPrice << " $ general price in Carrier" << std::endl;
	return generalPrice;
	system("pause");
}

unsigned int& Carrier::getWay()
{
	return m_way;
}
