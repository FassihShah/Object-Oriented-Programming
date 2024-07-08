#ifndef QUIZ_BANK_H
#define QUIZ_BANK_H
#include"Question.h"
class QuizBank
{
	Question** qB;
	int noOfQuestions;
	int capacity;
	static int qIdGen;
public:
	QuizBank();
	QuizBank(const Question&);
	void addQuestion(Question);
};
#endif