// The Celebrity Problem
// Brute force
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int celebrity(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); ++i)
    {
        bool isCelebrity = true;
        for (int j = 0; j < mat[i].size(); ++j)
        {
            if (i != j)
            {
                if (mat[i][j] == 1 || mat[j][i] == 0)
                {
                    isCelebrity = false;
                    break;
                }
            }
        }
        if (isCelebrity)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // Example matrix
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}};

    // Call the celebrity function
    int result = celebrity(mat);

    // Output the result
    if (result == -1)
    {
        cout << "No celebrity found" << endl;
    }
    else
    {
        cout << "The celebrity is person " << result << endl;
    }

    return 0;
}
