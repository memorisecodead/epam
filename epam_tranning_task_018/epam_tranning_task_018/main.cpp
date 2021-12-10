#include <iostream>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "SmartPointer.h"


int main()
{
	pointer::SmartPointer<int> sm(new int(6));
	int arr = 6;
	arr = sm;

	

	return 0;
}