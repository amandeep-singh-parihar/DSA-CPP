// L14. N-Queens | Leetcode Hard | Backtracking
// 51. N-Queens
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int duprow = row;
    int dupcol = col;
    // upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        --row, --col;
    }

    // left
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        --col;
    }

    row = duprow;
    col = dupcol;
    while (col >= 0 && row < n)
    {
        if (board[row][col] == 'Q')
            return false;
        --col, ++row;
    }

    return true;
}

void helper(int col, vector<vector<string>> &ans, vector<string> board, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; ++row)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            helper(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    helper(0, ans, board, n);
    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
// optimized
void helper(int col, vector<vector<string>> &ans, vector<string> &board,
            int n, vector<int> &leftRow, vector<int> &upperDiagonal,
            vector<int> &lowerDiagonal)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; ++row)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
            upperDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            helper(col + 1, ans, board, n, leftRow, upperDiagonal,
                   lowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0),
        lowerDiagonal(2 * n - 1, 0);
    helper(0, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for (auto it : ans)
    {
        cout << "[";
        for (auto _it : it)
        {
            cout << _it << " , ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}