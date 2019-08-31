void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	if (!matrix || !*matrix || matrixSize < 1 || !matrixSize || *matrixColSize < 1) {
		return;
	}

	bool setFirstColumn = false;
	for (int i = 0; i < matrixSize; i++) {
		if (!matrix[i][0]) {
			setFirstColumn = true;
			break;
		}
	}

	bool setFirstRow = false;
	for (int j = 0; j < *matrixColSize; j++) {
		if (!matrix[0][j]) {
			setFirstRow = true;
			break;
		}
	}

	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < *matrixColSize; j++) {
			if (!matrix[i][j]) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < matrixSize; i++) {
		if (!matrix[i][0]) {
			for (int j = 1; j < *matrixColSize; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	for (int j = 1; j < *matrixColSize; j++) {
		if (!matrix[0][j]) {
			for (int i = 1; i < matrixSize; i++) {
				matrix[i][j] = 0;
			}
		}
	}

	if (setFirstColumn) {
		for (int i = 0; i < matrixSize; i++) {
			matrix[i][0] = 0;
		}
	}

	if (setFirstRow) {
		for (int j = 0; j < *matrixColSize; j++) {
			matrix[0][j] = 0;
		}
	}
}


/*
 * Example 1:
 *
 * Input:
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output:
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 *
 * Example 2:
 *
 * Input:
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output:
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 */
