#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TODO:
    int n = 10;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> boxs;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void solveSudoku(vector<vector<char>> &board)
    {
        rows.assign(n, vector<int>(n, 0));
        cols.assign(n, vector<int>(n, 0));
        boxs.assign(n, vector<int>(n, 0));

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int pos = j / 3 + i / 3 * 3;
                if (board[i][j] != '.')
                {
                    rows[i][board[i][j] - '0'] = 1;
                    boxs[pos][board[i][j] - '0'] = 1;
                }

                if (board[j][i] != '.')
                {
                    cols[i][board[i][j] - '0'] = 1;
                }
            }
        }

        backtrack(board, 0, 0);
    }

    void backtrack(vector<vector<char>> &board, int row, int col)
    {
        // 终止条件是什么??

        if (board[row][col] == '.')
        {
            // 处理当前空格
            for (int i = 1; i <= 9; ++i)
            {
                int pos = col / 3 + row / 3 * 3;
                if (!rows[row][i] && !cols[col][i] && !boxs[pos][i])
                {
                    board[row][col] = '0' + i;
                    rows[row][i] = 1;
                    cols[col][i] = 1;
                    boxs[pos][i] = 1;
                    for (int j = 0; j < 4; ++j)
                    {
                        int new_row = row + directions[j][0];
                        int new_col = col + directions[j][1];
                        if (new_row >= 0 && new_row < 9 && new_col >= 0 && new_col < 9)
                        {
                            backtrack(board, new_row, new_col);
                        }
                    }
                    board[row][col] = '.';
                    rows[row][i] = 0;
                    cols[col][i] = 0;
                    boxs[pos][i] = 0;
                }
            }
        }
        else
        {
            // 不是空格，直接下一个
            for (int j = 0; j < 4; ++j)
            {
                int new_row = row + directions[j][0];
                int new_col = col + directions[j][1];
                if (new_row >= 0 && new_row < 9 && new_col >= 0 && new_col < 9)
                {
                    backtrack(board, new_row, new_col);
                }
            }
        }
    }
};

int main()
{
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution su;
    su.solveSudoku(board);
    for (auto chars : board)
    {
        for (auto c : chars)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}