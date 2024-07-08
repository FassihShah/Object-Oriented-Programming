#include"Quiz.h"
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
int Quiz::idNo = 20;
Quiz::Quiz()
{
	qB = nullptr;
	noOfQuestions = 0;
	capacity = 0;
}
Quiz::Quiz(const Question& q)
{
	reSize(1);
	qB[0] = new Question(q);
	questIdGentr();
	noOfQuestions = 1;
}
Quiz::~Quiz()
{
	if (qB != nullptr)
	{
		qB = nullptr;
		noOfQuestions = 0;
		capacity = 0;
	}
}
void Quiz::reSize(int cap)
{
	if (cap <= 0)
	{
		this->~Quiz();
		return;
	}
	Question** temp = new Question * [cap];
	if (noOfQuestions != 0)
	{
		for (int i = 0; i < cap && i < noOfQuestions; i = i + 1)
		{
			temp[i] = qB[i];
		}
	}
	int i = (cap < noOfQuestions ? cap : noOfQuestions);
	this->~Quiz();
	qB = temp;
	noOfQuestions = i;
	capacity = cap;
}
void Quiz::questIdGentr()
{
	qB[noOfQuestions]->setQiD() = idNo;
	idNo = idNo + 1;
}
void Quiz::addQuestion(Question q)
{
	if (capacity == noOfQuestions)
		reSize(capacity + 1);
	qB[noOfQuestions] = new Question(q);
	questIdGentr();
	noOfQuestions = noOfQuestions + 1;
}
Quiz* Quiz::generateQuiz(int n)
{
	Quiz* q = new Quiz;
	for (int i = 0; i < noOfQuestions && i < n; i = i + 1)
	{
		q->addQuestion(*qB[i]);
	}
	return q;
}
Question Quiz::getQuestion(int id)
{
	int i = 0;
	while (qB[i]->getQiD() != id && i < noOfQuestions - 1)
	{
		i = i + 1;
	}
	if (i == noOfQuestions - 1)
		exit(0);
	return *qB[i];
}
void Quiz::printQuiz()
{
	for (int i = 0; i < noOfQuestions; i = i + 1)
	{
		qB[i]->display();
	}
}