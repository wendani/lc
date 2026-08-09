class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowLen = grid.size();
        int columnLen = grid[0].size();

        int count = 0;

        for (int i = 0; i < rowLen; i++)
        {
            for (int j = 0; j < columnLen; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;

                    island(grid, i, j);
                }
            }
        }

        return count;
    }

private:
    void island(vector<vector<char>> &grid, const int i, const int j)
    {
        if (grid[i][j] != '1')
        {
            return;
        }

        // grid[i][j] == '1' when we reach here
        grid[i][j] = '2';

        if (j - 1 >= 0)
        {
            island(grid, i, j - 1);
        }
        int columnLen = grid[0].size();
        if (j + 1 < columnLen)
        {
            island(grid, i, j + 1);
        }
        if (i - 1 >= 0)
        {
            island(grid, i - 1, j);
        }
        int rowLen = grid.size();
        if (i + 1 < rowLen)
        {
            island(grid, i + 1, j);
        }
    }
};


/*
 * 200. Number of Islands
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 *
 *
 * Example 1:
 *
 * Input: grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 * Example 2:
 *
 * Input: grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 * Constraints:
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 */
