#include"CMath.h"
float CMath::calcPower(int x, int pow)
{
	float answer = 1;
	int cnt = 1;
	while (cnt <= pow)
	{
		answer = answer * x;
		cnt = cnt + 1;
	}
	return answer;
}
int CMath::calcGCD(int a, int b)
{
	int cnt, base = b, divisor = a;
	while (divisor != 0)
	{
		cnt = base % divisor;
		base = divisor;
		divisor = cnt;
	}
	return base;
}
String CMath::toString(long long int num)
{
	String s;
	s.setNumber(num);
	return s;
}
long long int CMath::toInteger(String s)
{
	return s.convertToInteger();
}