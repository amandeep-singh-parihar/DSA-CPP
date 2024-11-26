// insert sorted
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

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
    s.push(8);
    s.push(5);
    s.push(3);
    s.push(1);

    insertSorted(s, 7);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}