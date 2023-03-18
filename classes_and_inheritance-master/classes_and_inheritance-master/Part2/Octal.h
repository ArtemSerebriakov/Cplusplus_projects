#pragma once
#include "Array.h"
#include <sstream>
class Octal :public Array
{
public:
	Octal() :Array()
	{
	}
	Octal(int l) :Array(l)
	{
	}
	Octal(int l, unsigned char* f) :Array(l, f)
	{
	}
	friend std::istream& operator>> (std::istream& in, Octal& p_a);
	Octal& operator=(const Octal& d);
	bool operator>(const Octal& d);
	bool operator==(const Octal& d);
	bool operator!=(const Octal &d);
	bool operator>=(const Octal& d);
	bool operator<(const Octal& d);
	bool operator<=(const Octal& d);
	void add(const Array* p_a, Array* res)override;
	Octal operator-(const Octal& p_a);
	Octal operator*(const Octal& p_a);
	Octal operator/(const Octal& p_a);

};