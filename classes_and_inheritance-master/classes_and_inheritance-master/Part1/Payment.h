#pragma once
#include <iostream>
#include "Money.h"
class Payment
{
private:
	std::string name;
	double sal;
	int year;
	double pro;
	double tax;
	int woday;
	int allday;
	Money chsum;
	Money hosum;
	static int d;
public:
	Payment(std::string F, double S, int A, int Am, int D, double P, double I);
	~Payment() {}
	friend std::ostream& operator<< (std::ostream& out, const Payment& m);
	Money countchsum();
	Money counthosum();
	Money countsalary();
	int yearcount(int c);
	static void ShowCount();
};
