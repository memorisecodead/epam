#include "Backpack.h"

Backpack::Backpack()
	:m_item(nullptr),m_nametag("Skyrim"),m_weightbp(300),m_backp(nullptr),m_pricebp(0),m_size(0)
{
	
}

void Backpack::addBackPack(Backpack & crOfbp,unsigned int & count)
{
	
	if (m_backp == nullptr)
	{
		m_backp = new Backpack[1];
		m_backp[0] = crOfbp;
		std::cout << "Nametag: " << m_backp[0].m_nametag
			<< " | " << "Weight: " << m_backp[0].m_weightbp << std::endl;
	}
	//}
	//else
	//{
	//	Backpack* temp_backp = new Backpack[count];

	//	for (int i = 0; i < count; ++i)
	//	{
	//		temp_backp[i] = m_backp[i];
	//	}

	//	delete[] m_backp;
	//	m_backp = nullptr;

	//	m_backp = new Backpack[count + 1];

	//	for (int i = 0; i < count; ++i)
	//	{
	//		m_backp[i] = temp_backp[i];
	//	}
	//	m_backp[count] = crOfbp;

	//	std::cout << count + 1 << " BackPack is added:\n" << m_backp[count].m_nametag
	//		<< " " << m_backp[count].m_weightbp << std::endl;

	//	++count;
	//	/*count = m_item->s_count_of_item;*/

	//	delete[] temp_backp;
	//	temp_backp = nullptr;
}

void Backpack::editOfBackPack(Item *& items, Backpack& crOfbp, unsigned int& count)
{
	printOfBackPack(items,crOfbp,count);
	std::cout << "Edit the nametag: " << std::endl;
	std::cin >> m_backp[count].m_nametag;
	printResult(count);
}

void Backpack::printOfBackPack(Item *& items,Backpack & crOfbp, unsigned int & count)
{
	system("pause");
	system("cls");
	std::cout << "Items in " << crOfbp.m_nametag << "# backpack:" << std::endl;
	std::cout << "__________________________________" << std::endl;
	for (int i = 0; i < count; i++)
	{
		printAllItems(items, count);
	}
	std::cout << "__________________________________" << std::endl;
	std::cout << crOfbp.m_weightbp << " weight of " << crOfbp.m_nametag << std::endl;
}

void Backpack::printAllItems(Item *& items,unsigned int & count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << std::endl;
		std::cout << "Item is added:\n" << items[i+1].s_item
			<< " | " << items[i+1].s_weight << " | " << items[i+1].s_price << std::endl;
	}
}

void Backpack::printResult(unsigned int& count)
{
	std::cout << "Edited note:\n " << m_backp[count].m_nametag
		<< " " << m_backp[count].m_weightbp << std::endl;

	std::cout << "\nEdit was complete.\n";
}


Item* Backpack::pushOfItems(Item * items_obj, unsigned int& count)
{
	std::cout << std::endl;
	std::cout << "Push items in your backpack:" << std::endl;
	items_obj = new Item[count]; 
	std::string s_fakeitem = "Item 1";
	double s_fakeprice = 1000;
	double s_fakeweight = 100;

	for (int i = 0; i < count; ++i)
	{
		std::cout << std::endl;
		std::cin.clear();
		std::cout << i + 1 << "# Enter a your item: " << std::endl;
		/*std::getline(std::cin, items_obj[i].s_item);*/
		std::cin >> items_obj[i].s_item;
		/*items_obj[i].s_item = s_fakeitem;*/
		std::cout << "Enter a price of your item: " << std::endl;
		std::cin >> items_obj[i].s_price;
		/*items_obj[i].s_price = s_fakeprice;*/
		std::cout << "Enter a weight of your item: " << std::endl;
		std::cin >> items_obj[i].s_weight;
		//items_obj[i].s_weight = s_fakeweight;
		std::cin.clear();
		/*s_fakeitem += std::to_string(i);
		s_fakeprice += 1000;
		s_fakeweight += 50; */
	}

 	system("pause");
	system("cls");

	for (int i = 0; i < count; ++i)
	{
		if ((items_obj[i].s_price + m_pricebp > m_pricebp) && (m_weightbp - items_obj[i].s_weight < m_weightbp))
		{	
			++m_size;
			m_backp->pushItemsInBackpack(items_obj[i], m_size);
			m_pricebp += items_obj[i].s_price;
			m_weightbp -= items_obj[i].s_weight;
		}
		else
		{
			system("pause");
			std::cout << std::endl << std::endl;
			std::cout << "No space in the backpack" << std::endl;
			std::cout << "Price of backpack: " << m_pricebp << std::endl;
			std::cout << "Weight of backpack: " << m_weightbp << std::endl;
			std::cout << std::endl << std::endl;
		}
	}

	return items_obj;
}

void Backpack::printItems(unsigned int & count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << m_item[i].s_price << " | " << m_item[i].s_weight << " | "
			<< m_item[i].s_item << std::endl;
	}
}

void Backpack::pushItemsInBackpack(Item & item, unsigned int & index)
{
	if (m_item == nullptr)
	{
		m_item = new Item[++m_size];
		m_item[0] = item;

		std::cout <<"Item is added:\n" << m_item[0].s_item
			<< " | " << m_item[0].s_weight << " | " << m_item[0].s_price << std::endl;
	}
	else
	{
		Item * temp_item = new Item[m_size];

		for (int i = 0; i < m_size; ++i)
		{
			temp_item[i] = m_item[i];
	}

		delete[] m_item;
		m_item = nullptr;

		m_item = new Item[m_size+1]; 

		for (int i = 0; i < m_size; ++i)
		{
			m_item[i] = temp_item[i];
		}

		++m_size;
		m_item[m_size - 1] = item;

		std::cout << "Item is added:\n" << m_item[m_size -1].s_item
			<< " | " << m_item[m_size -1].s_weight << " | " << m_item[m_size -1].s_price << std::endl;

		++index;

		delete[] temp_item;
		temp_item = nullptr;
	}
}

Backpack::~Backpack()
{
	m_backp = nullptr;
	m_item = nullptr;
	m_nametag = " ";
	m_weightbp = 0;
}

void Backpack::countOfItems(unsigned int& index)
{
	std::cout << "How many items do you want to add?" << std::endl;
	std::cin >> index;
}