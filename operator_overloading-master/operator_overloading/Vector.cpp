#include <iostream>
#include "Vector.h"
#include "Exception.h"
#include "CslrMatrix.h"
using namespace std;
Vector::Vector(int n) :m_n(n)
{
	m_arr = new double[m_n];
}
Vector operator+(const Vector& p_a, const Vector& p_b)// ЕСЛИ РАЗМЕРЫ НЕ СОВПАДАЮТ НАДО ГЕНЕРИТЬ ИСКЛЮЧЕНИЕ ВО ВСЕХ БИНАРНЫХ ОПЕРАЦИЯХ
{
	if (p_a.m_n != p_b.m_n)
		throw IncompetibleDimException("Nevozmozhno slozhit vectory, t.k. oni imeyut raznyi razmer");
	Vector vec(p_a.m_n);
	for (int i = 0; i < p_a.m_n; i++)
	{
		vec.m_arr[i] = p_a.m_arr[i] + p_b.m_arr[i];
	}
	return vec;
}

Vector operator*(const Vector& p_a, double b)
{
	Vector vec(p_a.m_n);
	for (int i = 0; i < p_a.m_n; i++)
	{
		vec.m_arr[i] = p_a.m_arr[i] * b;
	}
	return vec;
}
Vector operator*(double b, const Vector& p_a)
{
	return p_a * b;
}
Vector operator-(const Vector& p_a, const Vector& p_b)
{
	if (p_a.m_n != p_b.m_n)
		throw IncompetibleDimException("Nevozmozhno naity raznost vectorov, t.k. oni imeyut raznyi razmer");
	return p_a + (-1) * p_b;
}
Vector Vector::operator-()const// здесь не могу возвращать по ссылке,тк функция умножения возвращает вектор
{
	return (-1) * (*this);
}
const Vector& Vector::operator+() const
{
	return (*this);
}
std::ostream& operator<< (std::ostream& out, const Vector& p_a)
{
	for (int i = 0; i < p_a.m_n; i++)
	{
		out << p_a.m_arr[i] << " ";
	}
	return out;
}

std::istream& operator>> (std::istream& in,Vector& p_a)
{
	for (int i = 0; i < p_a.m_n; i++)
	{
		in >> p_a.m_arr[i];
	}
	return in;
}
double operator*(const Vector& p_a, const Vector& p_b)
{
	if (p_a.m_n != p_b.m_n)
		throw IncompetibleDimException("Nevozmozhno naiti skalyarnoe proizvedenie vectorov, t.k. oni imeyut raznyi razmer");
	double x = 0;
	for (int i = 0; i < p_a.m_n; i++)
	{
		x += p_a.m_arr[i] * p_b.m_arr[i];
	}
	return x;
}
Vector& Vector::operator+=(const Vector& p_b)
{
	if (this->m_n!= p_b.m_n)
		throw IncompetibleDimException("Nevozmozhno uvelichit pervyi vector na vtoroy, t.k. oni imeyut raznyi razmer");
	for (int i = 0; i < p_b.m_n; i++)
	{
		this->m_arr[i] += p_b.m_arr[i];
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& p_b)
{
	if (this->m_n != p_b.m_n)
		throw IncompetibleDimException("Nevozmozhno umenshit pervyi vector na vtoroy, t.k. oni imeyut raznyi razmer");
	for (int i = 0; i < p_b.m_n; i++)
	{
		this->m_arr[i] -= p_b.m_arr[i];
	}
	return *this;
}
double Vector::length() const
{
	double len = 0;
	for (int i = 0; i < (*this).m_n; i++)
	{
		len += ((*this).m_arr[i] * (*this).m_arr[i]);
	}
	return (sqrt(len));
}
int Vector::size() const
{
	return (*this).m_n;
}

double& Vector::operator[] (const int index) const
{
	if (index < 0 || index >= m_n)
		throw OutOfRangeException("Ne sushestvuyet!");
	return m_arr[index];
}
double& Vector::operator[] (const int index)
{
	if (index < 0 || index >= m_n)
		throw OutOfRangeException("Invalid index!");
	return m_arr[index];
}
Vector& Vector::operator= (const Vector& p_a)  
{
	if (this == &p_a)                 
	{
		return *this;
	}
		if (m_n == p_a.m_n)
		{
			for (int i = 0; i < p_a.m_n; i++)
			{
				m_arr[i] = p_a.m_arr[i];
			}
		}
		else
		{
				double* d = new double[p_a.m_n];
				for (int i = 0; i < p_a.m_n; i++)
				{
					d[i] = p_a.m_arr[i];
				}
				m_n = p_a.m_n;
				delete [] m_arr;
				m_arr = d;
		}
	return *this;
}
Vector operator*(const cslrMatrix& mat, const Vector& veca)
{
	if (mat.m_N != veca.m_n)
		throw IncompetibleDimException("Proizvedenie matritsy i vectora nevozmozhno,t.k. razmer matritsy ne sovpadaet s razmerom vectora");
	int i, j;
	Vector vec(veca.m_n);
	for (i = 0; i < mat.m_N; i++)
		vec.m_arr[i] = 0;
	for (i = 0; i < mat.m_N; i++)
	{
		vec.m_arr[i] = veca.m_arr[i] * mat.m_adiag[i];//элементы i-ой строки рез вект увеличивается на произв диагонального ненул эл i-ой стр и эл i-ой стр вект
		for (j = mat.m_RowIndex[i]; j < mat.m_RowIndex[i + 1]; j++)//выполняется столько раз сколько ненулевых недиагональных элементов в нижнем треуг в i-ой стр
		{
			vec.m_arr[i] = vec.m_arr[i] + veca.m_arr[mat.m_jptr[j]] * mat.m_altr[j];//эл i-ой стр рез вект увел на произв эл j-ой стр век на ненул эл j-ого столб i-ой стр мат расп ниже гл диаг
			vec.m_arr[mat.m_jptr[j]] = vec.m_arr[mat.m_jptr[j]] + veca.m_arr[i] * mat.m_altr[j];//увел эл j-ой стр рез вект на произв симм эл относит эл j-ого столб i-ой стр мат на эл i-ой стр вект
		}
	}
	return vec;
}
Vector operator*(const Vector& veca,const cslrMatrix& mat)
{
	return mat * veca;
}
void Printuk(double* a)
{
	cout << a << endl;
}