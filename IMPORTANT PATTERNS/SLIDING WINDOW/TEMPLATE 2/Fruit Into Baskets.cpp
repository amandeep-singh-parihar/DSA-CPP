// GFG
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// //Brute force
// // TC : O(N*N)
// // SC : O(2)
// int totalFruits(vector<int> &arr)
// {
//     int maxLen = 0;
//     for (int i = 0; i < arr.size(); ++i)
//     {
//         set<int> st;
//         for (int j = i; j < arr.size(); ++j)
//         {
//             st.insert(arr[j]);
//             if (st.size() <= 2)
//             {
//                 maxLen = max(maxLen, j - i + 1);
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }
//     return maxLen;
// }

// // Better
// // TC : O(N+N)
// // SC : O(2)
// int totalFruits(vector<int> &arr)
// {
//     int l = 0, r = 0, maxLen = 0;
//     unordered_map<int, int> mpp;
//     while (r < arr.size())
//     {
//         mpp[arr[r]]++;
//         while (mpp.size() > 2)
//         {
//             mpp[arr[l]]--;
//             if (mpp[arr[l]] == 0)
//             {
//                 mpp.erase(arr[l]);
//             }
//             ++l;
//         }
//         if (mpp.size() <= 2)
//         {
//             maxLen = max(maxLen, r - l + 1);
//         }
//         ++r;
//     }
//     return maxLen;
// }

// Best
// TC : O(N)
// SC : O(2)
int totalFruits(vector<int> &arr)
{
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp;
    while (r < arr.size())
    {
        mpp[arr[r]]++;
        if (mpp.size() > 2) // how we use if here the ans is we are take the window minimum of maxLen size,
        {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
            {
                mpp.erase(arr[l]);
            }
            ++l;
        }
        if (mpp.size() <= 2)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        ++r;
    }
    return maxLen;
}

int main()
{
    // vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    vector<int> arr = {2, 1, 2};
    cout << totalFruits(arr);
    return 0;
}