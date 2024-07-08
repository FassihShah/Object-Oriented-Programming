#include<iostream>
int* data;
int capacity;
int noOfElements = 0;
bool isUnique(int element)
{
	bool status = true;
	for (int i = 0; i < noOfElements; i = i + 1)
	{
		if (data[i] == element)
		{
			status = false;
		}
	}
	return status;
}
void createSet(int setSize)
{
	data = new int[setSize];
	capacity = setSize;
}
void insertElement(int element)
{
	if (isUnique(element) && capacity>noOfElements)
	{
		(data)[noOfElements] = element;
		noOfElements = noOfElements + 1;
	}
}
void removeElement(int element)
{
	for (int i = 0; i < noOfElements; i = i + 1)
	{
		if ((data)[i] == element)
		{
			(data)[i] = (data)[noOfElements - 1];
			noOfElements = noOfElements - 1;
		}
	}
}
void displaySet()
{
	std::cout << "{ ";
	for (int i = 0; i < noOfElements - 1; i = i + 1)
	{
		std::cout << (data)[i] << ", ";
	}
	std::cout << (data)[noOfElements - 1] << " }";
}
void freeSet()
{
	delete[] data;
	data = nullptr;
}