#pragma once
#include "Integer.h"
class Decimal:public Integer
{
public:
	Decimal(int num, int* a):Integer(num,a)
	{
	}
	Decimal():Integer()
	{
	}
	~Decimal()
	{
	}
	void GetNumber(const Integer& a);
	void add(const Integer* first, Integer* res)override;
	void dif(const Integer* first, Integer* res)override;
	void mult(const Integer* first, Integer* res)override;
	void div(const Integer* first, Integer* res)override;
};