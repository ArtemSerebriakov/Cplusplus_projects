#include "Payment.h"
#include <iostream>
Payment::Payment(const std::string& F,const double& S,const int& A,const int& Am,const int& D,const double& P,const double& I):name(F),sal(S),allday(A),woday(Am),year(D),pro(P),tax(I)
{
	// ИСПОЛЬЗОВАТЬ ДВОЕТОЧИЕ
// ОБЪЕКТЫ ПЕРЕДАЮТСЯ ПО КОНСТАНТНОЙ ССЫЛКЕ

	d++;
}
int Payment::d = 0;
std::ostream& operator<< (std::ostream& out, const Payment& m)
{
	out << "Name: " << m.name << ", Salary: " << m.sal << ", Year: " << m.year << ", Procent " << m.pro << ", Tax: " << m.tax << '\n' << ", Amount of days: " << m.allday << ", Amount of workdays: " << m.woday;
	return out;
}
Money Payment::countchsum()
{
	double b = (sal / allday) * woday;
	b *= 100;
	long c = b;
	unsigned char d = c % 100;
	Money chsum(c / 100, d);
	chsum = chsum + (chsum * (pro / 100));
	return chsum;
}
Money Payment::counthosum()
{
	Money hosum = countchsum() * 0.01 + countchsum() * 0.13;
	return hosum;
}
Money Payment::countsalary()
{
	return countchsum() - counthosum();
}
int Payment::yearcount(int c)
{
	return c - year;
}
void Payment::ShowCount() { std::cout << d; }