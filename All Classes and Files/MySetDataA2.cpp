#include<iostream>
int* data;
int capacity;
int noofelements = 0;
bool isUnique(int* set, int noe, int elem)
{
	bool status = true;
	for (int i = 0; i < noe; i = i + 1)
	{
		if ((set)[i] == elem)
		{
			status = false;
		}
	}
	return status;
}
void createSet(int** data, int capacity)
{
	*data = new int[capacity];
}
void displaySet(int* data, int noe)
{
	std :: cout << "{ ";
	for (int i = 0; i < noe - 1; i = i + 1)
	{
		std :: cout << (data)[i] << ", ";
	}
	std :: cout << (data)[noe - 1] << " }";
}
bool insertElement(int* set, int capacity , int* noe, int elem)
{
	bool status = true;
	if ((*noe == capacity) || (!isUnique(set,*noe,elem)))
	{
		status = false;
	}
	else
	{
		(set)[*noe] = elem;
		*noe = *noe + 1;
	}
	return status;
}
bool removeElement(int* set, int capacity, int* noe, int elem)
{
	for (int i = 0; i < *noe; i = i + 1)
	{
		if ((set)[i] == elem)
		{
			(set)[i] = (set)[*noe - 1];
			*noe = *noe - 1;
			return true;
		}
	}
	return false;
}
void freeSet(int ** set)
{
	delete[] *set;
	*set = nullptr;
}
int* intersection(int* set1, int set1noe, int* set2, int set2noe, int& intersectionsetnoe)
{
	intersectionsetnoe = 0;
	for (int i = 0; i < set1noe; i = i + 1)
	{
		for (int j = 0; j < set2noe; j = j + 1)
		{
			if ((set1)[i] == (set2)[j])
			{
				intersectionsetnoe = intersectionsetnoe + 1;
			}
		}
	}
	int i = 0;
	int* intset = new int[intersectionsetnoe];
	bool present = true;
	for (int j = 0; j < set2noe; j = j + 1)
	{
		present = true;
		for (int k = 0; k < set1noe; k = k + 1)
		{
			if ((set2)[j] == (set1)[k])
			{
				present = false;
			}
		}
		if (present == false)
		{
			intset[i] = (set2)[j];
			i = i + 1;
		}
	}
	return intset;
}