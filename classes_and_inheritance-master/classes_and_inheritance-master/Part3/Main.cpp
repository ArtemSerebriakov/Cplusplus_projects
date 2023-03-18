#include <iostream>
#include <conio.h>
#include "Integer.h"
#include "Decimal.h"
#include "Binary.h"
#include "Exception.h"
#include "Application.h"
using namespace std;
int main()
{
	try 
	{
		Application a;
		a.Run();
	}
	catch (std::bad_cast& exception)
	{
		cerr << "Bad dynamic cast of reference!" << endl;
	}
	catch (OutOfRangeException& exception)
	{
		cerr << exception.what() << endl;
	}
	catch (CastException& exception)
	{
		cerr << exception.what() << endl;
	}
	_getch();
	return 0;
}