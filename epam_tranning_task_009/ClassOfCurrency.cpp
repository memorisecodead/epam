#include "ClassOfCurrency.h"

enum ChooseMainCurrency
{
	DollarMain = 1,
	RubelsMain,
	BynMain,
	EuroMain
};

enum ChooseConvertCurrency
{
	DollarConvert = 1,
	RubelsConvert,
	BynConvert,
	EuroConvert
};

void Currency::ShowInfoOfRatio(double(*foo)())
{
	std::cout << "Currency " << this->m_name_of_currency << " is added:\n "
		<< "Rate: " << this->m_rate << " Ratio: " << this->m_ratio
		<< "Count of base currency: " << this->m_baseCurr << std::endl;
	std::cout << foo() << std::endl;
}

Currency::~Currency()
{
	m_baseCurr = 0;
	m_name_of_currency = " ";
	m_ratio = 0.0;
	m_rate = 0.0;
}

Dollar::~Dollar()
{
	m_dpricer = 0.0;
}

void Currency::ConvertCurrency(double & course)
{	
	unsigned int chooseCourse = 0;
	unsigned int chooseCurr = 0;
	double rate = 0;
	double curr = 0;

	std::cout << "Choose main convert currency: " << std::endl;
	std::cout << "1. Dollar\n"
		"2. Rubels\n"
		"3. Byn\n"
		"4. Euro\n";
	std::cout << "Choose: ";
	std::cin >> chooseCurr;
	std::cout << std::endl;

	switch (chooseCurr)
	{
		std::cout << std::endl;
		case(unsigned int)(ChooseMainCurrency::DollarMain) :
		{
			Currency* cur = new Dollar;
			std::cout << "Set up a count of curr (Dollar):" << std::endl;
			std::cin >> curr;
			cur->m_baseCurr = curr;
			delete cur;
		}
		break;
		case(unsigned int)(ChooseMainCurrency::RubelsMain) :
		{
			std::cout << std::endl;
			Currency* cur = new Rubels;
			std::cout << "Set up a count of curr (Rubels):" << std::endl;
			std::cin >> curr;
			cur->m_baseCurr = curr;
			delete cur;
		}
		break;
		case(unsigned int)(ChooseMainCurrency::BynMain) :
		{
			std::cout << std::endl;
			Currency* cur = new Byn;
			std::cout << "Set up a count of curr (Byn):" << std::endl;
			std::cin >> curr;
			cur->m_baseCurr = curr;
			delete cur;
		}
		break;
		case(unsigned int)(ChooseMainCurrency::EuroMain) :
		{
			std::cout << std::endl;
			Currency* cur = new Euro;
			std::cout << "Set up a count of curr (Euro):" << std::endl;
			std::cin >> curr;
			cur->m_baseCurr = curr;
			delete cur;
		}
		break;

	}

	system("pause");
	system("cls");

	std::cout << "Choose course of currency: " << std::endl;
	std::cout << "1. Dollar\n"
		"2. Rubels\n"
		"3. Byn\n"
		"4. Euro\n";
	std::cout << "Choose: ";
	std::cin >> chooseCourse;

	switch (chooseCourse)
	{
		case(unsigned int)(ChooseConvertCurrency::DollarConvert) :
		{
			system("cls");
			std::cout << std::endl;
			std::cout << "Currency " << curr << " USD = " << std::endl;
			std::cout << curr * 2.46 << " BYN" << std::endl;
			std::cout << curr * 70.494 << " RUB" << std::endl;
			std::cout << curr * 1.16 << " EUR" << std::endl;
		}
		break;
		case(unsigned int)(ChooseConvertCurrency::RubelsConvert) :
		{
			system("cls");
			std::cout << std::endl;
			std::cout << "Currency " << curr << " RUB = " << std::endl;
			std::cout << curr * 0.034 << " BYN" << std::endl;
			std::cout << curr * 0.014 << " USD" << std::endl;
			std::cout << curr * 0.012 << " EUR" << std::endl;
		}
		break;
		case(unsigned int)(ChooseConvertCurrency::BynConvert) :
		{
			system("cls");
			std::cout << std::endl;
			std::cout << "Currency " << curr << " BYN = " << std::endl;
			std::cout << curr * 29.03 << " RUB" << std::endl;
			std::cout << curr * 0.41 << " USD" << std::endl;
			std::cout << curr * 0.35 << " EUR" << std::endl;
		}
		break;
		case(unsigned int)(ChooseConvertCurrency::EuroConvert) :
		{
			system("cls");
			std::cout << std::endl;
			std::cout << "Currency " << curr << " EUR = " << std::endl;
			std::cout << curr * 2.843 << " BYN" << std::endl;
			std::cout << curr * 82.51 << " RUB" << std::endl;
			std::cout << curr * 1.16 << " USD" << std::endl;
		}
		break;

	}
}

Euro::~Euro()
{
	m_epriceo = 0.0;
}

Byn::~Byn()
{
	m_bpricen = 0.0;
}

Rubels::~Rubels()
{
	m_rprices = 0.0;
}
