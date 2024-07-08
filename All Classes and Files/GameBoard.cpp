#include<iostream>
#include "GameBoard.h"
using namespace std;
//Private Functions:
void GameBoard::updateGameStatus()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)          //checking 3D WIN status
		{
			if ((data[0][i][j] < '1') || (data[0][i][j] > '9'))
			{
				if (data[0][i][j] == data[1][i][j] && data[1][i][j] == data[2][i][j])
				{
					gameStatus = WIN;
					return;
				}
			}
		}
	}

	int board = 0;
	while (board < 3)			//checking every board WIN status
	{
		if (checkBoardWinStatus(board))
		{
			gameStatus = WIN;
			return;
		}
		board++;
	}
	if (validMovesCount == 27)
		gameStatus = DRAW;
}



bool GameBoard::checkBoardWinStatus(int board)     //to check every board WIN status  ------------- (4)
{
	char lastSymbol;
	for (int j = 0; j < 3; j++) //checking down every col, changing rows
	{
		lastSymbol = data[board][0][j];
		int i = 1;
		while ((i < 3) && (lastSymbol == data[board][i][j]))
		{
			i++;
		}
		if (i == 3)
			return true;
	}
	for (int i = 0; i < 3; i++) //checking across every row, changing cols
	{
		lastSymbol = data[board][i][0];
		int j = 1;
		while ((j < 3) && (lastSymbol == data[board][i][j]))
		{
			j++;
		}
		if (j == 3)
			return true;
	}
	if ((data[board][0][0] == data[board][1][1]) && (data[board][1][1] == data[board][2][2])) //checking left diagonal
		return true;
	if ((data[board][0][2] == data[board][1][1]) && (data[board][1][1] == data[board][2][0])) //checking right diagonal
		return true;
	return false;
}




//Public Functions:
GameBoard::GameBoard()
{
	char ch = '1';
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++, ch++)
			{
				data[i][j][k] = ch;
			}
		}
		ch = '1';
	}
}

void GameBoard::displayBoard()
{
	cout << endl;
	for (int j = 0; j <= 2; j++)
	{
		for (int k = 0; k <= 2; k++)
		{
			cout << " ";
			for (int i = 0; i <= 2; i++)
			{
				cout << data[k][j][i];
				cout << "   ";
			}
			cout << "    ";
		}
		cout << endl;
	}
	cout << "-----------      -----------      -----------\n     1\t              2\t               3";
	cout << "\n\n";
}







void GameBoard::markBoard(int pos, char playerSymbol)
{
	int i = (pos / 10) - 1, j = (pos % 10) - 1;
	data[i][j / 3][j % 3] = playerSymbol;
	validMovesCount++;
	updateGameStatus();

	//updating gameStatus if there is no function of updateStatus the marks of the updateStatus shift here and there will be deduction of 1 marks for breaking automicity.
}



bool GameBoard::isValidPosition(int pos)
{
	if ((pos / 10) < 1 || (pos / 10) > 3)
		return false;
	return ((pos % 10) >= 1 && (pos % 10) <= 9);
}




bool GameBoard::isAlreadyMarked(int pos)
{
	int i = (pos / 10) - 1, j = (pos % 10) - 1;
	return (!(data[i][j / 3][j % 3] >= '1' && data[i][j / 3][j % 3] <= '9'));
}


int GameBoard::getValidMovesCount()
{
	return validMovesCount;
}

GameStatus GameBoard::getGameStatus()
{
	return gameStatus;
}
