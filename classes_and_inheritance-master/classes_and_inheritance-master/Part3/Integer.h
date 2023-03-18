#pragma once
#include <iostream>
class Integer
{
protected:
	int* array;
	int n;
public:
	Integer(int num, int* a);
	Integer();
	virtual ~Integer();
	virtual void GetNumber(const Integer& a) = 0;
	virtual void add(const Integer* first, Integer* res) = 0;
	virtual void dif(const Integer* first, Integer* res) = 0;
	virtual void mult(const Integer* first, Integer* res) = 0;
	virtual void div(const Integer* first, Integer* res) = 0;
};