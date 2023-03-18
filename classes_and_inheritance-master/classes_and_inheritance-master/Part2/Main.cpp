#include <conio.h>
#include <iostream>
#include "Exception.h"
#include "Array.h"
#include "Decimal.h"
#include "Octal.h"
#include "Application.h"
using namespace std;
int main()
{
	try 
	{
		Application a;
		a.Run();
	}
	catch (OutOfRangeException& exception)
	{
		cerr << exception.what() << endl;
	}
	catch (IncompetibleDimException& exception)
	{
		cerr << exception.what() << endl;
	}
	catch (std::exception& exception)
	{
		std::cerr << exception.what() << endl;
	}
	_getch();
	return 0;
}