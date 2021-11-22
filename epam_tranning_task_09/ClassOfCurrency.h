#pragma once
#include <iostream>
#include <algorithm>
#include <string>

class Currency
{
public:
	Currency() = default;
	void ShowInfoOfRatio(double(*foo)());
	void ConvertCurrency(double & course);
	virtual ~Currency();

	unsigned int m_baseCurr; //Базовая валюта 
	double m_ratio; //Ковертация 
	double m_rate; //Кратность 
	std::string m_name_of_currency;
	double m_dpricer;
	double m_rprices;
	double m_bpricen;
	double m_epriceo;

	virtual void money_transfer() = 0;
};
//[Курс]=[конвертация]*[Кратность]/[Базовая валюта]

class Dollar : public Currency 
{
public:
	Dollar() = default;
	virtual ~Dollar();

	void money_transfer() override
	{
		m_dpricer = m_ratio * m_rate / m_baseCurr;
		std::cout << m_dpricer << std::endl;
	}
};

class Rubels : public Currency
{
public:
	Rubels() = default;
	virtual ~Rubels();

	void money_transfer() override
	{
		m_rprices = m_ratio * m_rate / m_baseCurr;
		std::cout << m_rprices << std::endl;
	}
};

class Byn : public Currency
{
public:

	Byn() = default;
	virtual ~Byn();

	void money_transfer() override
	{
		m_bpricen = m_ratio * m_rate / m_baseCurr;
		std::cout << m_bpricen << std::endl;
	}
};

class Euro : public Currency
{
public:
	Euro() = default;
	virtual ~Euro();

	void money_transfer() override
	{
		m_epriceo = m_ratio * m_rate / m_baseCurr;
		std::cout << m_epriceo << std::endl;
	}
};