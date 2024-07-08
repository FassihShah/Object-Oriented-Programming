#ifndef MY_SET_DATA
#define MY_SET_DATA
struct Set
{
	int* data;
	int noOfElements = 0;
	int capacity;
};
bool isUnique(Set , int);
void createSet(Set* , int );
void displaySet(Set );
bool insertElement(Set* , int );
bool removeElement(Set* , int );
void freeSet(Set* );
Set intersection(Set , Set );
Set getUnion(Set , Set );
#endif