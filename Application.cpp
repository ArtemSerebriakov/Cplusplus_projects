#include "Application.h"
#include <iostream>
#include<conio.h>
using namespace std;
void Application::Run()
{
    int Key;
    bool flag = 1;
while (flag!=0)
{
    cout<<("\n Enter the number - the mode of operations with classes Money and Payment"
        "\n 1 - Count sum of Monies"
        "\n 2 - Count difference of Monies"
        "\n 3 - Count product of Monies"
        "\n 4 - Count division of Monies"
        "\n 5 - Count product of Money and number"
        "\n 6 - Count difference between Money and number"
        "\n 7 - Comparison of Monies"
        "\n 8 - Count Charged sum of Payment"
        "\n 9 - Count Hold sum of Payment"
        "\n 10 - Count final salary of Payment"
        "\n 11 - Count work experience of Payment"
        "\n 12 - Amount of created objects of Money:"
        "\n 13 - Amount of created objects of Payment:"
        "\n 14 - EXIT\n");
    cin >> Key;
    switch (Key)
    {
    case 1:
        cout << m1 << " + " << m2 << " = " << m1 + m2 << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 2:
        cout << m1 << " - " << m2 << " = " << m1 - m2 << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 3:
        cout << m1 << " * " << m2 << " = " << m1 * m2 << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 4:
        cout << m1 << " / " << m2 << " = " << m1 / m2 << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 5:
        cout << m1 << " * " << b << " = " << m1 * b << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 6:
        cout << m1 << " / " << b << " = " << m1 / b << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 7:
        if (m1 <= m2)
        {
            cout << m1 << " <= " << m2 << endl;
        }
        if (m1 >= m2)
        {
            cout << m1 << " >= " << m2 << endl;
        }
        if (m1 < m2)
        {
            cout << m1 << " < " << m2 << endl;
        }
        if (m1 > m2)
        {
            cout << m1 << " > " << m2 << endl;
        }
        if (m1 == m2)
        {
            cout << m1 << " == " << m2 << endl;
        }
        if (m1 != m2)
        {
            cout << m1 << " != " << m2 << endl;
        }
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 8:
        cout << "Charged sum: " << pay.countchsum() << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 9:
        cout << "Hold sum: " << pay.counthosum() << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 10:
        cout << "Final salary: " << pay.countsalary() << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 11:
        cout << "Work experience: " << pay.yearcount(2020) << " years" << endl;
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;
    case 12:
        cout << "Amount of created objects of Money : ";
        Money::ShowCount();
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 13:
        cout << "Amount of created objects of Payment : ";
        Payment::ShowCount();
        printf("\n\nPress any key to return in the menu...");
        _getch();
        break;

    case 14: 
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