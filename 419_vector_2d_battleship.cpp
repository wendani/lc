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

        if (j - 1 >= 0)
        {
            battleship(board, i, j - 1);
        }
        int columnLen = board[0].size();
        if (j + 1 < columnLen)
        {
            battleship(board, i, j + 1);
        }
        if (i - 1 >= 0)
        {
            battleship(board, i - 1, j);
        }
        int rowLen = board.size();
        if (i + 1 < rowLen)
        {
            battleship(board, i + 1, j);
        }
    }
};
