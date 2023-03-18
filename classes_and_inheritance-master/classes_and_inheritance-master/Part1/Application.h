#pragma once
#include "Money.h"
#include "Payment.h"
class Application
{
private:
	Money m1{ 39,76 };
	Money m2{ 39, 56 };
	double b = 0.75;
	Payment pay{ "John Johnson", 119000, 30, 20, 2010, 10, 10 };
public:
	void Run();
};