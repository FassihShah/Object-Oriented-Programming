#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
using namespace std;


enum PlayerTurn { FIRST_PLAYER = 1, SECOND_PLAYER = 2 };
enum GameStatus { DRAW, WIN, IN_PROGRESS };

class GameBoard
{
private:
	char data[3][3][3]; // Array used for board 
	int validMovesCount = 0;
	GameStatus gameStatus = IN_PROGRESS;
	void updateGameStatus();
	bool checkBoardWinStatus(int);
public:
	GameBoard();
	void displayBoard();
	void markBoard(int pos, char playerSymbol);
	bool isValidPosition(int pos);
	bool isAlreadyMarked(int pos);
	int getValidMovesCount();
	GameStatus getGameStatus();
};

#endif