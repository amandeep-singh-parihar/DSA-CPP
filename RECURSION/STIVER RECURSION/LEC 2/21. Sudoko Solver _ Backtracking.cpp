// L15. Sudoko Solver | Backtracking
// 37. Sudoku Solver
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool isValid(int row, int col, char ch, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[row][i] == ch)
            return false;

        if (board[i][col] == ch)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            return false;
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ++ch)
                {
                    if (isValid(i, j, ch, board))
                    {
                        board[i][j] = ch;
                        if (solve(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    // Print the solved board
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << "\n";
    }

    return 0;
}
