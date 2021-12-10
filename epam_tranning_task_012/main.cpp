#include <iostream>
#include "customQueue.h"
#include "ErrorHeader.h"

int main()
{
	customQueue qq;
	unsigned int count = 0;
	int i = 0;

	std::cout << "Enter a count of values: ";
	std::cin >> count;

	qq.ReferenceSize(count);

	for (i = 1; i <= count; ++i)
	{
		qq.pushValue(i);
	}

	std::cout << "Main queue:" << std::endl;
	qq.printQueue();
	std::cout << std::endl;
	qq.sizeOfQueue();
	std::cout << std::endl;
	std::cout << "Enter a new value: ";
	std::cin >> i;
	qq.pushValue(i);
	std::cout << std::endl;
	std::cout << "Queue:" << std::endl;
	qq.printQueue();
	std::cout << std::endl;
	std::cout << std::endl;
	qq.sizeOfQueue();
	std::cout << std::endl;
	std::cout << "The first element of queue:" << std::endl;
	std::cout << qq.frontValue();
	std::cout << std::endl;
	std::cout << "The last element of queue:" << std::endl;
	std::cout << qq.backValue();

	std::cout << std::endl;
	qq.isEmpty();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();
	qq.popValue();

	return 0;
}