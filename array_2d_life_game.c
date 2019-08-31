static int countNeighbors(int **board, const int row, const int column, int i, int j)
{
	int cnt = 0;

	if (i >= 1) {
		if (j >= 1 && board[i - 1][j - 1] > 0) {
			cnt++;
		}
		if (j < column - 1 && board[i - 1][j + 1] > 0) {
			cnt++;
		}
		if (board[i - 1][j] > 0) {
			cnt++;
		}
	}

	if (i < row - 1) {
		if (j >= 1 && board[i + 1][j - 1] > 0) {
			cnt++;
		}
		if (j < column - 1 && board[i + 1][j + 1] > 0) {
			cnt++;
		}
		if (board[i + 1][j] > 0) {
			cnt++;
		}
	}

	if (j >= 1 && board[i][j - 1] > 0) {
		cnt++;
	}

	if (j < column - 1 && board[i][j + 1] > 0) {
		cnt++;
	}

	return cnt;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
	if (!board || !*board || boardSize < 1 || !boardColSize || *boardColSize < 1) {
		return;
	}

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			int cnt = countNeighbors(board, boardSize, *boardColSize, i, j);

			if (board[i][j] == 1) {
				board[i][j] = cnt;
			}
			else {
				assert(board[i][j] == 0);
				if (cnt == 3) {
					board[i][j] = -1;
				}
			}
		}
	}

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			if (board[i][j] == -1) {
				board[i][j] = 1;
			}
			else if (board[i][j] == 1 || board[i][j] > 3) {
				board[i][j] = 0;
			}
			else if (board[i][j] == 2 || board[i][j] == 3) {
				board[i][j] = 1;
			}
		}
	}
}


/*
 * Example:
 *
 * Input:
 * [
 *   [0,1,0],
 *   [0,0,1],
 *   [1,1,1],
 *   [0,0,0]
 * ]
 * Output:
 * [
 *   [0,0,0],
 *   [1,0,1],
 *   [0,1,1],
 *   [0,1,0]
 * ]
 */
