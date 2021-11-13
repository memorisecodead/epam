#pragma once
#include <iostream>
#include <algorithm>
#include <string>

class Currency
{
public:
	Currency() = default;
	/*Currency(std::string name, unsigned int basecurr, double ratio, double rate);*/
	//double ratioOfCurrency(double& coure);
	void ShowInfoOfRatio(double(*foo)());
	void ConvertCurrency(double & course);
	~Currency();

	unsigned int m_baseCurr; //������� ������ 
	double m_ratio; //���������� 
	double m_rate; //��������� 
	std::string m_name_of_currency;
	double m_dpricer;
	double m_rprices;
	double m_bpricen;
	double m_epriceo;

	virtual void money_transfer() = 0;
};
//[����]=[�����������]*[���������]/[������� ������]
//[����]=19,40*100/1000=1,94

class Dollar : public Currency 
{
public:
	Dollar() = default;
	~Dollar();

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
	~Rubels();

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
	~Byn();

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
	~Euro();

	void money_transfer() override
	{
		m_epriceo = m_ratio * m_rate / m_baseCurr;
		std::cout << m_epriceo << std::endl;
	}
};