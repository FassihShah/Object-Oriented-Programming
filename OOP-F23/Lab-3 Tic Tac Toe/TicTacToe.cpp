#include<iostream>
#include "TicTacToe.h"
using namespace std;
//Private Functions:
bool TicTacToe::isValidPlayerSymbol(char symbol)
{
	return !(symbol >= '1' && symbol <= '9');
}

void TicTacToe::inputPlayers(char& player1Symbol, char& player2Symbol)
{
	bool validSymbol;
	do
	{
		cout << "Enter Player 1 Symbol : ";
		cin >> player1Symbol;
		validSymbol = isValidPlayerSymbol(player1Symbol);
		if (!validSymbol)
			cout << "Not a Valid Symbol!\n";
	} while (!validSymbol);

	do
	{
		cout << "Enter Player 2 Symbol : ";
		cin >> player2Symbol;
		validSymbol = isValidPlayerSymbol(player2Symbol);
		if (!validSymbol || player2Symbol == player1Symbol)
			cout << "Not a Valid Symbol!\n";
	} while (!validSymbol || player2Symbol == player1Symbol);
}

//Public Functions:
void TicTacToe::playGame()
{
	char player1Symbol;
	char player2Symbol;
	inputPlayers(player1Symbol, player2Symbol);

	GameBoard board;
	int pos;
	srand(time(0));
	int random = 1 + rand() % 2;
	PlayerTurn currentPlayer = (random == 1 ? FIRST_PLAYER : SECOND_PLAYER);
	char currentSymbol = (random == 1 ? player1Symbol : player2Symbol);

	while (board.getGameStatus() == IN_PROGRESS)
	{
		bool validMove = false;
		board.displayBoard();
		do
		{
			cout << "\nPlayer " << currentPlayer << " turn: Enter Cell #: ";
			cin >> pos;
			if (board.isValidPosition(pos) && !board.isAlreadyMarked(pos))
			{
				board.markBoard(pos, currentSymbol);
				validMove = true;
			}
		} while (!validMove);

		if (board.getGameStatus() == WIN)
		{
			board.displayBoard();
			cout << "\nGame Won by Player : " << currentPlayer << "\n";
		}
		else if (board.getGameStatus() == DRAW)
		{
			cout << "\nGame DRAW";
		}
		else
		{
			currentSymbol = (currentPlayer == FIRST_PLAYER ? player2Symbol : player1Symbol);
			currentPlayer = (currentPlayer == FIRST_PLAYER ? SECOND_PLAYER : FIRST_PLAYER);
		}
	}
}
