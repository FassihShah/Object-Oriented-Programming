#include<iostream>
using namespace std;
#include "GomukoBoard.h"
void GomukoBoard::updateGameStatus(int r, int c)
{
	bool status;
	for (int i = 0, j = r; i < 5, j < 19; i = i + 1, j = j + 1)
	{
		if (board[j][c] != currentPlayer)
		{
			status = false;
		}
	}
	for (int i = 0, j = r; i < 5, j >= 0; i = i + 1, j = j - 1)
	{
		if (board[j][c] != currentPlayer)
		{
			status = false;
		}
	}
	for (int i = 0, j = c; i < 5, j < 19; i = i + 1, j = j + 1)
	{
		if (board[r][j] != currentPlayer)
		{
			status = false;
		}
	}
	for (int i = 0, j = c; i < 5, j >= 0; i = i + 1, j = j - 1)
	{
		if (board[r][j] != currentPlayer)
		{
			status = false;
		}
	}
	for (int i = 0, j = c, k=r; i < 5, j < 19, j>=0; i = i + 1, j = j + 1,k=k+1)
	{
		if (board[k][j] != currentPlayer)
		{
			status = false;
		}
	}
	for (int i = 0, j = c, k = r; i < 5, j >= 0, j < 19; i = i + 1, j = j - 1, j = j - 1)
	{
		if (board[k][j] != currentPlayer)
		{
			status = false;
		}
	}
	if (status == true)
	{
		if (currentPlayer == FIRST_PLAYER)
		{
			gameStatus = FIRST_PLAYER_WIN;
		}
		else
		{
			gameStatus = SECOND_PLAYER_WIN;
		}
	}
}
int GomukoBoard::isValidPlace(int r, int c)
{
	if (r > ROWS || c > COLS)
	{
		return 0;
	}
	else if (board[r-1][c-1] == '.')
	{
		return -1;
	}
	return 1;
}
GomukoBoard :: GomukoBoard()
{
	for (int i = 0; i < 19; i = i + 1)
	{
		for (int j = 0; j < 19; j = j + 1)
		{
			board[i][j] = '.';
		}
	}
}
void GomukoBoard :: displayBoard()
{
	int cnt = 1;
	cout << "    ";
	for (int i = 1; i <= 19; i = i + 1)
	{
		if (i < 10)
			cout << i << "  ";
		else
			cout << i << " ";
	}
	cout << endl ;
	for (int i = 0; i < ROWS; i = i + 1)
	{
		if (cnt < 10)
		{
			cout <<" ";
		}
		cout << cnt << "  ";
		for (int j = 0; j < COLS; j = j + 1)
		{
			cout << board[i][j];
			if (j >= 10)
			{
				cout << "  ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
		cnt = cnt + 1;
	}
}
int GomukoBoard :: markBoard(int r, int c)
{
	int i;
	bool status = true;
	if (isValidPlace(r, c))
	{
		board[r-1][c-1] = currentPlayer;
		i= 1;
	}
	else
	{
		i= isValidPlace(r, c);
	}
	updateGameStatus(r, c);
	if (getGameStatus == IN_PROGRESS)
	{
		switchPlayerTurn();
	}
	return i;
}
int GomukoBoard::getValidMovesCount()
{
	return validMovesCount;
}
void GomukoBoard::switchPlayerTurn()
{
	currentPlayer = SECOND_PLAYER;
}
PlayerTurn GomukoBoard::getCurrentPlayer()
{
	return currentPlayer;
}
GameStatus GomukoBoard :: getGameStatus()
{
	return gameStatus();
}