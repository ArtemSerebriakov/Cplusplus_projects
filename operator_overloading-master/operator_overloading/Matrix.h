#pragma once
class Vector;
class cslrMatrix
{
private:
	int m_N;
	int m_NZ;
	int* m_jptr;
	int* m_RowIndex;
	double* m_adiag;
	double* m_altr;
public:
	cslrMatrix(int N, int NZ, double* adiag=nullptr, int* jptr=nullptr, double* altr=nullptr, int* RowIndex=nullptr);
	~cslrMatrix();// ПЕРЕНЕСТИ В CPP
	friend std::istream& operator>> (std::istream& in, cslrMatrix& p_a);
	friend std::ostream& operator<< (std::ostream& out, const cslrMatrix& p_a);
	friend Vector operator*(const cslrMatrix& mat,const Vector& veca);
	friend Vector operator*(const Vector& veca,const cslrMatrix& mat);
	friend cslrMatrix operator*(const cslrMatrix& mat, double a);
	friend cslrMatrix operator*(double a,const cslrMatrix& mat);
	int razmern() const;
	int nenul() const;
};