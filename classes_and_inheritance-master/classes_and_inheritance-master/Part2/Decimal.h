#pragma once
#include "Array.h"
class Decimal :public Array
{
public:
	Decimal() :Array()
	{
	}
	Decimal(int l) :Array(l)
	{
	}
	Decimal(int l,unsigned char* f):Array(l,f)
	{
	}
	friend std::istream& operator>> (std::istream& in, Decimal& p_a);
	Decimal& operator=(const Decimal& d);
	bool operator>(const Decimal& d);
	bool operator==(const Decimal& d);
	bool operator!=(const Decimal& d);
	bool operator>=(const Decimal& d);
	bool operator<(const Decimal& d);
	bool operator<=(const Decimal& d);
	void add(const Array* p_a, Array* res)override;
	Decimal operator-(const Decimal& p_a);
	Decimal operator*(const Decimal& p_a);
	Decimal operator/(const Decimal& p_a);

};