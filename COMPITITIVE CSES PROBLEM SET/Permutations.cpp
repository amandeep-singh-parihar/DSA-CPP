#include <bits/stdc++.h>
using namespace std;

void Permutations(int arr[], int n)
{
    if (n == 1)
    {
        cout << 1;
    }
    else if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        int k = 0;
        for (int i = 1; i <= n; ++i)
        {
            arr[k++] = i;
        }

        for (int i = 1; i < n; i = i + 2)
        {
            cout << arr[i] << " ";
        }

        for (int i = 0; i < n; i = i + 2)
        {
            cout << arr[i] << " ";
        }

        
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    Permutations(arr, n);

    return 0;
}