#pragma once
#include "Integer.h"
class Binary :public Integer
{
public:
	Binary(int num, int* a) :Integer(num, a)
	{
	}
	Binary() :Integer()
	{
	}
	~Binary()
	{
	}
	void GetNumber(const Integer& a);
	void add(const Integer* first, Integer* res)override;
	void dif(const Integer* first, Integer* res)override;
	void mult(const Integer* first, Integer* res)override;
	void div(const Integer* first, Integer* res)override;
};