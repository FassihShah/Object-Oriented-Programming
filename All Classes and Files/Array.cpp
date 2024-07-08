#include<iostream>
#include<stdarg.h>
#include "Array.h"
using namespace std;
void Array::copyArray(int* const dest, const int* const src, int cap)
{
	int i = 0;
	if (src == nullptr)
	{
		return;
	}
	for (int i = 0; i < cap; i = i + 1)
	{
		dest[i] = src[i];
	}
}
bool Array::isValidIndex(int index) const
{
	if (index < capacity)
	{
		return true;
	}
	return false;
}
Array::Array(const Array& ref)
{
	capacity = ref.capacity;
	if (capacity == 0)
	{
		data = nullptr;
		return;
	}
	data = new int[capacity];
	copyArray(data, ref.data, capacity);
}
Array::Array(int count, ...)
{
	if (count <= 0)
	{
		data = nullptr;
		capacity = 0;
		return;
	}
	capacity = count;
	data = new int[count];
	va_list list;
	va_start(list, count);
	for (int i = 0; i < count; i = i + 1)
	{
		data[i] = va_arg(list, int);
	}
	va_end(list);
}
void Array::display() const
{
	if (capacity == 0)
		return;
	for (int i = 0; i < capacity - 1; i = i + 1)
	{
		cout << data[i];
		cout << ",";
	}
	cout << data[capacity - 1];
}
int& Array::getSet(int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	cout << "\nIndex is out of bound.";
	exit(0);
}
int& Array::getSet(int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	cout << "\nIndex is out of bound.";
	exit(0);
}
int Array::getCapacity() const
{
	return capacity;
}
Array::~Array()
{
	if (capacity == 0)
	{
		return;
	}
	delete[]data;
	data = nullptr;
	capacity = 0;
}
void Array :: reSize(int newCapacity)
{
	if (newCapacity <= 0)
	{
		this->~Array();
		return;
	}
	int* temp = new int[newCapacity];
	if (newCapacity >= capacity)
	{
		copyArray(temp, data, capacity);
	}
	else
	{
		copyArray(temp, data, newCapacity);
	}
	this->~Array();
	capacity = newCapacity;
	data = temp;
}