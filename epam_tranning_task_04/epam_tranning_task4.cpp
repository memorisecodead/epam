#include <iostream>
#include <ctime>
#include "myVector.h"

int main()
{
	int count = 10;
	DynamicVector<int> dv(count,count);
	std::cout << "Size of Dynamic vector:" << std::setw(4) << dv.size() << std::endl;
	determOfNegative(dv);

	dv.clear();

	return 0;
}