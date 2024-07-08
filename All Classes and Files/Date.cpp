#include<iostream>
#include<iomanip>
#include"Date.h"
using namespace std;
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const String Date::monthsName[13] = { "","January","February","March","April","May","June","July","August","September","October","November","December"};
int Date::getMaxDays(int m) const
{
	int maxDays;
	maxDays = daysInMonth[m];
	if (m == 2 && isLeapYear())
		maxDays = 29;
	return maxDays;
}
bool Date::isValidDate(int d,int m,int y) const
{
	if ((y >= 1500 && y <= 3000) && (m >= 1 && m <= 12) && (d >= 1 && d <= getMaxDays(m)))
	{
		return true;
	}
	return false;
}
bool Date::isLeapYear() const
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}
Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}
Date::Date(int d,int m,int y):Date()
{
	setMonth(m);
	setDay(d);
	setYear(y);
}
void Date::setDate(int d, int m, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}
void Date::setDay(int d)
{
	if (d > 0 && d <= getMaxDays(month))
	{
		day = d;
	}
}
void Date::setMonth(int m)
{
	if (m > 0 && m <= 12 && day <= getMaxDays(m))
	{
		month = m;
	}
}
void Date::setYear(int y)
{
	if (y >= 1500 && y <= 3000)
	{
		year = y;
	}
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date :: incDay(int d = 1)
{
	day = day + d;
	int maxDays = getMaxDays(month);
	while (day > maxDays)
	{
		day = day - maxDays;
		incMonth(1);
		maxDays = getMaxDays(month);
	}
}
void Date::incMonth(int m = 1)
{
	month = m + month;
	while (month > 12)
	{
		month = month - 12;
		incYear(1);
	}
	int maxDays = getMaxDays(month);
	if (day > maxDays)
	{
		day = maxDays; 
	}
}
void Date::incYear(int y = 1)
{
	if (y > 0)
	{
		setYear(y + year);
	}
	if (day > getMaxDays(month))
	{
		day = 28;
	}
}
void Date::printFormat1() const
{
	cout << setw(2) << setfill('0') << day << "/";
	cout << setw(2) << month << "/";
	cout << year;
}
void Date::printFormat2() const
{
	monthsName[month].display();
	cout << " " << setw(2) << setfill('0') << day << ", " << year;
}
void Date::printFormat3() const
{
	cout << setw(2) << setfill('0') << day << "-";
	cout << monthsName[month].at(0) << monthsName[month].at(1) << monthsName[month].at(2) << "-";
	cout << year;
}
bool Date::isDateEqual(const Date& ref)
{
	if ((ref.getDay() == day) && (ref.getMonth() == month) && (ref.getYear() == year))
	{
		return true;
	}
	return false;
}
String Date::getDateInFormat1() const
{
	String temp,d,m,y;
	String sl{ '/' };
	String z{ '0' };
	d.setNumber(day);
	if (day < 10)
		d.insert(0, z);
	m.setNumber(month);
	if (month < 12)
		m.insert(0, z);
	y.setNumber(year);
	temp.insert(0, d);
	temp.insert(2, sl);
	temp.insert(3, m);
	temp.insert(5, sl);
	temp.insert(6, y);
	return temp;
}
String Date::getDateInFormat2() const
{
	String temp, d, y;
	String m{ monthsName[month] };
	String z{ '0' };
	String sp{ ' ' };
	String c{ ',' };
	d.setNumber(day);
	if (day < 10)
		d.insert(0, z);
	d.insert(0, sp);
	y.setNumber(year);
	temp.insert(0, m);
	temp.insert(temp.getLenght(), d);
	temp.insert(temp.getLenght(), c);
	temp.insert(temp.getLenght(), sp);
	temp.insert(temp.getLenght(), y);
	return temp;
}
String Date::getDateInFormat3() const
{
	String temp, d, y;
	String m{ monthsName[month]};
	m.reSize(3);
	String z{ '0' };
	String hy{ '-' };
	d.setNumber(day);
	if (day < 10)
		d.insert(0, z);
	y.setNumber(year);
	temp.insert(0, d);
	temp.insert(2, hy);
	temp.insert(3, m);
	temp.insert(6, hy);
	temp.insert(7, y);
	return temp;
}
void Date::inputDate()
{
	int d,m,y;
	cout << "\nEnter date in DD/MM/YY pattern : ";
	do
	{
		cin >> d;
		cin.ignore();
		cin >> m;
		cin.ignore();
		cin >> y;
		if (!isValidDate(d, m, y))
			cout << "\nPlease Enter a Valid Date ! : ";
	} 
	while (!isValidDate(d, m, y));
	setDate(d, m, y);
}