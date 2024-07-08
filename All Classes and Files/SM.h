#pragma once
#include"Matrix.h"
class SM:Matrix
{
	SM(const Matrix&);
public:
	SM(int = 0);
	SM(const SM&);
	SM transpose() const;
	SM add(const SM&) const;
	SM multiply(const SM&) const;
	void reSize(int);
};