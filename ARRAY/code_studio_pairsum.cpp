// you are given an array of size N and an integer S your task is to return the list of all pairs of elements such that
//  each sum elements of each pair equals to S
//  and the pair also in sorted ordre -----------------------------> INCOMPLETE-----------O(n^2)

#include <bits/stdc++.h>
using namespace std;
int pairsum(int arr[], int size, int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == n)
            {
                mini = min(arr[i], arr[j]);
                maxi = max(arr[i], arr[j]);
                cout << mini << " " << maxi << " ";
                cout << endl;
            }
        }
    }
    // int s=sort(mini,maxi);
    //  return s;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    pairsum(arr, 5, n);
    return 0;
}