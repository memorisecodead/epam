#include <iostream>
#include "miniQuest.h"
#include "SimpleExplicit.h"

int main()
{
	Simple s{};
	SimpleExplicit se{};

	bool ss = s;

	/*bool sse = se;*/ //conversion does not exist
	bool sse = static_cast<bool>(se);



	return 0;
}
