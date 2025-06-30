/*

Binary Search a 2D Matrix I


You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

Input: matrix = [[1,3,5,7],
               [10,11,16,20],
               [23,30,34,60]],
               target = 3
Output: true



*/

#include <bits/stdc++.h>
using namespace std;

bool binary(vector<vector<int>> arr, int target)
{
    int rows = arr.size();
    int cols = arr[0].size();
    int s = 0;
    int e = rows * cols - 1; // last index -> 11 (here)

    while (s <= e)
    {
        int mid = s + (e - s) / 2; // mid = 11/2 = 5
        int row = mid / cols;
        int col = mid % cols;
        int element = arr[row][col]; // finding the mid element in the matrix
        // arr[5/2][5%2]
        // arr[2][1] -> 10

        if (element == target)
        {
            cout << "row-> " << row << " col-> " << col << endl;
            return true;
        }

        if (element > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}

int main()
{
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    vector<vector<int>> arr = {{2, 3, 5, 7},
                               {10, 11, 16, 20},
                               {23, 30, 34, 60}};
    int target;
    cin >> target;
    cout << binary(arr, target);
    return 0;
}