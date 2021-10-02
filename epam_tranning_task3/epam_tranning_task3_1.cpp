#include <iostream>
#include <ctime>
#include "myVector.h"

int main()
{	
	srand(time(NULL));
	int count = 10;
	myVector<int> v(count);
	
	/*v.insert(4,55);*/
	std::cout << "Size of vector:" << std::setw(4) << v.size() << std::endl;
	v.showVector();
	v.summOfMassPastMinEl();

	return 0;
}