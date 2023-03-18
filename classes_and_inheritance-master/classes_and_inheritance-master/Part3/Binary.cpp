#include <iostream>
#include "Integer.h"
#include "Binary.h"
#include "Exception.h"
void Binary::GetNumber(const Integer& a)
{
	const Binary& l = dynamic_cast<const Binary&>(a);
	for (int i = 0; i < l.n; i++)
	{
		std::cout << l.array[i] << " ";
	}
}
void Binary::add(const Integer* first, Integer* res)
{
	const Binary* b = dynamic_cast<const Binary*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Binary* d = dynamic_cast<Binary*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		c += m * array[i];
		m *= 2;
	}
	int k = 0;
	m = 1;
	for (int i = b->n - 1; i >= 0; i--)
	{
		k += m * b->array[i];
		m *= 2;
	}
	int sum = c + k;
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 2;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i = r - 1; i >= 0; i--)
	{
		l[i] = (sum1 % 2);
		sum1 /= 2;
	}
	delete[] d->array;
	d->array = l;
}
void Binary::dif(const Integer* first, Integer* res)
{
	const Binary* b = dynamic_cast<const Binary*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Binary* d = dynamic_cast<Binary*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		c += m * array[i];
		m *= 2;
	}
	int k = 0;
	m = 1;
	for (int i = b->n - 1; i >= 0; i--)
	{
		k += m * b->array[i];
		m *= 2;
	}
	int sum = c - k;
	if (sum < 0)
		throw OutOfRangeException("Difference<0!");
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 2;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i = r - 1; i >= 0; i--)
	{
		l[i] = (sum1 % 2);
		sum1 /= 2;
	}
	delete[] d->array;
	d->array = l;
}
void Binary::mult(const Integer* first, Integer* res)
{
	const Binary* b = dynamic_cast<const Binary*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Binary* d = dynamic_cast<Binary*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		c += m * array[i];
		m *= 2;
	}
	int k = 0;
	m = 1;
	for (int i = b->n - 1; i >= 0; i--)
	{
		k += m * b->array[i];
		m *= 2;
	}
	int sum = c * k;
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 2;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i = r - 1; i >= 0; i--)
	{
		l[i] = (sum1 % 2);
		sum1 /= 2;
	}
	delete[] d->array;
	d->array = l;
}
void Binary::div(const Integer* first, Integer* res)
{
	const Binary* b = dynamic_cast<const Binary*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Binary* d = dynamic_cast<Binary*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		c += m * array[i];
		m *= 2;
	}
	int k = 0;
	m = 1;
	for (int i = b->n - 1; i >= 0; i--)
	{
		k += m * b->array[i];
		m *= 2;
	}
	int sum = c / k;
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 2;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i = r - 1; i >= 0; i--)
	{
		l[i] = (sum1 % 2);
		sum1 /= 2;
	}
	delete[] d->array;
	d->array = l;
}