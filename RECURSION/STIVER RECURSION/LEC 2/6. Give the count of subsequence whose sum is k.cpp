// L7. All Kind of Patterns in Recursion | Print All | Print one | Count
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int printS(int i, int s, int sum, vector<int> &arr)
{
    if (i == arr.size())
    {
        if (s == sum)
            return 1;
        return 0;
    }

    // include
    s += arr[i];
    int l = printS(i + 1, s, sum, arr);
    s -= arr[i];

    // exclude
    int r = printS(i + 1, s, sum, arr);
    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int sum = 2;
    cout << printS(0, 0, sum, arr);
    return 0;
}

/*
The basic pattern is in the image of the same name below this

Here when the base condition satisfied return 1
if not return 0

and when the function return from the call if it satisfied it get some 1 from call which we will
store in the l

same for the r

and at the end we return l + r for each and every recursive call

and this way it only counts that which satisfies condition and we get the desired count of those 
subsequence whose sum is k

*/
