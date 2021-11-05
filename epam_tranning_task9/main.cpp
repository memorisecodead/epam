#include <iostream>
#include "ClassOfCurrency.h"

int main()
{
	double d_ratio = 19.40;
	Currency* cur = nullptr;
	cur->ConvertCurrency(d_ratio);
	delete cur;
	return 0;
}