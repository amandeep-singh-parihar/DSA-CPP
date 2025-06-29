// 1358. Number of Substrings Containing All Three Characters
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute-> Better
// TC : O(N*N);
// SC : O(1);
// int numberOfSubstrings(string s)
// {
//     int cnt = 0;
//     for (int i = 0; i < s.size(); ++i)
//     {
//         int mpp[3] = {0};
//         for (int j = i; j < s.size(); ++j)
//         {
//             mpp[s[j] - 'a'] = 1;
//             if (mpp[0] + mpp[1] + mpp[2] == 3)
//             {
//                 cnt = cnt + (s.size() - j);
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

// OPTIMAL
// TC : O(N);
// SC : O(1);
int numberOfSubstrings(string s)
{
    int cnt = 0;
    int mpp[3] = {-1, -1, -1};
    for (int i = 0; i < s.size(); ++i)
    {
        mpp[s[i] - 'a'] = i;
        if (mpp[0] != -1 && mpp[1] != -1 && mpp[2] != -1)
        {
            cnt = cnt + (1 + min(min(mpp[0], mpp[1]), mpp[2]));
        }
    }
    return cnt;
}
// even there is no need of if (check) because the min in worst be -1 and (1+(-1))=0.

int main()
{
    string str;
    cin >> str;
    cout << numberOfSubstrings(str);
    return 0;
}