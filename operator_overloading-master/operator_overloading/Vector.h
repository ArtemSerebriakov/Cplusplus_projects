#pragma once
class cslrMatrix;
class Vector
{
private:
	int m_n;
	double* m_arr;
public:
	Vector(int n=0); 
	Vector(const Vector& p_a) :m_n(p_a.m_n)
	{
		m_arr = new double[m_n];
		for (int i = 0; i < m_n; ++i)
			m_arr[i] = p_a.m_arr[i];
	};
	~Vector()
	{
		delete[] m_arr;
	}
	Vector& operator= (const Vector& p_a);
	friend Vector operator+(const Vector& p_a, const Vector& p_b);
	friend double operator*(const Vector& p_a, const Vector& p_b);
	friend Vector operator*(const Vector& p_a, double b);
	friend Vector operator*(double b, const Vector& p_a);
	friend Vector operator-(const Vector& p_a, const Vector& p_b);
	friend std::ostream& operator<< (std::ostream& out, const Vector& p_a);
	friend std::istream& operator>> (std::istream& in,Vector& p_a);
	friend Vector operator*(const cslrMatrix& mat, const Vector& veca);
	friend Vector operator*(const Vector& veca,const cslrMatrix& mat);
	Vector operator-()const;
	const Vector& operator+() const;
	Vector& operator+=(const Vector& p_b);
	Vector& operator-=(const Vector& p_b);
	double& operator[] (const int index);   
	double& operator[] (const int index) const;    
	operator double* ()
	{
		return m_arr;
	}
	double length() const;      
	int size() const;
};
void Printuk(double* a);