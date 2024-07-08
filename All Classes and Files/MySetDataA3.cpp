#include<iostream>
using namespace std;
struct Set
{
	int* data;
	int noOfElements = 0;
	int capacity;
};
bool isUnique(Set s, int element)
{
	bool status = true;
	for (int i = 0; i < s.noOfElements; i = i + 1)
	{
		if ((s.data)[i] == element)
		{
			status = false;
		}
	}
	return status;
}
void createSet(Set* s, int size)
{
	s->capacity = size;
	s->noOfElements = 0;
	(*s).data = new int[size];
}
void displaySet(Set s)
{
	cout << "{ ";
	for (int i = 0; i < (s.noOfElements) - 1; i = i + 1)
	{
		cout << (s).data[i] << ", ";
	}
	cout << (s.data)[(s.noOfElements) - 1] << " }";
}
bool insertElement(Set* s, int element)
{
	bool status = true;
	if ((s->noOfElements) == (s->capacity) || (!isUnique(*s, element)))
	{
		status = false;
	}
	else
	{
		(s->data)[s->noOfElements] = element;
		s->noOfElements = s->noOfElements + 1;
	}
	return status;
}
bool removeElement(Set* s, int elem)
{
	for (int i = 0; i < (s->noOfElements); i = i + 1)
	{
		if ((s->data)[i] == elem)
		{
			(s->data)[i] = (s->data)[(s->noOfElements) - 1];
			(s->noOfElements) = (s->noOfElements) - 1;
			return true;
		}
	}
	return false;
}
void freeSet(Set* s)
{
	delete[](s->data);
	(s->data) = nullptr;
}
Set intersection(Set s1, Set s2)
{
	int setSize = 0;
	for (int i = 0; i < (s1).noOfElements; i = i + 1)
	{
		for (int j = 0; j < (s2).noOfElements; j = j + 1)
		{
			if (s1.data[i] == s2.data[j])
			{
				setSize = setSize + 1;
			}
		}
	}
	int i = 0;
	Set intSet;
	createSet(&intSet, setSize);
	intSet.noOfElements = setSize;
	bool present = true;
	for (int j = 0; j < (s2).noOfElements; j = j + 1)
	{
		present = true;
		for (int k = 0; k < (s1).noOfElements; k = k + 1)
		{
			if ((s2.data)[j] == (s1.data)[k])
			{
				present = false;
			}
		}
		if (present == false)
		{
			((intSet).data)[i] = ((s2).data)[j];
			i = i + 1;
		}
	}
	return intSet;
}
Set getUnion(Set s1, Set s2)
{
	int count = 0;
	for (int i = 0; i < s1.noOfElements; i = i + 1)
	{
		for (int j = 0; j < s2.noOfElements; j = j + 1)
		{
			if ((s1.data)[i] == (s2.data)[j])
			{
				count = count + 1;
			}
		}
	}
	int i = 0;
	count = (s1.noOfElements + s2.noOfElements) - count;
	Set unSet;
	createSet(&unSet, count);
	unSet.noOfElements = count;
	bool present;
	while (i < s1.noOfElements)
	{
		(unSet.data)[i] = s1.data[i];
		i = i + 1;
	}
	for (int j = 0; j < s2.noOfElements; j = j + 1)
	{
		present = false;
		for (int k = 0; k < s1.noOfElements; k = k + 1)
		{
			if (s2.data[j] == s1.data[k])
			{
				present = true;
			}
		}
		if (present == false)
		{
			unSet.data[i] = s2.data[j];
			i = i + 1;
		}
	}
	return unSet;
}