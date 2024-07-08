#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include<iostream>
using namespace std;
class BigNumber
{
	char* number;
	int numberLength;
	int getStartingZeros(const char*) const;
	int getStrLength(const char*);
	void copyStr(const char*, char*);
	int compare(const BigNumber&) const;
public:
	BigNumber(const char*);
	BigNumber(const BigNumber&);
	~BigNumber();
	void setNumber(const char*);
	void print() const;
	BigNumber operator = (const BigNumber&);
	BigNumber operator + (const BigNumber&) const;
	BigNumber operator - (const BigNumber&) const;
	BigNumber operator * (const BigNumber&) const;
	bool operator == (const BigNumber&) const;
	bool operator > (const BigNumber&) const;
	bool operator < (const BigNumber&) const;
	bool operator >= (const BigNumber&) const;
	bool operator <= (const BigNumber&) const;
	bool operator != (const BigNumber&) const;
};
#endif 
//#ifndef BIG_NUMBER_H
//#define BIG_NUMBER_H
//#include<iostream>
//using namespace std;
//
//class BigNumber
//{
//	char* number;
//	int numberLength;
//	int getStrLength(const char* str);
//	void copyStr(const char* source, char* destination);
//	int compare(const BigNumber& ref)const;
//
//public:
//	BigNumber(const char*);
//	BigNumber(const BigNumber&);
//	~BigNumber();
//	void setNumber(const char* num);
//	void print() const;
//	BigNumber operator = (const BigNumber&);
//	BigNumber operator + (const BigNumber&) const;
//	BigNumber operator - (const BigNumber& other) const;
//	BigNumber operator* (const BigNumber& other) const;
//	bool operator == (const BigNumber& other) const;
//	bool operator > (const BigNumber& other) const;
//	bool operator < (const BigNumber& other) const;
//	bool operator >= (const BigNumber& other) const;
//	bool operator <= (const BigNumber& other) const;
//	bool operator != (const BigNumber& other) const;
//};
//#endif // !BIG_NUMBER_H
