// sort a stack
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 3

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

void sort_a_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topEle = s.top();
    s.pop();

    sort_a_stack(s);
    insertSorted(s, topEle); // now we have to push it in sorted manner
}

int main()
{
    stack<int> s;
    s.push(8);
    s.push(-1);
    s.push(30);
    s.push(-1101);

    sort_a_stack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}