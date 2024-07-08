#ifndef BOUNDED_INTEGER_H
#define BOUNDED_INTEGER_H
class BoundedInteger
{
	int lowerBound;
	int upperBound;
	int value;
	bool isValidBound(int, int) const;
public:
	BoundedInteger();
	BoundedInteger(int, int);
	BoundedInteger(int, int, int);
	void setValue(int);
	int getValue() const;
	int getUpperBound() const;
	int getLowerBound() const;
	bool isValidValue(int) const;
	void increment(int = 1);
	void decrement(int = 1);
};
#endif