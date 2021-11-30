#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include <exception>
#include <functional>

class Fraction
{
public:
    Fraction(int a, int b);
    ~Fraction();

private:
    int a_value;
    int b_value;
};

double divide(int a, int b, bool& success)
{
    if (b == 0)
    {
        success = false;
        return 0.0;
    }

    success = true;
    return static_cast<double>(a) / b;
}

int checkOutOfValues(int a, int b)
{
    if (a < 0 && b < 0)
    {
        try
        {
            throw a;
            throw b;
        }
        catch (int a_v)
        {
            std::cerr << "We caught an int exception with value: " << a_v << '\n';
            std::cerr << "Incorrect values!!!" << std::endl;
        }
    }

}


Fraction::Fraction(int a, int b)
    :a_value(a), b_value(b)
{
    if (a_value <= 0 && b_value <= 0)
    {
        try
        {
            throw a_value;
            throw b_value;
        }
        catch (std::exception & ca)
        {
            std::cerr << "Incorrect values in Constructor!!!!" << std::endl;
        }
    }
    else
    {
        std::cout << "The Object is build!" << std::endl;
    }
}

Fraction::~Fraction()
{
    std::cout << "Destructor Of Fraction" << std::endl;
}
