#pragma once
#include <iostream>

class customQueue
{
public:
	customQueue();
	void pushValue(int & index);
	void popValue();
	void printQueue();
	int frontValue();
	int backValue();
	bool isEmpty();
	unsigned int sizeOfQueue();
	unsigned int ReferenceSize(unsigned int & size);
	~customQueue();

private:
	int * q_arr;
	int q_fbeg;
	int q_rend;
	unsigned int q_size = 10;
};