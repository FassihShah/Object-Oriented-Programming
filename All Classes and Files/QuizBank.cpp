#include"QuizBank.h"
int QuizBank::qIdGen = 10;
QuizBank::QuizBank()
{
	qB = nullptr;
	noOfQuestions = 0;
	capacity = 0;
}
QuizBank::QuizBank(const Question& q)
{

}
void QuizBank::addQuestion(Question q)
{
	qB = new Question*(4);
	noOfQuestions = noOfQuestions + 1;
}