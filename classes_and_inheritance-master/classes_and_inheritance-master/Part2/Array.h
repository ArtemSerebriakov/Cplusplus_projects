#pragma once
#include <iostream>
#include "Exception.h"
class Array
{
protected:
	static const int n = 100;
	unsigned char* a;
	int size;
public:
	Array();
	Array(int l);
	Array(int l, unsigned char* f);
	virtual void add(const Array* p_a, Array* res);
	virtual ~Array() {}
	unsigned char operator[] (const int index);
	unsigned char operator[] (const int index)const;
	friend std::ostream& operator<< (std::ostream& out, const Array& p_a);
};