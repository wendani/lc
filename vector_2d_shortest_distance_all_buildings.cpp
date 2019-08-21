class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		int rowSize = grid.size();
		if (rowSize < 1) {
			return -1;
		}
		int colSize = grid[0].size();
		if (colSize < 1) {
			return -1;
		}

		int totalBuildings = 0;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (grid[i][j] == 1) {
					totalBuildings++;
				}
			}
		}

		int upperLimit = rowSize * colSize * totalBuildings;
		int minDist = upperLimit;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (grid[i][j] == 0) {
					int dist = findDist(grid, rowSize, colSize, totalBuildings, i, j);
					if (dist > 0 && dist < minDist) {
						minDist = dist;
					}
				}
			}
		}
		return minDist < upperLimit ? minDist : -1;
	}
private:
	int findDist(const vector<vector<int>> &grid, const int rowSize, const int colSize, int totalBuildings, const int i, const int j)
	{
		int totalDist = 0;

		unordered_set<int> idxSet[2];
		unordered_set<int> *curr = &idxSet[0];
		unordered_set<int> *next = &idxSet[1];
		vector<bool> visited(rowSize * colSize, false);

		int dist = 0;
		int idx = i * colSize + j;
		curr->insert(idx);
		visited[idx];
		while (!curr->empty()) {
			for (const auto &idx : *curr) {
				// dequeue
				int row = idx / colSize;
				int column = idx % colSize;
				if (grid[row][column] == 1) {
					totalDist += dist;
					totalBuildings--;
					if (!totalBuildings) {
						return totalDist;
					}
					continue;
				}

				// enqueue
				int i = row + 1;
				int j = column;
				if (i < rowSize && grid[i][j] != 2) {
					int idx = i * colSize + j;
					if (!visited[idx]) {
						next->insert(idx);
						visited[idx] = true;
					}
				}

				i = row - 1;
				j = column;
				if (i >= 0 && grid[i][j] != 2) {
					int idx = i * colSize + j;
					if (!visited[idx]) {
						next->insert(idx);
						visited[idx] = true;
					}
				}

				i = row;
				j = column + 1;
				if (j < colSize && grid[i][j] != 2) {
					int idx = i * colSize + j;
					if (!visited[idx]) {
						next->insert(idx);
						visited[idx] = true;
					}
				}

				i = row;
				j = column - 1;
				if (j >= 0 && grid[i][j] != 2) {
					int idx = i * colSize + j;
					if (!visited[idx]) {
						next->insert(idx);
						visited[idx] = true;
					}
				}
			}
			curr->clear();

			dist++;
			auto *temp = curr;
			curr = next;
			next = temp;
		}
		return -1;
	}
};

/*
 * Example:
 *
 * Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
 *
 * 1 - 0 - 2 - 0 - 1
 * |   |   |   |   |
 * 0 - 0 - 0 - 0 - 0
 * |   |   |   |   |
 * 0 - 0 - 1 - 0 - 0
 *
 * Output: 7
 *
 * Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
 *              the point (1,2) is an ideal empty land to build a house, as the total
 *              travel distance of 3+3+1=7 is minimal. So return 7.
 */
