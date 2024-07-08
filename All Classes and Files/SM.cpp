#include<iostream>
#include"SM.h"
using namespace std;
SM::SM(int s) :Matrix(s, s)
{
}
SM::SM(const SM& ref) :Matrix(ref)
{

}
SM::SM(const Matrix& m) :Matrix(m)
{
}
SM SM::transpose() const
{
	SM temp(Matrix::transpose());
	return temp;
}
SM SM::add(const SM& ref) const
{
	SM temp(Matrix::add(ref));
	return temp;
}
SM SM::multiply(const SM& ref) const
{
	SM temp(Matrix::multiply(ref));
	return temp;
}
void SM::reSize(int s)
{
	Matrix::reSize(s, s);
}