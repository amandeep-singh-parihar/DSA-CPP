#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n & 1)
        {
            n = n * 3 + 1;
        }
        else
        {
            n /= 2;
        }
    }
    cout << 1;
    return 0;
}
