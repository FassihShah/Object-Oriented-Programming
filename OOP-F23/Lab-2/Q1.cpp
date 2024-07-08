#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime> 
using namespace std;
struct Time
{
	int hours;
	int minutes;
	int seconds;
};

Time getTimeDifference(Time t1)
{
	Time currentTime;
	time_t t = time(0);
	tm curTime = *localtime(&t);
	currentTime.hours = curTime.tm_hour;
	currentTime.minutes = curTime.tm_min;
	currentTime.seconds = curTime.tm_sec;

	currentTime.seconds = currentTime.seconds - t1.seconds;
	currentTime.minutes = currentTime.minutes - t1.minutes;
	currentTime.hours = currentTime.hours - t1.hours;
	if (currentTime.seconds < 0)
	{
		currentTime.seconds = currentTime.seconds + 60;
		currentTime.minutes--;
	}
	if (currentTime.minutes < 0)
	{
		currentTime.minutes = currentTime.minutes + 60;
		currentTime.hours--;
	}
	if (currentTime.hours < 0)
	{
		currentTime.hours = currentTime.hours + 24;
	}
	return currentTime;
}

int main()
{
	Time t = { 10, 15, 50 };
	Time diffTime = getTimeDifference(t);
	cout << diffTime.hours << " : " << diffTime.minutes << " : " << diffTime.seconds << endl;
	return 0;
}
