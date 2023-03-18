#include <iostream>
#include "Integer.h"
#include "Decimal.h"
#include "Exception.h"
void Decimal::GetNumber(const Integer& a)
{
	const Decimal& b = dynamic_cast<const Decimal&>(a);
	for (int i = 0; i < b.n; i++)
	{
		std::cout << b.array[i] << " ";
	}
}
void Decimal::add(const Integer* first, Integer* res)
{
	const Decimal* b = dynamic_cast<const Decimal*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Decimal* d = dynamic_cast<Decimal*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n-1; i>=0; i--)
	{
		c += m * array[i];
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = b->n-1; i>=0; i--)
	{
		k += m * b->array[i];
		m *= 10;
	}
	int sum = c + k;
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 10;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i=r-1; i>=0; i--)
	{
		l[i] = (sum1 % 10);
		sum1 /= 10;
	}
	delete[] d->array;
	d->array = l;
}
void Decimal::dif(const Integer* first, Integer* res)
{
	const Decimal* b = dynamic_cast<const Decimal*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Decimal* d = dynamic_cast<Decimal*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		c += m * array[i];
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = b->n - 1; i >= 0; i--)
	{
		k += m * b->array[i];
		m *= 10;
	}
	int sum = c - k;
	if (sum < 0)
		throw OutOfRangeException("Difference<0!");
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 10;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i = r - 1; i >= 0; i--)
	{
		l[i] = (sum1 % 10);
		sum1 /= 10;
	}
	delete[] d->array;
	d->array = l;
}
void Decimal::mult(const Integer* first, Integer* res)
{
	const Decimal* b = dynamic_cast<const Decimal*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Decimal* d = dynamic_cast<Decimal*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		c += m * array[i];
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = b->n - 1; i >= 0; i--)
	{
		k += m * b->array[i];
		m *= 10;
	}
	int sum = c * k;
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 10;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i = r - 1; i >= 0; i--)
	{
		l[i] = (sum1 % 10);
		sum1 /= 10;
	}
	delete[] d->array;
	d->array = l;
}
void Decimal::div(const Integer* first, Integer* res)
{
	const Decimal* b = dynamic_cast<const Decimal*>(first);
	if (b == nullptr)
		throw CastException("Cast Exception!");
	Decimal* d = dynamic_cast<Decimal*>(res);
	if (d == nullptr)
		throw CastException("Cast Exception!");
	int m = 1;
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		c += m * array[i];
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = b->n - 1; i >= 0; i--)
	{
		k += m * b->array[i];
		m *= 10;
	}
	int sum = c / k;
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 10;
		r++;
	}
	d->n = r;
	int* l = new int[r];
	for (int i = r - 1; i >= 0; i--)
	{
		l[i] = (sum1 % 10);
		sum1 /= 10;
	}
	delete[] d->array;
	d->array = l;
}