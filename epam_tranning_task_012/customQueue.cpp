#include "customQueue.h"
#include "ErrorHeader.h"

customQueue::customQueue()
{
	q_arr = new int[q_size];
	q_fbeg = q_rend = 0;
}

void customQueue::pushValue(int& index)
{
	if (q_rend + 1 == q_fbeg || (q_rend + 1 == q_size && !q_fbeg))
	{
		std::cout << "Queue is full!" << std::endl;
	}

	++q_rend;

	if (q_rend == q_size)
	{
		q_rend = 0;
	}
	else
	{
		q_arr[q_rend] = index;
	}
}

void customQueue::popValue()
{
	unsigned int el_q = 0;
	el_q = q_arr[q_rend];

	if (q_rend > 0)
	{
		q_arr[--q_fbeg];
		std::cout << std::endl
			<< "Value is delete: " << el_q
			<< std::endl;

		el_q = q_arr[--q_rend];
	}

	try
	{
		if (q_rend >= q_size || q_rend == 0)
		{
			throw std::invalid_argument("bad area!");
		}

	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << " Going outside the area!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void customQueue::printQueue()
{
	for (int i = q_fbeg + 1; i < q_rend + 1; ++i)
	{
		std::cout << " " << q_arr[i];
	}
}

int customQueue::frontValue()
{
	return q_arr[q_fbeg + 1];
}

int customQueue::backValue()
{
	return q_arr[q_rend];
}

bool customQueue::isEmpty()
{
	if (q_rend == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int customQueue::sizeOfQueue()
{
	unsigned int temp_s = 0;
	for (int i = q_fbeg; i < q_rend; ++i)
	{
		++temp_s;
	}
	std::cout << "Size of queue: " << temp_s << std::endl;
	return temp_s;
}

unsigned int customQueue::ReferenceSize(unsigned int & size)
{
	try
	{
		if (size >= q_size)
		{
			throw std::invalid_argument("bad area!");
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << " Going outside the area!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Size of queue: " << q_size << std::endl << std::endl;
	return q_size;
}

customQueue::~customQueue()
{
	q_arr = nullptr;
	q_fbeg = 0;
	q_rend = 0;
	q_size = 0;
}