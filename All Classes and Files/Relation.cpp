#include<iostream>
#include"Relation.h"
using namespace std;
Relation::Relation(Set s):setA(s)
{
	capacity = 0;
	noOfOrderedPair = 0;
	orderedPairList = nullptr;
}
Relation::Relation(const Relation& ref) :setA(ref.setA)
{
	capacity = ref.capacity;
	noOfOrderedPair = ref.noOfOrderedPair;
	orderedPairList = new OrderedPair[noOfOrderedPair];
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		orderedPairList[i] = ref.orderedPairList[i];
	}
}
Relation::~Relation()
{
	if (orderedPairList != nullptr)
	{
		delete[]orderedPairList;
		capacity = 0;
		noOfOrderedPair = 0;
		orderedPairList = nullptr;
	}
}
void Relation::reSize()
{
	OrderedPair* temp = new OrderedPair[capacity + 1];
	int i;
	if (noOfOrderedPair != 0)
	{
		for (i = 0; i < noOfOrderedPair; i = i + 1)
		{
			temp[i]=orderedPairList[i];
		}
	}
	this->~Relation();
	capacity = capacity + 1;
	orderedPairList = temp;
}
void Relation::shrink()
{
	OrderedPair* temp = new OrderedPair[capacity - 1];
	int i;
	if (noOfOrderedPair != 0)
	{
		for (i = 0; i < capacity - 1, i < noOfOrderedPair; i = i + 1)
		{
			temp[i] = orderedPairList[i];
		}
	}
	int t = (noOfOrderedPair == capacity ? noOfOrderedPair - 1 : noOfOrderedPair);
	this->~Relation();
	capacity = capacity - 1;
	orderedPairList = temp;
	noOfOrderedPair = t;
}
bool Relation::isValidOrderedPair(const OrderedPair&pair)
{
	if (setA.isMember(pair.atA()) && setA.isMember(pair.atB()))
	{
		return true;
	}
	return false;
}
bool Relation::isUnique(const OrderedPair& pair)
{
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		if (orderedPairList[i].atA() == pair.atA() && orderedPairList[i].atB() == pair.atB())
			return false;
	}
	return true;
}
void Relation::insert(const OrderedPair& ref)
{
	if (capacity == noOfOrderedPair)
		reSize();
	if (isValidOrderedPair(ref) && isUnique(ref))
	{
		orderedPairList[noOfOrderedPair] = ref;
	}
}
void Relation::remove(const OrderedPair& ref)
{
	if (noOfOrderedPair == 0 || isUnique(ref))
		return;
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		if (orderedPairList[i].atA() == ref.atA() && orderedPairList[i].atB() == ref.atB())
		{
			orderedPairList[i] = orderedPairList[noOfOrderedPair];
			shrink();
		}
	}
}
bool Relation::compare(const Relation& ref) const
{
	if (noOfOrderedPair != ref.noOfOrderedPair)
		return false;
	bool flag = true;
	bool status = true;
	for (int i = 0; i < noOfOrderedPair, status=true; i = i + 1)
	{
		flag = true;
		for (int j = 0; j < noOfOrderedPair, flag = true; j = j + 1)
		{
			if (orderedPairList[i].atA() == ref.orderedPairList[j].atA())
			{
				flag = false;
				status = true;
			}
			else
			{
				status = false;
			}
		}
	}
	return status;
}
int Relation::getCardinality() const
{
	return noOfOrderedPair;
}
bool Relation::isReflexive() const
{
	char ch;
	int count = 0;
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		if (orderedPairList[i].atA() == orderedPairList[i].atB())
		{
			count = count + 1;
		}
	}
	if (count == setA.getCardinality())
	{
		return true;
	}
	return false;
}
void Relation::print() const
{
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		cout << "(" << orderedPairList[i].atA() << "," << orderedPairList[i].atB() << ")";
		cout << " ";
	}
}