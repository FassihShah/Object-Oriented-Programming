#include<iostream>
#include"QuizBank.h"
#include"Quiz.h"
using namespace std;
void QuizBank::quizApp()
{
	String opt1[4] = { {"test"},{"Paper"},{"Oral"},{"none"} };
	String opt2[4] = { {"test"},{"Paper"},{"Oral"},{"none"} };
	Question q1({ "What is a Lab ? " }, opt1, 10, 1);
	Question q2({ "What are Mids ? " }, opt1, 11, 2);
	Quiz q(q1);
	q.addQuestion(q2);
	cout << "\n\n\t\t\t\t  QUIZ APP";
	cout << "\n\t\t------------------------------------------";
	cout << "\n\t\t  Your Quiz is Starting.";
	cout << "\n\t\t------------------------------------------";
	do 
	{



	} while (1);
}