bool _exist(char **board, int rowSize, int columnSize, int row, int column, char *word)
{
	if (!*word)
		return true;

	if (row < 0 || row > rowSize - 1)
		return false;

	if (column < 0 || column > columnSize - 1)
		return false;

	// reach here when *word is not '\0'
	if (*word != board[row][column])
		return false;

	board[row][column] = 0;
	if (_exist(board, rowSize, columnSize, row, column + 1, word + 1)
		|| _exist(board, rowSize, columnSize, row + 1, column, word + 1)
		|| _exist(board, rowSize, columnSize, row, column - 1, word + 1)
		|| _exist(board, rowSize, columnSize, row - 1, column, word + 1)) {
		board[row][column] = *word;
		return true;
	}

	board[row][column] = *word;
	return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
	int i, j;

	if (!board || !*board || !boardColSize || !word) {
		return false;
	}

	for (i = 0; i < boardSize; i++)
		for (j = 0; j < *boardColSize; j++) {
			if (_exist(board, boardSize, *boardColSize, i, j, word)) {
				return true;
			}
		}

	return false;
}
