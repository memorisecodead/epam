#include <iostream>
#include "myVector.h"

int main()
{
	//сравнить быстродействие 
	int count = 10;

	myVector<int> v(count);

	v.size();
	v.shakerSort(count);
	v.sortOfShell(count);

	v.find(v,28);

	return 0;
}