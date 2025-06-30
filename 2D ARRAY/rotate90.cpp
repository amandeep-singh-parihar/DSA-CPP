// Rotate the matrix by 90 // done by ---> amandeep singh parihar

#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();
    vector<vector<int>> brr(row, vector<int>(col, 0));
    // get the transpose of the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            brr[i][j] = arr[j][i];
        }
    }
    int startingCol = 0;
    int endingCol = col - 1;
    while (startingCol <= endingCol)
    {
        for (int i = 0; i < row; i++)
        {
            swap(brr[i][startingCol], brr[i][endingCol]);
        }
        startingCol++, endingCol--;
    }
    cout << "THE 90 DEGREE ROTATED ARRAY IS : " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "PRINTING THE ARRAY" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    rotate90(arr);
}