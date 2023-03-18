#include "Array.h"
Array::Array() :a(nullptr), size(0)
{
	a = new unsigned char[n];
}
Array::Array(int l) :size(l), a(nullptr)
{
	a = new unsigned char[n];
	if ((l >= 0) && (l <= n))
	{
		for (int i = 0; i < l; i++)
		{
			a[i] = 0;
		}
	}
	else
	{
		throw OutOfRangeException("Invalid length!");
	}
}
Array::Array(int l, unsigned char* f)
{
	a = new unsigned char[100];
	if ((l >= 0) && (l <= 100))
	{
		size = l;
		for (int i = 0; i < l; i++)
		{
			a[i] = f[i] + '0';
		}
	}
	else
	{
		throw OutOfRangeException("Invalid length!");
	}
}
void Array::add(const Array* p_a, Array* res)
{
	if (p_a->size != size)
		throw IncompetibleDimException("Can't add up arrays because they have different lengths!");
	res->size = size;
	for (int i = 0; i < p_a->size; i++)
	{
		int e= p_a->a[i]-'0' + a[i]-'0';
		res->a[i] = e + '0';
	}
}
unsigned char Array::operator[] (const int index)
{
	if (index < 0 || index >= size)
		throw OutOfRangeException("Invalid index!");
	return a[index];
}
unsigned char Array::operator[] (const int index)const
{
	if (index < 0 || index >= size)
		throw OutOfRangeException("Invalid index!");
	return a[index];
}
std::ostream& operator<< (std::ostream& out, const Array& p_a)
{
	for (int i = 0; i < p_a.size; i++)
	{
		out << (p_a.a[i]) << " ";
	}
	return out;
}
Array::~Array() { delete[] a; }