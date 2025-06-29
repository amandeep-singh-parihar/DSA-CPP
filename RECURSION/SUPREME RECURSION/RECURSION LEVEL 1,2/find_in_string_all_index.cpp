#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 2
void findKey(string name, int n, int i, char key, vector<int> &ans)
{
    if (i > n - 1)
    {
        return;
    }

    // 1 case solve
    if (name[i] == key)
    {
        // cout<<"Found at : "<<i<<endl;
        ans.push_back(i);
        // no need of return as we want all indexs
        // lets store this in vector
    }

    return findKey(name, n, i + 1, key, ans);
}

int main()
{
    string name = "amandeepsinghparihar";
    int n = name.length();

    vector<int> ans;

    char key = 'a';
    int i = 0;

    findKey(name, n, i, key, ans);
    cout << "[ ";
    for (auto z : ans)
    {
        cout << z << " ";
    }
    cout << "]";
    cout << endl;

    return 0;
}