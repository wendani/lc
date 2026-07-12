/*
 * Example 1:
 *
 *
 * Input:
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation:
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
 * by a path of the same color as the starting pixel are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally connected
 * to the starting pixel.
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void _floodFill(int **image, const int rowSize, const int colSize, int row, int column, const int oldColor, const int newColor)
{
	if (row < 0 || row >= rowSize) {
		return;
	}

	if (column < 0 || column >= colSize) {
		return;
	}

	if (image[row][column] != oldColor) {
		return;
	}

	image[row][column] = newColor;

	_floodFill(image, rowSize, colSize, row, column + 1, oldColor, newColor);
	_floodFill(image, rowSize, colSize, row + 1, column, oldColor, newColor);
	_floodFill(image, rowSize, colSize, row, column - 1, oldColor, newColor);
	_floodFill(image, rowSize, colSize, row - 1, column, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {
	if (!image || !*image || imageSize < 1 || !imageColSize || *imageColSize < 1) {
		if (returnSize) {
			*returnSize = 0;
		}
		if (returnColumnSizes) {
			*returnColumnSizes = NULL;
		}
		return NULL;
	}

	// int **newImage = (int **)malloc(imageSize * sizeof(int *));
	// for (int i = 0; i < imageSize; i++) {
	// 	newImage[i] = (int *)malloc(*imageColSize * sizeof(int));
	// 	for (int j = 0; j < *imageColSize; j++) {
	// 		newImage[i][j] = image[i][j];
	// 	}
	// }

	if (image[sr][sc] != newColor) {
		_floodFill(image, imageSize, *imageColSize, sr, sc, image[sr][sc], newColor);
	}

	if (returnSize) {
		*returnSize = imageSize;
	}
	if (returnColumnSizes) {
		// int *colSize = (int *)malloc(sizeof(int));
		// *colSize = *imageColSize;
		// *returnColumnSizes = colSize;
		*returnColumnSizes = imageColSize;
	}
	// return newImage;
	return image;
}
