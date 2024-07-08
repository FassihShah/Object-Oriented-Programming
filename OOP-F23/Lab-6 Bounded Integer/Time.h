#ifndef TIME_H
#define TIME_H
#include"BoundedInteger.h"
class Time
{
	BoundedInteger hour;
	BoundedInteger minute;
	BoundedInteger second;
public:
	Time(int = 0, int = 0, int = 0);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void setTime(int, int , int);
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	void incHour(int = 1);
	void incMin(int = 1);
	void incSec(int = 1);
	void decHour(int = 1);
	void decMin(int = 1);
	void decSec(int = 1);
	void printTwentyFourHourFormat() const;
	void printTwelveHourFormat() const;
};
#endif