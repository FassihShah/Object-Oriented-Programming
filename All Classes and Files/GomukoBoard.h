#ifndef GOMUKO_BOARD_H
#define GOMUKO_BOARD_H
enum PlayerTurn { FIRST_PLAYER = 'W', SECOND_PLAYER = 'B' };
enum PlayerSymbol { FIRST_PLAYER_SYMBOL = 'W', SECOND_PLAYER_SYMBOL = 'B' };
enum GameStatus { FIRST_PLAYER_WIN, SECOND_PLAYER_WIN, DRAW, IN_PROGRESS };
#define ROWS 19
#define COLS 19
class GomukoBoard
{
	char board[ROWS][COLS];
	GameStatus gameStatus = IN_PROGRESS;
	PlayerTurn currentPlayer = FIRST_PLAYER;
	int validMovesCount = 0;
	int isValidPlace(int r, int c);
	void updateGameStatus(int r, int c);
public:
	GomukoBoard();
	void displayBoard();
	int markBoard(int r, int c);
	GameStatus getGameStatus();
	int getValidMovesCount();
	PlayerTurn getCurrentPlayer();
	void switchPlayerTurn();
};

#endif
