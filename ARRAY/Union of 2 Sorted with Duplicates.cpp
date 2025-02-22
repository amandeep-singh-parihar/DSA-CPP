// Union of 2 Sorted with Duplicates
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O( N1logN + N2longN ) + ( N1 + N2 )
// SC O(N1 + N2) + O(N1 + N2)
//               this is for return the ans
vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    set<int> s; // this is ordered set so it will take care of all the sorted order in the final res
    for (int i = 0; i < a.size(); ++i)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < b.size(); ++i)
    {
        s.insert(b[i]);
    }
    vector<int> res(s.begin(), s.end());
    return res;
}

// Optimal
// TC O(N1 + N2)
// SC O(N1 + N2)
// only for return the ans
vector<int> _findUnion(vector<int> &a, vector<int> &b)
{
    vector<int> uni;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            if (uni.size() == 0 || uni.back() != a[i])
            {
                uni.push_back(a[i]);
            }
            ++i;
        }
        else
        {
            if (uni.size() == 0 || uni.back() != b[j])
            {
                uni.push_back(b[j]);
            }
            ++j;
        }
    }

    while (i < a.size())
    {
        if (uni.size() == 0 || uni.back() != a[i])
        {
            uni.push_back(a[i]);
        }
        ++i;
    }
    while (j < b.size())
    {
        if (uni.size() == 0 || uni.back() != b[j])
        {
            uni.push_back(b[j]);
        }
        ++j;
    }
    return uni;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {1, 2, 3, 4, 5, 5, 5, 6, 7};
    vector<int> ans = _findUnion(a, b);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}