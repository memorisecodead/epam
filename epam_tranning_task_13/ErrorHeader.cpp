#include "ErrorHeader.h"

void bad_area::messg()
{
	std::cout << "size of queue: " << b_size
		<< " invalid arguments!" << std::endl
		<< " Going outside the area!" << std::endl;
}