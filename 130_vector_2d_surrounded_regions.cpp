class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowLen = board.size();
        int columnLen = board[0].size();

        int i, j;

        i = 0;
        for (j = 0; j < columnLen; j++)
        {
            if (board[i][j] == 'O')
            {
                unsurroundedRegion(board, i, j);
            }
        }
        i = rowLen - 1;
        for (j = 0; j < columnLen; j++)
        {
            if (board[i][j] == 'O')
            {
                unsurroundedRegion(board, i, j);
            }
        }
        j = 0;
        for (i = 1; i < rowLen - 1; i++)
        {
            if (board[i][j] == 'O')
            {
                unsurroundedRegion(board, i, j);
            }
        }
        j = columnLen - 1;
        for (i = 1; i < rowLen - 1; i++)
        {
            if (board[i][j] == 'O')
            {
                unsurroundedRegion(board, i, j);
            }
        }

        for (int i = 1; i < rowLen - 1; i++)
        {
            for (j = 1; j < columnLen - 1; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'Z')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void unsurroundedRegion(vector<vector<char>> &board, const int i, const int j)
    {
        if (board[i][j] != 'O')
        {
            return;
        }

        // board[i][j] == 'O' when we reach here
        board[i][j] = 'Z';

        if (j - 1 >= 0 && board[i][j - 1] == 'O')
        {
            unsurroundedRegion(board, i, j - 1);
        }
        if (j + 1 < columnLen && board[i][j + 1] == 'O')
        {
            unsurroundedRegion(board, i, j + 1);
        }
        if (i - 1 >= 0 && board[i - 1][j] == 'O')
        {
            unsurroundedRegion(board, i - 1, j);
        }
        if (i + 1 < rowLen && board[i + 1][j] == 'O')
        {
            unsurroundedRegion(board, i + 1, j);
        }
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowLen = board.size();
        int columnLen = board[0].size();

        unordered_set<int> unsurroundedCells;
        queue<int> unexploredUnsurroundedCells;

        int i, j;

        i = 0;
        for (j = 0; j < columnLen; j++)
        {
            if (board[i][j] == 'O')
            {
                int id = i * columnLen + j;
                unsurroundedCells.emplace(id);
                unexploredUnsurroundedCells.emplace(id);
            }
        }
        i = rowLen - 1;
        for (j = 0; j < columnLen; j++)
        {
            if (board[i][j] == 'O')
            {
                int id = i * columnLen + j;
                unsurroundedCells.emplace(id);
                unexploredUnsurroundedCells.emplace(id);
            }
        }
        j = 0;
        for (i = 1; i < rowLen - 1; i++)
        {
            if (board[i][j] == 'O')
            {
                int id = i * columnLen + j;
                unsurroundedCells.emplace(id);
                unexploredUnsurroundedCells.emplace(id);
            }
        }
        j = columnLen - 1;
        for (i = 1; i < rowLen - 1; i++)
        {
            if (board[i][j] == 'O')
            {
                int id = i * columnLen + j;
                unsurroundedCells.emplace(id);
                unexploredUnsurroundedCells.emplace(id);
            }
        }

        while (!unexploredUnsurroundedCells.empty())
        {
            const int id = unexploredUnsurroundedCells.front();

            const int i = id / columnLen;
            const int j = id % columnLen;

            if (j - 1 >= 0 && board[i][j - 1] == 'O' && !unsurroundedCells.count(id - 1))
            {
                unsurroundedCells.emplace(id - 1);
                unexploredUnsurroundedCells.emplace(id - 1);
            }
            if (j + 1 < columnLen && board[i][j + 1] == 'O' && !unsurroundedCells.count(id + 1))
            {
                unsurroundedCells.emplace(id + 1);
                unexploredUnsurroundedCells.push(id + 1);
            }
            if (i - 1 >= 0 && board[i - 1][j] == 'O' && !unsurroundedCells.count(id - columnLen))
            {
                unsurroundedCells.emplace(id - columnLen);
                unexploredUnsurroundedCells.emplace(id - columnLen);
            }
            if (i + 1 < rowLen && board[i + 1][j] == 'O' && !unsurroundedCells.count(id + columnLen))
            {
                unsurroundedCells.emplace(id + columnLen);
                unexploredUnsurroundedCells.emplace(id + columnLen);
            }

            unexploredUnsurroundedCells.pop();
        }

        for (int i = 1; i < rowLen - 1; i++)
        {
            for (j = 1; j < columnLen - 1; j++)
            {
                int id = i * columnLen + j;
                if (board[i][j] == 'O' && !unsurroundedCells.count(id))
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


/*
 * 130. Surrounded Regions
 *
 * You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
 *
 * Connect: A cell is connected to adjacent cells horizontally or vertically.
 * Region: To form a region connect every 'O' cell.
 * Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
 * To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
 *
 *
 *
 * Example 1:
 *
 * Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 *
 * Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 *
 * Explanation:
 *
 *
 * In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
 *
 * Example 2:
 *
 * Input: board = [["X"]]
 *
 * Output: [["X"]]
 *
 *
 *
 * Constraints:
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 */
