class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rowLen = board.size();
        int columnLen = board[0].size();

        unordered_set<int> battleshipCells;
        int count = 0;

        for (int i = 0; i < rowLen; i++)
        {
            for (int j = 0; j < columnLen; j++)
            {
                if (board[i][j] == 'X')
                {
                    int id = i * columnLen + j;
                    if (!battleshipCells.count(id))
                    {
                        count++;

                        if (j + 1 < columnLen && board[i][j + 1] == 'X')
                        {
                            // Horizontal battleship
                            for (int l = j + 1; l < columnLen; l++)
                            {
                                if (board[i][l] != 'X')
                                {
                                    break;
                                }
                                battleshipCells.emplace(id + (l - j));
                            }
                        }
                        else if (i + 1 < rowLen && board[i + 1][j] == 'X')
                        {
                            // Vertical battleship
                            for (int k = i + 1; k < rowLen; k++)
                            {
                                if (board[k][j] != 'X')
                                {
                                    break;
                                }
                                battleshipCells.emplace(id + (k - i) * columnLen);
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rowLen = board.size();
        int columnLen = board[0].size();

        int count = 0;
        for (int i = 0; i < rowLen; i++)
        {
            for (int j = 0; j < columnLen; j++)
            {
                if (board[i][j] == 'X')
                {
                    count++;

                    battleship(board, i, j);
                }
            }
        }

        return count;
    }

private:
    void battleship(vector<vector<char>> &board, const int i, const int j)
    {
        if (board[i][j] != 'X')
        {
            return;
        }

        // board[i][j] == 'X' when we reach here
        board[i][j] = 'Z';

        int columnLen = board[0].size();
        if (j + 1 < columnLen)
        {
            battleship(board, i, j + 1);
        }
        int rowLen = board.size();
        if (i + 1 < rowLen)
        {
            battleship(board, i + 1, j);
        }
    }
};

/*
 * 419. Battleships in a Board
 *
 * Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.
 *
 * Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
 *
 *
 *
 * Example 1:
 *
 *
 * Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
 * Output: 2
 * Example 2:
 *
 * Input: board = [["."]]
 * Output: 0
 *
 *
 * Constraints:
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is either '.' or 'X'.
 *
 *
 * Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?
 */
