#include "Application.h"
#include <iostream>
#include<conio.h>
using namespace std;
void Application::Run()
{
    Integer* a{ nullptr };
    Integer* b{ nullptr };
    Integer* c{ nullptr };
    Integer* res{ nullptr };
    int Key;
    bool flag = 1;
    while (flag != 0)
    {
        cout << ("\n Enter the number - the mode of operations with classes Decimal and Binary"
            "\n 1 - Count summ of d1 and d3"
            "\n 2 - Count summ of bin1 and bin2"
            "\n 3 - Count difference between d1 and d3"
            "\n 4 - Count difference between bin1 and bin2"
            "\n 5 - Count product of d1 and d3"
            "\n 6 - Count product of bin1 and bin2"
            "\n 7 - Count division d1 by d3"
            "\n 8 - Count division bin1 by bin2"
            "\n 9 - EXIT\n");
        cin >> Key;
        switch (Key)
        {
        case 1:
        {
            int k[] = { 3,6,7,8,9 };
            int l[] = { 2,1,3,5,9 };
            a = new Decimal(5, k);
            b = new Decimal(5, l);
            c = new Decimal();
            res = new Decimal();
            c->GetNumber(*a);
            cout << " + ";
            c->GetNumber(*b);
            a->add(b,res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }
        case 2:
        {
            int k[] = { 1,1,0,1,0 };
            int l[] = { 1,0,1,0,0 };
            a = new Binary(5, k);
            b = new Binary(5, l);
            c = new Binary();
            res = new Binary();
            c->GetNumber(*a);
            cout << " + ";
            c->GetNumber(*b);
            a->add(b, res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }
        case 3:
        {
            int k[] = { 3,6,7,8,9 };
            int l[] = { 2,1,3,5,9 };
            a = new Decimal(5, k);
            b = new Decimal(5, l);
            c = new Decimal();
            res = new Decimal();
            c->GetNumber(*a);
            cout << " - ";
            c->GetNumber(*b);
            a->dif(b, res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }

        case 4:
        {
            int k[] = { 1,1,0,1,0 };
            int l[] = { 1,0,1,0,0 };
            a = new Binary(5, k);
            b = new Binary(5, l);
            c = new Binary();
            res = new Binary();
            c->GetNumber(*a);
            cout << " - ";
            c->GetNumber(*b);
            a->dif(b, res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }

        case 5:
        {
            int k[] = { 3,6,7,8,9 };
            int l[] = { 2,1,3,5,9 };
            a = new Decimal(5, k);
            b = new Decimal(5, l);
            c = new Decimal();
            res = new Decimal();
            c->GetNumber(*a);
            cout << " * ";
            c->GetNumber(*b);
            a->mult(b, res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }

        case 6:
        {
            int k[] = { 1,1,0,1,0 };
            int l[] = { 1,0,1,0,0 };
            a = new Binary(5, k);
            b = new Binary(5, l);
            c = new Binary();
            res = new Binary();
            c->GetNumber(*a);
            cout << " * ";
            c->GetNumber(*b);
            a->mult(b, res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }

        case 7:
        {
            int k[] = { 3,6,7,8,9 };
            int l[] = { 2,1,3,5,9 };
            a = new Decimal(5, k);
            b = new Decimal(5, l);
            c = new Decimal();
            res = new Decimal();
            c->GetNumber(*a);
            cout << " / ";
            c->GetNumber(*b);
            a->div(b, res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }

        case 8:
        {
            int k[] = { 1,1,0,1,0 };
            int l[] = { 1,0,1,0,0 };
            a = new Binary(5, k);
            b = new Binary(5, l);
            c = new Binary();
            res = new Binary();
            c->GetNumber(*a);
            cout << " / ";
            c->GetNumber(*b);
            a->div(b, res);
            cout << " = ";
            c->GetNumber(*res);
            cout << endl;
            printf("\n\nPress any key to return in the menu...");
            delete a;
            delete b;
            delete c;
            delete res;
            _getch();
            break;
        }

        case 9:
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