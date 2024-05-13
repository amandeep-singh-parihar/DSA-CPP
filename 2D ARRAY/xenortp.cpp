#include <bits/stdc++.h>
using namespace std;

// void zeroToOne(int zeroIdx)
// {
//     zeroIdx = 1;
// }

// void oneToZero(int oneIdx)
// {
//     oneIdx = 0;
// }

// void changeVal(vector<vector<int>> &grid, int a, int b)
// {
//     if (grid[a][b] == 1)
//     {
//         grid[a][b] = 0;
//     }
//     else
//     {
//         grid[a][b] = 1;
//     }
// }

// void changRow(vector<vector<int>> &grid, int a, int b)
// {
//     int zerofirst = 0;
//     int onefirst = 0;
//     // first check all the rows
//     for (int i = 0; i < 3; i++)
//     {
//         int j = 0;
//         if (grid[i][j] == 0)
//         {
//             zerofirst = i;
//         }
//         else
//         {
//             onefirst = i;
//         }
//     }
//     if (zerofirst < onefirst)
//     {
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 changeVal(grid, i, j);
//             }
//         }
//     }
// }

// void changCol(vector<vector<int>> &grid, int a, int b)
// {
//     int zerofirst = 0;
//     int onefirst = 0;

//     for (int j = 0; j < 3; j++)
//     {
//         int i = 0;
//         if (grid[j][i] == 0)
//         {
//             zerofirst = j;
//         }
//         else
//         {
//             onefirst = j;
//         }
//     }
//     if (zerofirst < onefirst)
//     {
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 changeVal(grid, i, j);
//             }
//         }
//     }
// }

int matrixScore(vector<vector<int>> &grid)
{
    int n = grid.size();
    // for row
    if (grid[0][0] == 0)
    {
        for (int i = 0; i < n; i++)
        {
            grid[i][0] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};

    // now for col

    cout << "*************************" << endl;

    cout << "***************###########" << endl;

    for (int i = 0; i < 3; i++)
    {
        if(grid[0][0]==0)
        {
            
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     int j = 0;
    //     changRow(grid, i, j);
    // }

    // for (int j = 0; j < 4; j++)
    // {
    //     int i = 0;
    //     changCol(grid, j, i);
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}