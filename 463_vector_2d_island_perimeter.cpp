class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m_perimeter = 0;

        int rowLen = grid.size();
        int columnLen = grid[0].size();
        for (int i = 0; i < rowLen; i++)
        {
            for (int j = 0; j < columnLen; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Landed on island
                    measurePerimeter(grid, i, j);
                    return m_perimeter;
                }
            }
        }

        // We shall never reach here
        return m_perimeter;
    }

private:
    int m_perimeter = 0;

    void measurePerimeter(vector<vector<int>> &grid, const int i, const int j)
    {
        if (grid[i][j] != 1)
        {
            return;
        }

        // grid[i][j] == 1 when we reach here
        grid[i][j] = -1;

        if (j == 0)
        {
            m_perimeter++;
        }
        else
        {
            if (grid[i][j - 1] == 0)
            {
                m_perimeter++;
            }
            else
            {
                measurePerimeter(grid, i, j - 1);
            }
        }

        int columnLen = grid[0].size();
        if (j == columnLen - 1)
        {
            m_perimeter++;
        }
        else
        {
            if (grid[i][j + 1] == 0)
            {
                m_perimeter++;
            }
            else
            {
                measurePerimeter(grid, i, j + 1);
            }
        }

        if (i == 0)
        {
            m_perimeter++;
        }
        else
        {
            if (grid[i - 1][j] == 0)
            {
                m_perimeter++;
            }
            else
            {
                measurePerimeter(grid, i - 1, j);
            }
        }

        int rowLen = grid.size();
        if (i == rowLen - 1)
        {
            m_perimeter++;
        }
        else
        {
            if (grid[i + 1][j] == 0)
            {
                m_perimeter++;
            }
            else
            {
                measurePerimeter(grid, i + 1, j);
            }
        }
    }
};

/*
 * 463. Island Perimeter
 *
 * You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
 *
 * Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
 *
 * The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image above.
 * Example 2:
 *
 * Input: grid = [[1]]
 * Output: 4
 * Example 3:
 *
 * Input: grid = [[1,0]]
 * Output: 4
 *
 *
 * Constraints:
 *
 * row == grid.length
 * col == grid[i].length
 * 1 <= row, col <= 100
 * grid[i][j] is 0 or 1.
 * There is exactly one island in grid.
 */
