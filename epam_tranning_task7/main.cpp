#include <iostream>
#include "Backpack.h"
#include "Item.h"

int main()
{
	unsigned int index = 0;
	Backpack bp;
	Item* it = nullptr;
	countOfItems(index);
	bp.addBackPack(bp,index);
	bp.pushOfItems(it, index);
	
	delete it;

	return 0;
}