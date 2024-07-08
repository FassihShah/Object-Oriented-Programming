#include<iostream>
#include"Question.h"
using namespace std;
Question::Question(const String& q,String opt[4], int ans)
{
	statement = q;
	options[0] = opt[0];
	options[1] = opt[1];
	options[2] = opt[2];
	options[3] = opt[3];
	correctOption = ans;
}
int& Question::setQiD()
{
	return qID;
}
const int& Question::getQiD() const
{
	return qID;
}
void Question::display() const
{
	cout << endl;
	statement.display();
	cout << "\n i)   ";
	options[0].display();
	cout << "        ii)  ";
	options[1].display();
	cout << "\n iii) ";
	options[2].display();
	cout << "        iv)  ";
	options[3].display();
	cout << endl;
}