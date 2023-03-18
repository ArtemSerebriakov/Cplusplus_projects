#include "Decimal.h"
void Decimal::add(const Array* p_a, Array* res)
{
	int m = 1;
	int c = 0;
	const Decimal* s = dynamic_cast<const Decimal*>(p_a); // ГДЕ ПРОВЕРКА ПРАПВИЛЬНОСТИ ПРИВЕДЕНИЯ?
	Decimal* p = dynamic_cast<Decimal*>(res);  // ГДЕ ПРОВЕРКА ПРАПВИЛЬНОСТИ ПРИВЕДЕНИЯ?
	for (int i = 0; i < size; i++)
	{
		c += m * (a[i] - '0');
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = 0; i < s->size; i++)
	{
		k += m * (s->a[i] - '0');
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
	p->size = r;
	for (int i = 0; i < r; i++)
	{
		p->a[i] = (sum1 % 10) + '0';
		sum1 /= 10;
	}
}
std::istream& operator>> (std::istream& in, Decimal& p_a)
{
	for (int i = 0; i < p_a.size; i++)
	{
		in >> p_a.a[i];
	}
	return in;
}

Decimal& Decimal::operator=(const Decimal& d)
{
	if (this == &d)
		return *this;
	size = d.size;
	for (int i = 0; i<d.size; i++)
	{
		a[i] = d[i];
	}
	return *this;
}
bool Decimal::operator>(const Decimal& d)
{
	if(size > d.size)
	{
		return 1;
	}
	if(size < d.size)
	{
		return 0;
	}
	for(int i = size - 1; i >= 0; i--)
	{
		if (a[i] > d[i])
		{
			return 1;
		}
	}
	return 0;
}
bool Decimal::operator>=(const Decimal& d)
{
	if (size > d.size)
	{
		return 1;
	}
	if (size < d.size)
	{
		return 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		if (a[i] < d[i])
		{
			return 0;
		}
	}
	return 1;
}
bool Decimal::operator<(const Decimal& d)
{
	if (size < d.size)
	{
		return 1;
	}
	if (size > d.size)
	{
		return 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		if (a[i] < d[i])
		{
			return 1;
		}
	}
	return 0;
}
bool Decimal::operator<=(const Decimal& d)
{
	if (size < d.size)
	{
		return 1;
	}
	if (size > d.size)
	{
		return 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		if (a[i] > d[i])
		{
			return 0;
		}
	}
	return 1;
}
bool Decimal::operator==(const Decimal& d)
{
	if (size != d.size)
		return 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] != d[i])
		{
			return 0;
		}
	}
	return 1;
}
bool Decimal::operator!=(const Decimal& d)
{
	return !(*this == d);
}
Decimal Decimal::operator-(const Decimal& p_a)
{
	Decimal result;
	int m = 1;
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		c += m * (a[i] - '0');
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = 0; i < p_a.size; i++)
	{
		k += m * (p_a.a[i] - '0');
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
	result.size = r;
	for (int i = 0; i < r; i++)
	{
		result.a[i] = (sum1 % 10) + '0';
		sum1 /= 10;
	}
	return result;
}
Decimal Decimal::operator*(const Decimal& p_a)
{
	Decimal result;
	int m = 1;
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		c += m * (a[i] - '0');
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = 0; i < p_a.size; i++)
	{
		k += m * (p_a.a[i] - '0');
		m *= 10;
	}
	int sum = c*k;
	int sum1 = sum;
	int r = 0;
	while (sum != 0)
	{
		sum /= 10;
		r++;
	}
	result.size = r;
	for (int i = 0; i < r; i++)
	{
		result.a[i] = (sum1 % 10) + '0';
		sum1 /= 10;
	}
	return result;
}
Decimal Decimal::operator/(const Decimal& p_a)
{
	Decimal result;
	int m = 1;
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		c += m * (a[i] - '0');
		m *= 10;
	}
	int k = 0;
	m = 1;
	for (int i = 0; i < p_a.size; i++)
	{
		k += m * (p_a.a[i] - '0');
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
	result.size = r;
	for (int i = 0; i < r; i++)
	{
		result.a[i] = (sum1 % 10) + '0';
		sum1 /= 10;
	}
	return result;
}