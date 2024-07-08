#ifndef ARRAY_h
#define ARRAY_h
class Array
{
	int* data;
	int size;
	bool isValidIndex(int) const;
	void copyArray(int* const, const int* const, int);
public:
	Array(const Array&);
	Array(int = 0, ...);
	void display() const;
	~Array();
	int& getSet(int);
	int& getSet(int) const;
	int getCapacity() const;
	void reSize(int );
};
#endif
