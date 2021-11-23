#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "miniQuest.h"
#include "SimpleExplicit.h"
#include "myVector.h"
#include "myString.h"

int main()
{
	Simple s{};
	SimpleExplicit se{};

	myString str("Stas");
	myVector<myString> sv(2);

	sv.push_back(str);
	std::cout << str 
		<< std::endl;

	/*foo();*/

	bool ss = s;

	/*bool sse = se;*/ //conversion does not exist
	bool sse = static_cast<bool>(se);

	return 0;
}
