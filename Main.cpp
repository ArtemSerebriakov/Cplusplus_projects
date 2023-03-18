#include<conio.h>
#include<iostream>
#include "Money.h"
#include "Payment.h"
#include "Application.h"
using namespace std;
// ЭТО ДЕЛАЕТСЯ В СООТВЕТСТВУЮЩЕМ CPP ФАЙЛЕ. К ЭТОМУ ФАЙЛУ ЭТОТ КОД ОТНОШЕНИЯ НЕ ИМЕЕТ
int main()
{
	Money m1(39, 76);
	Money m2(39, 56);
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;
	double b = 0.75;
	Payment pay("John Johnson", 119000, 30, 20,2010, 10, 10);
	cout << pay << endl;
	Application ap;
	ap.Run();
	_getch();
	return 0;
}