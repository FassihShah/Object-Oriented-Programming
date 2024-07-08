#ifndef SET_H
#define SET_H
#include"Array.h"
class Set
{
	Array data;
	int noOfElements;
	int linearSearch(int) const;
	void copySetData(const Set&) const;
	bool checkSubSet(const Set& s) const;
public:
	Set(int = 0);
	int getCardinality() const;
	void insert(int);
	void remove(int);
	bool isMember(int) const;
	void print() const;
	void reSize(int);
	int isSubSet(Set) const;
	Set calcUnion(const Set&) const;
	Set calcIntersection(const Set&) const;
	Set calcDifference(const Set& ) const;
	Set calcSymmetricDifference(const Set&) const;
	void displayPowerSet() const;
};
#endif
