#include<iostream>
using namespace std;
#include"GomukoBoard.h"
#include"GomukoGame.h"
void GomukoGame::playGame()
{
	GomukoBoard board;
	PlayerTurn currentPlayer = FIRST_PLAYER;
	GameStatus gameStatus = IN_PROGRESS;
	int r, c;
	board.displayBoard();
	PlayerSymbol currentSymbol = FIRST_PLAYER_SYMBOL;
	while (gameStatus == IN_PROGRESS)
	{
		do
		{
			bool status = false;
			board.displayBoard();
			cout << "\nPlayer " << currentPlayer << " Position (row, column) : ";
			cin >> r;
			cin.ignore();
			cin >> c;
			if (board.isValidPlace(r, c) == 1)
			{
				board.markBoard(r, c);
				status = true;
			}
			else if (board.isValidPlace(r, c) == 0)
			{
				cout << "\nNumbers are not on gameboard ";
			}
			else
			{
				cout << "\nPlace is already Marked";
			}
		} while (status == false);
		gameStatus = board.getGameStatus();
		if (gameStatus == FIRST_PLAYER_WIN || gameStatus==SECOND_PLAYER_WIN)
		{
			cout << "\nPlayer " << currentPlayer << " WON !";
		}
		else if (gameStatus == DRAW)
		{
			cout << "\nGame has DRAWN";
		}
		else
		{
			currentPlayer = (currentPlayer == FIRST_PLAYER ? SECOND_PLAYER : FIRST_PLAYER);
		}
	}
}