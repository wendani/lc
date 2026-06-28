class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int columnLen = grid[0].size();

        int minutes = 0;
        queue<int> rottenOranges;
        unordered_set<int> freshOranges;
        for (int i = 0; i < rowLen; i++)
        {
            for (int j = 0; j < columnLen; j++)
            {
                int id = i * columnLen + j;
                if (grid[i][j] == 2)
                {
                    rottenOranges.push(id);
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges.push(id);
                }
                else
                {
                    // grid[i][j] == 0
                    // Do nothing
                }
            }
        }

        while (!freshOranges.empty())
        {
            int len = rottenOranges.size();
            if (len == 0)
            {
                // Impossible case
                return -1;
            }

            for (int cnt = 0; cnt < len; cnt++)
            {
                const int &id = rottenOranges.front();
                const int i = id / columnLen;
                const int j = id % columnLen;

                if (j - 1 >= 0)
                {
                    int erased = freshOranges.erase(id - 1);
                    if (erased > 0)
                    {
                        rottenOranges.push(id - 1);
                    }
                }
                if (j + 1 < columnLen)
                {
                    int erased = freshOranges.erase(id + 1);
                    if (erased > 0)
                    {
                        rottenOranges.push(id + 1);
                    }
                }
                if (i - 1 >= 0)
                {
                    int erased = freshOranges.erase(id - columnLen);
                    if (erased > 0)
                    {
                        rottenOranges.push(id - columnLen);
                    }
                }
                if (i + 1 < rowLen)
                {
                    int erased = freshOranges.erase(id + columnLen);
                    if (erased > 0)
                    {
                        rottenOranges.push(id + columnLen);
                    }
                }

                rottenOranges.pop();
            }

            minutes++;
        }

        return minutes;
    }
};

/*
 * 994. Rotting Oranges
 * You are given an m x n grid where each cell can have one of three values:
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * Example 2:
 *
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 * Example 3:
 *
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 *
 *
 * Constraints:
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 */
