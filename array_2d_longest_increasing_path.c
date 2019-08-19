static const int visited = -32768;

static int increasingPathLength(int **matrix, const int rowSize, const int colSize, int row, int column, const int prevVal)
{
	int currVal, maxLen, len;

	if (row < 0 || row > rowSize - 1) {
		return 0;
	}

	if (column < 0 || column > colSize - 1) {
		return 0;
	}

	if (matrix[row][column] == visited) {
		return 0;
	}

	if (matrix[row][column] <= prevVal) {
		return 0;
	}

	// reach here when prevVal < matrix[row][column]
	currVal = matrix[row][column];
	matrix[row][column] = visited;

	maxLen = 0;
	// east
	len = increasingPathLength(matrix, rowSize, colSize, row, column + 1, currVal);
	if (len > maxLen) {
		maxLen = len;
	}
	// south
	len = increasingPathLength(matrix, rowSize, colSize, row + 1, column, currVal);
	if (len > maxLen) {
		maxLen = len;
	}
	// west
	len = increasingPathLength(matrix, rowSize, colSize, row, column - 1, currVal);
	if (len > maxLen) {
		maxLen = len;
	}
	// north
	len = increasingPathLength(matrix, rowSize, colSize, row - 1, column, currVal);
	if (len > maxLen) {
		maxLen = len;
	}

	matrix[row][column] = currVal;

	return maxLen + 1;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
	int i, j;
	int maxLen;

	if (!matrix || !*matrix || matrixSize < 1 || !matrixColSize || *matrixColSize < 1) {
		return 0;
	}

	maxLen = 0;
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < *matrixColSize; j++) {
			int len = increasingPathLength(matrix, matrixSize, *matrixColSize, i, j, matrix[i][j] - 1);
			if (len > maxLen) {
				maxLen = len;
			}
		}
	}
	return maxLen;
}

/*
 * Example 1:
 *
 * Input: nums =
 * [
 *   [9,9,4],
 *   [6,6,8],
 *   [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 * Example 2:
 *
 * Input: nums =
 * [
 *   [3,4,5],
 *   [3,2,6],
 *   [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */
