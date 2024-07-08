#ifndef CMATH_H
#define CMATH_H
#include "String.h"
class CMath
{
public:
	static float calcPower(int, int);
	static int calcGCD(int, int);
	static String toString(long long int);
	static long long int toInteger(String);
};
#endif 