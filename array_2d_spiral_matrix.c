/*
 * Example 1:
 *
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 * Example 2:
 *
 * Input:
 * [
 *   [1, 2, 3, 4],
 *   [5, 6, 7, 8],
 *   [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> spiral;

		int rowSize = matrix.size();
		if (rowSize < 1) {
			return spiral;
		}
		int colSize = matrix[0].size();
		if (colSize < 1) {
			return spiral;

		}

		// reach here when matrix has at least 1 element
		int startRow = 0;
		int startCol = 0;
		int endRow = rowSize - 1;
		int endCol = colSize - 1;
		findSpiral(spiral, matrix, startRow, startCol, endRow, endCol);
		return spiral;
	}

private:
	void findSpiral(vector<int> &spiral, const vector<vector<int>> &matrix, const int &startRow, const int &startCol, const int &endRow, const int &endCol)
	{
		if (startRow > endRow || startCol > endCol) {
			return;
		}

		spiral.push_back(matrix[startRow][startCol]);

		// single element
		if (startRow == endRow && startCol == endCol) {
			return;
		}

		int currRow = startRow;
		int currCol = startCol;
		if (startCol == endCol) {
			currRow++;
		}
		else {
			currCol++;
		}

		while (currRow != startRow && currCol != startCol) {
			spiral.push_back(matrix[currRow][currCol]);

			if (currRow == startRow && currCol < endCol) {
				currCol++;
			}
			else if (currCol == endCol && currRow < endRow) {
				currRow++;
			}
			else if (startRow < endRow && currRow == endRow && currCol > startCol) {
				currCol--;
			}
			else if (startCol < endCol && currCol == startCol && currRow > startRow) {
				currRow--;
			}
			else {
				break;
			}
		}
	}
};
