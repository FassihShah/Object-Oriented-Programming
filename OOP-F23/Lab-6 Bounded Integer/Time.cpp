#include<iostream>
#include"Time.h"
using namespace std;
Time::Time(int h, int m, int s) :hour(0, 23), minute(0, 59), second(0, 59)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}
void Time::setHour(int h)
{
	hour.setValue(h);
}
void Time::setMinute(int m)
{
	minute.setValue(m);
}
void Time::setSecond(int s)
{
	second.setValue(s);
}
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}
int Time::getHour() const
{
	return hour.getValue();
}
int Time::getMinute() const
{
	return minute.getValue();
}
int Time::getSecond() const
{
	return second.getValue();
}

void Time::printTwentyFourHourFormat() const
{
	cout << hour.getValue() << ":" << minute.getValue() << ":" << second.getValue();
}

void Time::printTwelveHourFormat() const
{
	if (hour.getValue() == 0)
		cout << 12 << ":" << minute.getValue() << ":" << second.getValue() << " AM";
	else if(hour.getValue() < 12)
		cout << hour.getValue() << ":" << minute.getValue() << ":" << second.getValue() << " AM";
	else if(hour.getValue() == 12)
		cout << 12 << ":" << minute.getValue() << ":" << second.getValue() << " PM";
	else
		cout << hour.getValue() % 12 << ":" << minute.getValue() << ":" << second.getValue() << " PM";
}

void Time::incSec(int inc)
{
	incHour(inc / 3600);
	incMin(inc % 3600 / 60);
	if (second.getValue() + inc % 3600 % 60 > 59)
	{
		incMin(1);
	}
	second.increment(inc % 3600 % 60);
}

void Time::incMin(int inc)
{
	incHour(inc / 60);
	if (minute.getValue() + inc % 60 > 59)
	{
		incHour(1);
	}
	minute.increment(inc % 60);
}

void Time::incHour(int inc)
{
	hour.increment(inc);
}

void Time::decSec(int dec)
{
	decHour(dec / 3600);
	decMin(dec % 3600 / 60);
	if (second.getValue() - dec % 3600 % 60 < 0)
	{
		decMin(1);
	}
	second.decrement(dec % 3600 % 60);
}

void Time::decMin(int dec)
{
	decHour(dec / 60);
	if (minute.getValue() - dec % 60 < 0)
	{
		decHour(1);
	}
	minute.decrement(dec % 60);
}

void Time::decHour(int dec)
{
	hour.decrement(dec);
}
