// insert sorted in stack
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

void insertSorted(stack<int> &s, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }

    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    int topEle = s.top();
    s.pop();
    insertSorted(s, target);
    s.push(topEle);
}

int main()
{
    stack<int> s;
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    insertSorted(s, 25);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}