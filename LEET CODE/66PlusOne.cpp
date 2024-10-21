// 66. Plus One
#include <bits/stdc++.h>
using namespace std;
// revision 1
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        digits[i]++;

        if (digits[i] < 10)
        {
            return digits;
        }
        // else case if the digit is greater then or equal to 10
        digits[i] = 0;
    }
    // edge case if digits[i]=9
    digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }

    cout << "[";
    vector<int> result = plusOne(digits);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
    return 0;
}