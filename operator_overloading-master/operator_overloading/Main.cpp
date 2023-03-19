#include <iostream>
#include <conio.h>
#include <cmath>
#include <exception>
#include <string>
#include "Vector.h"
#include "CslrMatrix.h"
#include "Exception.h"
using namespace std;
int main()
{
	int n;
	cout << "Vvedite razmer vectora:" << endl;
	cin >> n;
	try
	{
		Vector vec1(n);
		cout << "Vvedite " << n << " koordinat vec1" << endl;
		cin >> vec1;
		cout << "Vvedennyi vec1:" << endl;
		cout << vec1 << endl;
		Vector vec2(vec1);
		cout << "Vypolneno kopirovanie vec2 v vec1" << endl;
		cout << "vec2:" << endl;
		cout << vec2 << endl;
		Vector vec3(n);
		vec3 = vec1 + vec2;
		cout << "vec3=vec1+vec2:" << endl;
		cout << vec3 << endl;
		cout << "vec1-vec2:" << endl;
		cout << vec1 - vec2 << endl;
		cout << "-vec2:" << endl;
		cout << -vec2 << endl;
		cout << "+vec2:" << endl;
		cout << +vec2 << endl;
		cout << "Skalyarnoe proizvedenie vec2 na vec3:" << endl;
		cout << vec2 * vec3 << endl;
		cout << "Vvedite chislo dlya umnozheniya na vec3:" << endl;
		double b;
		cin >> b;
		cout << "Proizvedenie vec3 i chisla " << b << " ravno:" << endl;
		cout << vec3 * b << endl;
		cout << "Proizvedenie chisla " << b << " i vec3 ravno:" << endl;
		cout << b * vec3 << endl;
		cout << "Uvelichivaev vec1 na vec3:" << endl;
		cout << (vec1 += vec3) << endl;
		cout << "Umenshaem vec2 na vec3:" << endl;
		cout << (vec2 -= vec3) << endl;
		cout << "Vvedite nomer zhelaemoy koordinaty vec2:" << endl;
		int l;
		cin >> l;
		cout << "Koordinata vec2 pod nomerom " << l << " :" << endl;
		cout << vec2[l] << endl;
		cout << "Adres vec2:" << endl;
		Printuk(vec2);
		cout << "Dlina vec2:" << endl;
		cout<<vec2.length()<<endl;
		cout << "Razmernost vec2:" << endl;
		cout<<vec2.size()<<endl;
		cout << "Vvedite razmer vec4: " << endl;
		int w;
		cin >> w;
		Vector vec4(w);
		cout << "Vvedite " << w << " koordinat vec4: " << endl;
		cin >> vec4;
		cout << "vec4: " << endl;
		cout << vec4 << endl;
		cout << "Vvedite nomer izmenyaemoy koordinaty vec4: " << endl;
		int h;
		cin >> h;
		cout << "Vvedite novoe znachenie " << h << " koordinaty vec4: " << endl;
		cin >> vec4[h];
		cout << "vec4: " << endl;
		cout << vec4 << endl;
        cout << "vec4=vec3=  ";
		vec4 = vec3;
		cout << vec4 << endl;
		Vector vec6;
		cout << "Pustomu vec6 prisvoim vec4" << endl;
		vec6 = vec4;
		cout << "vec6:" << endl;
		cout << vec6 << endl;
		cout << "Vvedite razmer razrezhennoy simmetrichnoy matritsy:" << endl;
		int k;
		cin >> k;
		cout << "Vvedite kolichestvo nenulevyh elementov matritsy:" << endl;
		int p;
		cin >> p;
		cslrMatrix mat1(k, p);
		cout << "Vvedite razrezhennuyu simmetrichnuyu matritsu mat1:" << endl;
		cout << "massiv ROW_INDEX menyaet nomera strok na index nachala kazhdoy stroki ili," 
			<<"po-drugomu, soderzhit kol-vo elementov v kazhdoy stroke"<<
			"nizhnego treugolnika bez ucheta diagonalnyh elementov, " <<
			"posledniy element-obshee kolichestvo nenulevyh elementov nizhe glavnoy diagonaly"<<endl;
		cin >> mat1;
		cout << mat1 << endl;
		cout << "mat1*vec3= " << mat1 * vec3 << endl;
		cout << "vec3*mat1= " << vec3 * mat1 << endl;
		cout << "Vvedite chislo dlya umnozhenyya na matritsu:" << endl;
		double a;
		cin >> a;
		cout << "mat1* " << a << " :" << endl;
		cout << mat1 * a << endl;
		cout << a << " * mat1:" << endl;
		cout << a * mat1 << endl;
		cout << "Razmernost mat1:" << endl;
		cout<<mat1.razmern()<<endl;
		cout << "Kolichestvo nenulevyh elementov v mat1:" << endl;
		cout<<mat1.nenul()<<endl;
		Vector vec5(n);
		cout << "vec5 = mat1*vec3*4-5*vec1+vec2*mat1= ";
		vec5 = mat1 * vec3 * 4 - 5 * vec1 + vec2 * mat1;
		cout << vec5 << endl;
	}
	catch (std::bad_alloc& exception)
	{
		cerr << "Vveden nekorrektnyi razmer vectora/matritsy!" << endl;
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
		std::cerr << exception.what() <<endl;
	}
   _getch();
	return 0;
}