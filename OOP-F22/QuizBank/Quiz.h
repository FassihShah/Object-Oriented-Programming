#ifndef QUIZ_H
#define QUIZ_H
#include"Question.h"
class Quiz
{
	Question** qB;
	int noOfQuestions;
	int capacity;
	static int idNo;
	void questIdGentr();
public:
	Quiz();
	Quiz(const Question&);
	~Quiz();
	void reSize(int);
	void addQuestion(Question);
	Question getQuestion(int);
	Quiz* generateQuiz(int);
	void printQuiz();
};
#endif