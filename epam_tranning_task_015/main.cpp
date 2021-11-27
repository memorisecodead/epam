#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "miniQuest.h"
#include "SimpleExplicit.h"
#include "myVector.h"
#include "myString.h"
#include "TextView.h"

int main()
{
	Simple s{};
	SimpleExplicit se{};

	myString str("Stas");
	myString str2("Sasha");

	TextView<myString> tv(&str);
	TextView<myString> tvv(tv);

	myVector<myString> sv(2);

	sv.push_back(str);
	sv.push_back(str2);
	std::cout << str 
		<< str2 << std::endl;

	/*foo();*/

	bool ss = s;

	/*bool sse = se;*/ //conversion does not exist
	bool sse = static_cast<bool>(se);

	return 0;
}
