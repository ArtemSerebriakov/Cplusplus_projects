#include "Octal.h"
#include <sstream>
void Octal::add(const Array* p_a, Array* res)
{
	unsigned int ar, br;
	unsigned char buf[100];
	const Octal* f = dynamic_cast<const Octal*>(p_a); // ГДЕ ПРОВЕРКА ПРАПВИЛЬНОСТИ ПРИВЕДЕНИЯ?
	Octal* q = dynamic_cast<Octal*>(res); // ГДЕ ПРОВЕРКА ПРАПВИЛЬНОСТИ ПРИВЕДЕНИЯ?
	std::stringstream s, d, result, ss;
	s.setf(std::ios::oct, std::ios::basefield);
	d.setf(std::ios::oct, std::ios::basefield);
	result.setf(std::ios::oct, std::ios::basefield);
	unsigned char* h = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		h[i] = a[size - 1 - i];
	}
	unsigned char* p = new unsigned char[f->size];
	for (int i = 0; i < f->size; i++)
	{
		p[i] = f->a[f->size - 1 - i];
	}
	s << h;
	d << p;
	s >> ar;
	d >> br;
	result << ar + br;
	result >> buf;
	ss << buf;
	int k = 0;
	ss >> k;
	q->size = (result.str().length());
	for (int i = 0; i < result.str().length(); i++)
	{
		q->a[i] = k % 10 + '0';
		k /= 10;
	}
	delete[] h;
	delete[] p;
}
std::istream& operator>> (std::istream& in, Octal& p_a)
{
	for (int i = 0; i < p_a.size; i++)
	{
		in >> p_a.a[i];
	}
	return in;
}
Octal& Octal::operator=(const Octal& d)
{
	if (this == &d)
		return *this;
	size = d.size;
	for (int i = 0; i < d.size; i++)
	{
		a[i] = d[i];
	}
	return *this;
}
bool Octal::operator>(const Octal& d)
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
		if (a[i] > d[i])
		{
			return 1;
		}
	}
	return 0;
}
bool Octal::operator>=(const Octal& d)
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
bool Octal::operator<(const Octal& d)
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
bool Octal::operator<=(const Octal& d)
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
bool Octal::operator==(const Octal& d)
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
bool Octal::operator!=(const Octal& d)
{
	return !(*this == d);
}
Octal Octal::operator-(const Octal& p_a)
{
	if (*this < p_a)
		throw OutOfRangeException("Difference<0!");
	unsigned int ar, br;
	unsigned char buf[100];
	std::stringstream s, d, res,ss;
	s.setf(std::ios::oct, std::ios::basefield);
	d.setf(std::ios::oct, std::ios::basefield);
	res.setf(std::ios::oct, std::ios::basefield);
	unsigned char* h = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		h[i] = a[size - 1 - i];
	}
	unsigned char* p = new unsigned char[p_a.size];
	for (int i = 0; i < p_a.size; i++)
	{
		p[i] = p_a[p_a.size - 1 - i];
	}
	s << h;
	d << p;
	s >> ar;
	d >> br;
	res << ar - br;
	res >> buf;
	ss << buf;
	int k = 0;
	ss >> k;
	Octal temp(res.str().length());
	for (int i = 0; i < res.str().length(); i++)
	{
		temp.a[i] = k%10+'0';
		k /= 10;
	}
	delete[] h;
	delete[] p;
	return temp;
}
Octal Octal::operator*(const Octal& p_a)
{
	unsigned int ar, br;
	unsigned char buf[100];
	std::stringstream s, d, res, ss;
	s.setf(std::ios::oct, std::ios::basefield);
	d.setf(std::ios::oct, std::ios::basefield);
	res.setf(std::ios::oct, std::ios::basefield);
	unsigned char* h = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		h[i] = a[size - 1 - i];
	}
	unsigned char* p = new unsigned char[p_a.size];
	for (int i = 0; i < p_a.size; i++)
	{
		p[i] = p_a[p_a.size - 1 - i];
	}
	s << h;
	d << p;
	s >> ar;
	d >> br;
	res << ar * br;
	res >> buf;
	ss << buf;
	int k = 0;
	ss >> k;
	Octal temp(res.str().length());
	for (int i = 0; i < res.str().length(); i++)
	{
		temp.a[i] = k % 10 + '0';
		k /= 10;
	}
	delete[] h;
	delete[] p;
	return temp;
}
Octal Octal::operator/(const Octal& p_a)
{
	unsigned int ar, br;
	unsigned char buf[100];
	std::stringstream s, d, res, ss;
	s.setf(std::ios::oct, std::ios::basefield);
	d.setf(std::ios::oct, std::ios::basefield);
	res.setf(std::ios::oct, std::ios::basefield);
	unsigned char* h = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		h[i] = a[size - 1 - i];
	}
	unsigned char* p = new unsigned char[p_a.size];
	for (int i = 0; i < p_a.size; i++)
	{
		p[i] = p_a[p_a.size - 1 - i];
	}
	s << h;
	d << p;
	s >> ar;
	d >> br;
	res << ar / br;
	res >> buf;
	ss << buf;
	int k = 0;
	ss >> k;
	Octal temp(res.str().length());
	for (int i = 0; i < res.str().length(); i++)
	{
		temp.a[i] = k % 10 + '0';
		k /= 10;
	}
	delete[] h;
	delete[] p;
	return temp;
}