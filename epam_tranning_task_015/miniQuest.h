#pragma once
#include <iostream>

void foo()
{
	int x = 0;
	int a = 6;

	a = a - 3;

	std::cout << a << std::endl; 

	int b = a;
	std::cout << b << std::endl; 

	std::cout << a + b << std::endl; 

	std::cout << a << std::endl;

	int c = 0;
	std::cout << c << std::endl;

	a += b;
	//std::cout << à << std::endl; 

	int& ref1 = x; 		// lvalue
	/*int& ref2 = 7; */		// rvalue

	const int& ref3 = x;	 // lvalue
	const int& ref4 = 7;	 // lvalue

/*	int&& ref5 = x; 	*/	// rvalue
	int&& ref6 = 7; 		// lvalue

	/*const int&& ref7 = x; */	// rvalue
	const int&& ref8 = 7; 	// lvalue

	int arr[] = { 1, 2 };
	int* p = &arr[0]; 		//lvalue
	*(p + 1) = 10;		//lvalue

	int var = 10;
	/*int* bad_addr = &(var + 1);	*///rvalue
	int* addr = &var; 			//lvalue
	/*&var = 40;		*/		//rvalue
}