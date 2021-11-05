#include <iostream>
#include "Idustries.h"

int main()
{
    bool success;
    int a_value = 0;
    int b_value = 0;
    Fraction fr(5, 6);

    std::cout << "Enter a values for foo:" << std::endl;
    std::cin >> a_value >> b_value;

    checkOutOfValues(a_value, b_value);

    double result = divide(a_value, b_value, success);

    if (!success)
    {
        std::cerr << "An error occurred" << std::endl;
    }
    else
    {
        std::cout << "The answer is " << result << '\n';
    }


    return 0;
}