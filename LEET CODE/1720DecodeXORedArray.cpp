#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> &encoded, int first)
{
    vector<int> arr;
    arr.push_back(first);
    for (int i = 0; i < encoded.size(); ++i)
    {
        int next_element = arr.back() ^ encoded[i];
        arr.push_back(next_element);
    }
    return arr;
}

int main()
{
    vector<int> encoded = {6,2,7,3};
    int first = 4;

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