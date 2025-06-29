//28. Find the Index of the First Occurrence in a String
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//first attempt me bana diya
int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();

        if (n == 0) {
            return 0;
        }

        int i = 0, j = n;
#pragma unroll
        while (j <= h) {
            if (equal(haystack.begin() + i, haystack.begin() + j,
                      needle.begin())) {
                return i;
            }
            ++i, ++j;
        }
        return -1;
    }

int main()
{
    string h,n;
    cin>>h>>n;
    cout<<strStr(h,n);
    return 0;
}