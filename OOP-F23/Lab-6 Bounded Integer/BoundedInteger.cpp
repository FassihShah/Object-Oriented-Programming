#include<iostream>
#include"BoundedInteger.h"
bool BoundedInteger::isValidBound(int lb, int ub) const
{
	if (lb >= INT_MIN && ub <= INT_MAX && lb <= ub)
		return true;
	else
		return false;
}
BoundedInteger::BoundedInteger()
{
	lowerBound = INT_MIN;
	upperBound = INT_MAX;
	value = lowerBound;
}
BoundedInteger::BoundedInteger(int lb, int ub) :BoundedInteger()
{
	if (!isValidBound(lb, ub))
		return;
	lowerBound = lb;
	upperBound = ub;
	value = lb;
}
BoundedInteger::BoundedInteger(int lb, int ub, int val) :BoundedInteger(lb, ub)
{
	setValue(val);
}
void BoundedInteger::setValue(int val)
{
	if (isValidValue(val))
		value = val;
}
int BoundedInteger::getValue() const
{
	return value;
}
int BoundedInteger::getUpperBound() const
{
	return upperBound;
}
int BoundedInteger::getLowerBound() const
{
	return lowerBound;
}
bool BoundedInteger::isValidValue(int val) const
{
	return (val >= lowerBound && val <= upperBound);
}
void BoundedInteger::increment(int inc)
{
	value += inc;
	if (value > upperBound)
	{
		int range = upperBound - lowerBound + 1;
		value = lowerBound + ((value - upperBound - 1) % range);
	}
}
void BoundedInteger::decrement(int dec)
{
	value -= dec;
	if (value < lowerBound)
	{
		int range = upperBound - lowerBound + 1;
		value = upperBound - ((lowerBound - value - 1) % range);
	}
}