#include "Application.h"
#include <iostream>
#include<conio.h>
using namespace std;
void Application::Run()
{
    Array* a;
    Array* b;
    Array* res;
    int Key;
    bool flag = 1;
    while (flag != 0)
    {
        cout << ("\n Enter the number - the mode of operations with classes Array,Decimal and Octal"
            "\n 1 - Count summ of arr1 and arr2"
            "\n 2 - Count summ of d1 and d3"
            "\n 3 - Count summ of oct1 and oct2"
            "\n 4 - EXIT\n");
        cin >> Key;
        switch (Key)
        {
        case 1:
        {
            unsigned char j[5] = { 1,2,3,4,5 };
            unsigned char k[5] = { 1,1,1,1,1 };
            res = new Array;
            a = new Array(5, j);
            b = new Array(5, k);
            a->add(b, res);
            cout <<*a<<" + "<<*b<<" = " << *res << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete res;
            _getch();
            break;
        }
        case 2:
        {
            unsigned char l[6] = { 3,2,1,9,6,5 };
            a = new Decimal(6, l);
            unsigned char d[4] = { 7,6,8,2 };
            b = new Decimal(4, d);
            res = new Decimal;
            a->add(b, res);
            cout << *a << " + " << *b << " = " << *res << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete res;
            _getch();
            break;
        }
        case 3:
        {
            unsigned char u[5] = { 6,7,4,4,3 };
            a = new Octal(5, u);
            unsigned char p[4] = { 1,2,3,4 };
            b = new Octal(4, p);
            res = new Octal;
            a->add(b, res);
            cout << *a << " + " << *b << " = " << *res << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete res;
            _getch();
            break;
        }
        case 4:
            flag = 0;
            cout << "EXIT" << endl;
            break;

        default:
            printf("\nIncorrect input! Try again!!!");
            printf("\n\nPress any key to return in the menu...");
            _getch();
            break;
        }
    }
}