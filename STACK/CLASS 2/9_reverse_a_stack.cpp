// Reverse a stack
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 3

void insert_at_bottom(stack<int> &s, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insert_at_bottom(s, target);
    s.push(topElement);
}

void reverse_stack(stack<int> &s, int sizeOfStack)
{
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    reverse_stack(s, sizeOfStack);
    insert_at_bottom(s, target);
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
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    reverse_stack(s, s.size());
    print(s);

    return 0;
}