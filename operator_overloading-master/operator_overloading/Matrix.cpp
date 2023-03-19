#include <iostream>
#include "CslrMatrix.h"
using namespace std;
cslrMatrix::cslrMatrix(int N, int NZ, double* adiag, int* jptr, double* altr, int* RowIndex) : 
	m_N(N), m_NZ(NZ)
{
	m_adiag = new double[m_N];
	if (adiag != nullptr)
	{
		for (int i = 0; i < m_N; ++i)
		{
			m_adiag[i] = adiag[i];
		}
	}
	else
	{
		for (int i = 0; i < m_N; ++i)
		{
			m_adiag[i] = 0;
		}
	}
	m_jptr = new int[(m_NZ - m_N) / 2];
	if (jptr != nullptr)
	{
		for (int i = 0; i < (m_NZ - m_N) / 2; ++i)
		{
			m_jptr[i] = jptr[i];
		}
	}
	else
	{
		for (int i = 0; i < (m_NZ - m_N) / 2; ++i)
		{
			m_jptr[i] = 0;
		}
	}
	m_RowIndex = new int[m_N + 1];
	if (RowIndex != nullptr)
	{
		for (int i = 0; i < m_N + 1; ++i)
		{
			m_RowIndex[i] = RowIndex[i];
		}
	}
	else
	{
		for (int i = 0; i < m_N + 1; ++i)
		{
			m_RowIndex[i] = 0;
		}
	}
	m_altr = new double[(m_NZ - m_N) / 2];
	if (altr != nullptr)
	{
		for (int i = 0; i < (m_NZ - m_N) / 2; ++i)
		{
			m_altr[i] = altr[i];
		}
	}
	else
	{
		for (int i = 0; i < (m_NZ - m_N) / 2; ++i)
		{
			m_altr[i] = 0;
		}
	}
}
cslrMatrix:: ~cslrMatrix()
{
	delete[] m_adiag;
	delete[] m_jptr;
	delete[] m_RowIndex;
	delete[] m_altr;
}
std::istream& operator>> (std::istream& in, cslrMatrix& p_a)
{
	cout << "Vvedite " << p_a.m_N << " diagonalnyh elementov matritsy sverhu vniz:" << endl;
	for (int i = 0; i < p_a.m_N; ++i)
	{
		in >> p_a.m_adiag[i];
	}
	cout << "Vvedite " << (p_a.m_NZ - p_a.m_N) / 2 << " nenulevyh elementov matritsy nizhe glavnoy diagonaly sverhu vniz sleva napravo:" << endl;
	for (int i = 0; i < (p_a.m_NZ - p_a.m_N) / 2; ++i)
	{
		in >> p_a.m_altr[i];
	}
	cout << "Vvedite " << (p_a.m_NZ - p_a.m_N) / 2 << " nomerov stolbtsov nenulevyh elementov mtritsy nizhe glavnoy diagonaly,sootvetstvuyushih vvedennym vyshe elementam:" << endl;
	for (int i = 0; i < (p_a.m_NZ - p_a.m_N) / 2; ++i)
	{
		in >> p_a.m_jptr[i];
	}
	cout << "Vvedite " << p_a.m_N + 1 << " elementov massiva RowIndex: " << endl;
	for (int i = 0; i < p_a.m_N + 1; ++i)
	{
		in >> p_a.m_RowIndex[i];
	}
	return in;
}
std::ostream& operator<< (std::ostream& out, const cslrMatrix& p_a)
{
	out << "Vvedeno " << p_a.m_N << " diagonalnyh elementov matritsy sverhu vniz:" << endl;
	for (int i = 0; i < p_a.m_N; ++i)
	{
		out << p_a.m_adiag[i] << " ";
	}
	out << endl;
	out << "Vvedeno " << (p_a.m_NZ - p_a.m_N) / 2 << " nenulevyh elementov mtritsy nizhe glavnoy diagonaly sverhu vniz sleva napravo:" << endl;
	for (int i = 0; i < (p_a.m_NZ - p_a.m_N) / 2; ++i)
	{
		out << p_a.m_altr[i] << " ";
	}
	out << endl;
	out << "Vvedeno " << (p_a.m_NZ - p_a.m_N) / 2 << " nomerov stolbtsov nenulevyh elementov mtritsy nizhe glavnoy diagonaly,sootvetstvuyushih vvedennym vyshe elementam:" << endl;
	for (int i = 0; i < (p_a.m_NZ - p_a.m_N) / 2; ++i)
	{
		out << p_a.m_jptr[i] << " ";
	}
	out << endl;
	out << "Vvedeno " << p_a.m_N + 1 << " elementov massiva RowIndex : " << endl;
	for (int i = 0; i < p_a.m_N + 1; ++i)
	{
		out << p_a.m_RowIndex[i] << " ";
	}
	return out;
}
cslrMatrix operator*(const cslrMatrix& mat, double a)
{
	int i;
	int z = mat.m_NZ;
	int* jptr = new int[(mat.m_NZ - mat.m_N) / 2];
	int* RowIndex = new int[mat.m_N + 1];
	double* adiag = new double[mat.m_N];
	double* altr = new double[(mat.m_NZ - mat.m_N) / 2];
	for (i = 0; i < mat.m_N; i++)
	{
		adiag[i] = a * mat.m_adiag[i];
	}
	for (i = 0; i < (mat.m_NZ - mat.m_N) / 2; i++)
	{
		altr[i] = a * mat.m_altr[i];
	}
	if (fabs(a)<1e-12)// ЛУЧШЕ std::fabs(a) < 1.E-12
	{
		for (i = 0; i < (mat.m_NZ - mat.m_N) / 2; i++)
		{
			jptr[i] = 0;
		}
		for (i = 0; i < mat.m_N + 1; i++)
		{
			RowIndex[i] = 0;
		}
	}
	else
	{
		for (i = 0; i < (mat.m_NZ - mat.m_N) / 2; i++)
		{
			jptr[i] = mat.m_jptr[i];
		}
		for (i = 0; i < mat.m_N + 1; i++)
		{
			RowIndex[i] = mat.m_RowIndex[i];
		}
	}
	return cslrMatrix(mat.m_N, z, adiag, jptr, altr, RowIndex);
}
cslrMatrix operator*(double a,const cslrMatrix& mat)
{
	return mat * a;
}
int cslrMatrix::razmern() const 
{
	return (*this).m_N;
}
int cslrMatrix::nenul() const
{
	return (*this).m_NZ;
}