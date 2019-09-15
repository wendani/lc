void updateMinutes(int **grid, const int rowSize, const int colSize, const int i, const int j, int minutesToRot)
{
	if (i < 0 || i > rowSize - 1) {
		return;
	}

	if (j < 0 || j > colSize - 1) {
		return;
	}

	// empty cell
	if (grid[i][j] == 0) {
		return;
	}

	// step onto another rotten orange
	if (grid[i][j] == 2 && minutesToRot > 2) {
		return;

	// minutesToRot == 2 when we start from a new rotten orange
	if (minutesToRot == 2 || grid[i][j] == 1 || minutesToRot < grid[i][j]) {
		grid[i][j] = minutesToRot;

		minutesToRot++;
		// East
		updateMinutes(grid, rowSize, colSize, i, j + 1, minutesToRot);
		// South
		updateMinutes(grid, rowSize, colSize, i + 1, j, minutesToRot);
		// North
		updateMinutes(grid, rowSize, colSize, i - 1, j, minutesToRot);
		// West
		updateMinutes(grid, rowSize, colSize, i, j - 1, minutesToRot);
	}
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
	int i, j;
	if (!grid || !*grid || gridSize < 1 || !gridColSize || *gridColSize < 1) {
		return;
	}

	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 2) {
				updateMinutes(grid, gridSize, *gridColSize, i, j, 2);
			}
		}
	}

	int min = 2;
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 1) {
				return -1;
			}
			else if (grid[i][j] > min) {
				min = grid[i][j];
			}
		}
	}
	return min - 2;
}


/*
 * Example 1:
 *
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 * Example 2:
 *
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 *
 * Example 3:
 *
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 */
