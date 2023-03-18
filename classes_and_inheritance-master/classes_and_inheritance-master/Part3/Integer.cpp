#include "Integer.h"
Integer::Integer(int num, int* a)
{
	array = new int[num];
	n = num;
	for (int i = 0; i < num; i++)
	{
		array[i] = a[i];
	}
}
Integer::Integer() :array(nullptr), n(0)
{
}
Integer::~Integer()
{
	delete[] array;
}