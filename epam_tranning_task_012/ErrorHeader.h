#pragma once
#include <iostream>

class bad_area
{
public:
	bad_area(unsigned int size = 0)
		: b_size(size) {}
	void messg();
private:
	unsigned int b_size;
};