#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// void print(string name,int n)
// {
//     if(n==0) return ;

//     cout<<name<<endl;
//     print(name,n-1);

// }

void print2(int i, int n)
{
    if (i > n)
        return;

    cout << "aman" << endl;

    print2(i + 1, n);
}

int main()
{
    // string name;
    // cin>>name;
    cout << "****************" << endl;
    // print(name,5);

    int i, n;
    cin >> i >> n;
    print2(i, n);
    return 0;
}