#include "Money.h"
Money::Money():rub(0),kop(0)// ИСПОЛЬЗОВАТЬ ДВОЕТОЧИЕ
{
	c++;
}
int Money::c = 0;
Money operator+(const Money& m1, const Money& m2)
{
	Money m3;
	m3.rub = m1.rub + m2.rub;
	if ((m1.kop + m2.kop) >= 100)
	{
		m3.rub++;
		m3.kop = m1.kop + m2.kop - 100;
	}
	else
	{
		m3.kop = m1.kop + m2.kop;
	}
	return m3;
}
Money operator-(const Money& m1, const Money& m2)
{
	Money m3;
	m3.rub = m1.rub - m2.rub;
	if ((m1.kop - m2.kop) < 0)
	{
		m3.rub--;
		m3.kop = 100 - (m2.kop - m1.kop);
	}
	else
	{
		m3.kop = m1.kop - m2.kop;
	}
	return m3;
}
Money operator/(const Money& m1, const Money& m2)
{
	Money m3;
	double d = (static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) / (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100));
	m3.rub = static_cast<long>(d);
	m3.kop = static_cast<unsigned char>((d - m3.rub) * 100);
	return m3;
}
Money operator/(const Money& m1, double b)
{
	Money m3;
	double d = (static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) / b;
	m3.rub = static_cast<long>(d);
	m3.kop = static_cast<unsigned char>((d - m3.rub) * 100);
	return m3;
}
Money operator*(const Money& m1, const Money& m2)
{
	Money m3;
	double d = (static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) * (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100));
	m3.rub = static_cast<long>(d);
	m3.kop = static_cast<unsigned char>((d - m3.rub) * 100);
	return m3;
}
Money operator*(const Money& m1, double b)
{
	Money m3;
	double d = (static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) * b;
	m3.rub = static_cast<long>(d);
	m3.kop = static_cast<unsigned char>((d - m3.rub) * 100);
	return m3;
}
bool operator<=(const Money& m1, const Money& m2)// НЕ ПРОЩЕ ОДНОЙ СТРОКОЙ ВЕЗДЕ?
    // return ((static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) <=
    //         (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100)));

{
	return ((static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) <=(static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100)));

}
bool operator>=(const Money& m1, const Money& m2)
{
	return ((static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) >= (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100)));
}
bool operator<(const Money& m1, const Money& m2)
{
	return ((static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) < (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100)));
}
bool operator>(const Money& m1, const Money& m2)
{
	return ((static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) > (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100)));

}
bool operator==(const Money& m1, const Money& m2)
{
	return ((static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) == (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100)));
}
bool operator!=(const Money& m1, const Money& m2)
{
	return ((static_cast<double>(m1.rub) + (static_cast<double>(m1.kop) / 100)) != (static_cast<double>(m2.rub) + (static_cast<double>(m2.kop) / 100)));
}
void Money::ShowCount() { std::cout << c; }
std::ostream& operator<< (std::ostream& out, const Money& m)
{
	out << m.rub << "," << static_cast<int>(m.kop);
	return out;
}