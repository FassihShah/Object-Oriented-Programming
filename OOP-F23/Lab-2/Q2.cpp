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
struct Date
{
    int day;
    int month;
    int year;
};
struct Token
{
    int tokenNumber;
    Date tokenDate;
    Time tokenTime;
};
struct ServiceCounter
{
    int counterNumber;
    Token list[100];
    int tokensCount;
};
void printDate(Date d)
{
    cout << "Date: " << d.day << ":" << d.month << ":" << d.year;
}
void printTime(Time t)
{
    int h = t.hours;
    char bound = 'A';
    if (h > 12)
    {
        h = h - 12;
        bound = 'P';
    }
    else if (h == 12)
    {
        bound = 'P';
    }
    else if (h == 0)
    {
        h = 12;
    }
    cout << "Time: " << h << ":" << t.minutes << ":" << t.seconds << " " << bound << 'M';
}
Token generateToken()
{
    static int counter = 1;
    Time currentTime;
    time_t t = time(0);
    tm curTime = *localtime(&t);
    currentTime.hours = curTime.tm_hour;
    currentTime.minutes = curTime.tm_min;
    currentTime.seconds = curTime.tm_sec;
    Date currentDate;
    currentDate.day = curTime.tm_mday;
    currentDate.month = curTime.tm_mon + 1;
    currentDate.year = curTime.tm_year + 1900;

    Token newToken;
    newToken.tokenNumber = counter;
    counter++;
    newToken.tokenDate = currentDate;
    newToken.tokenTime = currentTime;
    return newToken;
}
void printToken(Token t)
{
    cout << "\nToken # : " << t.tokenNumber;
    cout << '\n';
    printTime(t.tokenTime);
    cout << '\n';
    printDate(t.tokenDate);
}
void initializeServiceCounter(ServiceCounter& s)
{
    static int counter = 1;
    s.counterNumber = counter;
    counter++;
    s.tokensCount = 0;
}
void assignToken(ServiceCounter& s, Token t)
{
    s.list[s.tokensCount] = t;
    s.tokensCount++;
}
void serviceToken(ServiceCounter& s)
{
    if (s.tokensCount == 0)
        return;
    for (int i = 0; i < s.tokensCount - 1; i++)
    {
        s.list[i] = s.list[i + 1];
    }
    s.tokensCount--;
}
void printTokensAtServiceCounter(ServiceCounter s)
{
    cout << "\n*** Token Queue Waiting For Service @ Counter # " << s.counterNumber;
    if (s.tokensCount == 0)
    {
        cout << "\n\t\t --> Queue is Empty <--";
        return;
    }
    for (int i = 0; i < s.tokensCount; i++)
    {
        cout << '\n';
        printToken(s.list[i]);
    }
}
int main()
{
    ServiceCounter a, b;
    initializeServiceCounter(a);
    initializeServiceCounter(b);
    assignToken(a, generateToken());
    assignToken(b, generateToken());
    assignToken(a, generateToken());
    assignToken(a, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(a, generateToken());
    printTokensAtServiceCounter(a);
    serviceToken(a);
    printTokensAtServiceCounter(a);
    serviceToken(a);
    serviceToken(a);
    serviceToken(a);
    printTokensAtServiceCounter(a);
    serviceToken(b);
    printTokensAtServiceCounter(b);
    return 0;
}
