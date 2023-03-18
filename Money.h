#pragma once
#include <iostream>
class Money
{
private:
	long rub;
	unsigned char kop;
	static int c;
public:
	Money();
	Money(long r, unsigned char k) :rub(r), kop(k)
	{
		c++;
	}
	~Money() {}
	friend std::ostream& operator<< (std::ostream& out, const Money& m);
	friend Money operator+(const Money& m1, const Money& m2);
	friend Money operator-(const Money& m1, const Money& m2);
	friend Money operator/(const Money& m1, const Money& m2);
	friend Money operator/(const Money& m1, double b);
	friend Money operator*(const Money& m1, const Money& m2);
	friend bool operator<=(const Money& m1, const Money& m2);
	friend bool operator>=(const Money& m1, const Money& m2);
	friend bool operator<(const Money& m1, const Money& m2);
	friend bool operator>(const Money& m1, const Money& m2);
	friend bool operator==(const Money& m1, const Money& m2);
	friend bool operator!=(const Money& m1, const Money& m2);
	friend Money operator*(const Money& m1, double b);
	static void ShowCount();
};
