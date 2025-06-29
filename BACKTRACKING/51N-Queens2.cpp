#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLDiagonal;
unordered_map<int, bool> bottomLDiagonal;

static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// rivise pending
bool isSafe(vector<vector<string>> &board, int row, int col, int n)
{
    if (rowCheck[row] || upperLDiagonal[n - 1 + col - row] || bottomLDiagonal[row + col])
    {
        return false;
    }
    return true;
}

void solve(vector<vector<string>> &board, vector<vector<string>> &result, int col, int n)
{
    // base case
    if (col == n)
    {
        vector<string> solution;
        for (int i = 0; i < n; ++i)
        {
            string row = "";
            for (int j = 0; j < n; ++j)
            {
                row += board[i][j];
            }
            solution.push_back(row);
        }
        result.push_back(solution);
        return;
    }

    // recursion
    for (int row = 0; row < n; ++row)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = "Q";
            rowCheck[row] = true;
            upperLDiagonal[n - 1 + col - row] = true;
            bottomLDiagonal[row + col] = true;
            solve(board, result, col + 1, n);

            // backtracking
            board[row][col] = ".";
            rowCheck[row] = false;
            upperLDiagonal[n - 1 + col - row] = false;
            bottomLDiagonal[row + col] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> board(n, vector<string>(n, "."));
    vector<vector<string>> result;
    solve(board, result, 0, n);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < result[0].size(); ++j)
        {
            cout << "[" << '"' << result[i][j] << '"';
            if (j < result[0].size() - 1)
            {
                cout << ",";
            }
            cout << "]";
        }
        cout << "]";
        cout << endl;
        cout << endl;
    }
    cout << endl;
    return 0;
}