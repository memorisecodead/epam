#pragma once
#include <iostream>
#include <algorithm>

class Simple
{
public:
	Simple(){ }
	operator bool() const { return true; }
};

class SimpleExplicit
{
public:
	explicit SimpleExplicit() {}
	explicit operator bool() const { return true; }
};