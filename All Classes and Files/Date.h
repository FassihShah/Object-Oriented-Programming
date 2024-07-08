#ifndef DATE_H
#define DATE_H
#include"String.h"
class Date
{
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	static const String monthsName[13];
	bool isLeapYear() const;
	int getMaxDays(int) const;
	bool isValidDate(int,int,int) const;
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printFormat1() const;
	void printFormat2() const;
	void printFormat3() const;
	void incDay(int);
	void incMonth(int);
	void incYear(int);
	String getDateInFormat1() const;
	String getDateInFormat2() const;
	String getDateInFormat3() const; 
	bool isDateEqual(const Date&);
	void inputDate();
};
#endif