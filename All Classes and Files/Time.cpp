#include<iostream>
#include<iomanip>
#include "Time.h"
using namespace std;
Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}
bool Time::isValidTime(int h, int m, int s) const
{
	if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
	{
		return true;
	}
	return false;
}
void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		hour = h;
	}
}
void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
	{
		minute = m;
	}
}
void Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
	{
		second = s;
	}
}
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}
int Time::getHour()
{
	return hour;	
}
int Time::getMinute()
{
	return minute;
}
int Time::getSecond()
{
	return second;
}
void Time::incHour(int h)
{
	hour = (hour + h) % 24;
}
void Time::incMinute(int m)
{
	incHour((minute + m) / 60);
	minute = (minute + m) % 60;
}
void Time::incSecond(int s)
{
	incMinute((second + s) / 60);
	second = (second + s) % 60;
}
void Time::printTwentyFourHourFormat()
{
	cout << setw(2) << setfill('0') << hour << ":";
	cout << setw(2) << minute << ":";
	cout << setw(2) << second;
}
void Time::printTwelveHourFormat()
{
	int h = hour;
	char bound = 65;
	if (hour > 12)
	{
		h = h - 12;
		bound = 80;
	}
	else if (hour == 12)
	{
		bound = 80;
	}
	else if (hour == 0)
	{
		h = 12;
	}
	cout << setw(2) << setfill('0') << h << ":";
	cout << setw(2) << minute << ":";
	cout << setw(2) << second << " " << bound << "M";
}
void Time::inputTime()
{
	int h,m,s;
	cout << "\nEnter Time in HH:MM:SS pattern : ";
	do
	{
		cin >> h;
		cin.ignore();
		cin >> m;
		cin.ignore();
		cin >> s;
		if (!isValidTime(h, m, s))
		{
			cout << "\nEnter a valid Time : ";
		}
	}
	while (!isValidTime(h, m, s));
	setTime(h, m, s);
}