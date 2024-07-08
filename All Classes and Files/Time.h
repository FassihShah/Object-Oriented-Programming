#ifndef TIME_H
#define TIME_H
class Time
{
	int hour;
	int minute;
	int second;
	bool isValidTime(int h, int m, int s) const;
public:
	Time(int = 1, int = 1, int = 1);
	void setHour(int = 1);
	void setMinute(int);
	void setSecond(int);
	void setTime(int, int , int);
	int getHour();
	int getMinute();
	int getSecond();
	void incHour(int = 1);
	void incMinute(int = 1);
	void incSecond(int = 1);
	void printTwentyFourHourFormat();
	void printTwelveHourFormat();
	void inputTime();
};
#endif