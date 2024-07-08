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
	void setQID();
	void getQID();
};

#endif
