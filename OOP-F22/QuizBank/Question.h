#ifndef QUESTION_H
#define QUESTION_H
#include"String.h"
class Question
{
	String statement;
	String options[4];
	int qID;
	int correctOption;
public:
	Question(const String&,String[4], int);
	int& setQiD();
	const int& getQiD() const;
	void display() const;
};
#endif