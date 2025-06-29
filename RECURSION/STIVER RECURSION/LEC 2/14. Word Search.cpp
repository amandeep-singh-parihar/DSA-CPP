// 79. Word Search
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool isValid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
bool helper(int row, int col, int idx, int n, int m,
            vector<vector<char>> &board, string word, int delRow[],
            int delCol[])
{

    if (idx == word.size())
        return true;

    if (!isValid(row, col, n, m) || board[row][col] != word[idx])
        return false;

    char temp = board[row][col];
    board[row][col] = '@';
    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (helper(nrow, ncol, idx + 1, n, m, board, word, delRow, delCol))
            return true;
    }
    board[row][col] = temp;
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == word[0] &&
                helper(i, j, 0, n, m, board, word, delRow, delCol))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}