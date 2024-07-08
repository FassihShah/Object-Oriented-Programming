#include<iostream>
#include"String.h"
#include"Set.h"
using namespace std;
bool Set::checkSubSet(const Set& s) const
{
	bool status = true;
	int i = 0;
	while (i < noOfElements && status)
	{
		if (!s.isMember(data.getSet(i)))
		{
			status = false;
		}
		i = i + 1;
	}
	return status;
}
void Set::copySetData(const Set& src) const
{
	for (int i = 0; i < src.noOfElements; i = i + 1)
	{
		data.getSet(i) = src.data.getSet(i);
	}
}
int Set::linearSearch(int elem) const
{
	bool status = false;
	int i = 0;
	while (i < noOfElements && !status)
	{
		status = (data.getSet(i) == elem ? true : false);
		i = i + 1;
	}
	return i - 1;
}
Set::Set(int cap):data(cap)
{
	noOfElements = 0;
}
int Set::getCardinality() const
{
	return data.getCapacity();
}
void Set::insert(int element)
{
	if (isMember(element))
	{
		return;
	}
	if (noOfElements == data.getCapacity())
	{
		reSize(data.getCapacity() + 1);
	}
	data.getSet(noOfElements) = element;
	noOfElements = noOfElements + 1;
}
bool Set::isMember(int val) const
{
	bool status = false;
	int i = 0;
	while (i < noOfElements && !status)
	{
		status = (data.getSet(i) == val ? true : false);
		i = i + 1;
	}
	return status;
}
void Set::remove(int element)
{
	if (!isMember(element))
		return;
	int index = linearSearch(element);
	data.getSet(index) = data.getSet(noOfElements - 1);
	noOfElements = noOfElements - 1;
}
void Set::print() const
{
	if (noOfElements == 0)
	{
		cout << "{ }";
		return;
	}
	cout << "{";
	for (int i = 0; i < noOfElements - 1; i = i + 1)
	{
		cout << data.getSet(i);
		cout << ",";
	}
	cout << data.getSet(noOfElements - 1) << "}";
}
void Set::reSize(int newCapacity)
{
	data.reSize(newCapacity);
	if (noOfElements > newCapacity)
		noOfElements = newCapacity;
}
Set Set::calcUnion(const Set& s2) const
{
	Set unSet(s2.noOfElements);
	unSet.copySetData(s2);
	unSet.noOfElements = s2.noOfElements;
	for (int i = 0; i < noOfElements; i = i + 1)
	{
		if (!unSet.isMember(data.getSet(i)))
		{
			unSet.insert(data.getSet(i));
		}
	}
	return unSet;
}
Set Set::calcIntersection(const Set& s2) const
{
	Set inSet;
	int i = 0;
	while (i < noOfElements)
	{
		if (s2.isMember(data.getSet(i)))
		{
			inSet.insert(data.getSet(i));
		}
		i = i + 1;
	}
	return inSet;
}
Set Set::calcDifference(const Set& s2) const
{
	Set diff;
	for (int i = 0; i < noOfElements; i = i + 1)
	{
		if (!s2.isMember(data.getSet(i)))
		{
			diff.insert(data.getSet(i));
		}
	}
	return diff;
}
Set Set::calcSymmetricDifference(const Set& s2) const
{
	Set un = calcUnion(s2);
	Set in = calcIntersection(s2);
	Set sym = un.calcDifference(in);
	return sym;
}
int Set::isSubSet(Set s2) const
{
	if (checkSubSet(s2) && noOfElements == s2.noOfElements)
	{
		return 2;
	}
	else if (checkSubSet(s2))
	{
		return 1;
	}
	else if (s2.checkSubSet(*this))
	{
		return -1;
	}
	return 0;
}
double getPower(double x, double power)
{
	double  answer;
	int cnt2 = 1;
	answer = 1;
	while (cnt2 <= power)
	{
		answer = answer * x;
		cnt2 = cnt2 + 1;
	}
	return answer;
}
long long int convertBase10ToBinary(int numInBase10)
{
	long long int  mode, divisor = 1;
	long long int numInTarget = 0;
	while (numInBase10 >= 2)
	{
		mode = numInBase10 % 2;
		numInBase10 = numInBase10 / 2;
		mode = mode * divisor + numInTarget;
		numInTarget = mode;
		divisor = divisor * 10;
	}
	numInTarget = numInBase10 * divisor + numInTarget;
	return numInTarget;
}
void Set::displayPowerSet() const
{
	int cnt = getPower(2,noOfElements);
	long long int base;
	for (int i=2; i <= cnt; i = i + 1)
	{
		base = convertBase10ToBinary(i);
		String s;
		s.setNumber(base);
		cout << "{";
		for (int i = 0; i < s.getLenght(); i = i + 1)
		{
			if (s.at(i) == 1)
				cout << s.at(i) << ",";
		}
		cout << "}";
	}
}