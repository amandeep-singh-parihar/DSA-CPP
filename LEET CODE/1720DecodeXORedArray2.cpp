#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> &encoded, int first)
{
    int n=encoded.size()+1;
    vector<int>arr(n);
    arr[0]=first;
    for(int i=0;i<n-i;i++)
    {
        arr[i+1]=arr[i]^encoded[i];
    }
    return arr;
}

/*
vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr={first};
        for (int &n:encoded) {
            arr.push_back(arr.back()^n);
        }
        return arr;
    }

*/
int main()
{
    vector<int> encoded = {1,2,3};
    int first = 1;

    vector<int> arr = decode(encoded, first);

    // Output the decoded array
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;

    return 0;
}