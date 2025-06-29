#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

void solve(stack<int> &s, int tsize, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();
    solve(s, tsize, target);
    s.push(temp);
}

void insert_at_bottom(stack<int> &s, int tsize)
{
    if (s.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    int target = s.top();
    s.pop();
    solve(s, tsize, target);
}

void print(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(10); // bottom element
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(-999); // top element
    int tsize = s.size();
    insert_at_bottom(s, tsize);
    print(s);
    return 0;
}