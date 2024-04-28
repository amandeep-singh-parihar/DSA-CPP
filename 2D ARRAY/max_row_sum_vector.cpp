#include <bits/stdc++.h>
using namespace std;

int largestSum(vector<vector<int>> &array)
{
    int maxi = -99999999;
    for (int i = 0; i < array.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < array[i].size(); j++)
        {
            sum += array[i][j];
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> array(rows, vector<int>(cols));
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }

    int result = largestSum(array);
    cout << "Largest sum of a row in the array: " << result << endl;

    return 0;
}