// middle element in stack
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

void printMiddle(stack<int> &s, int &totalSize)
{

    if (s.size() == 0)
    {
        cout << "There is no element in Stack" << endl;
        return;
    }

    if (s.size() == totalSize / 2 + 1)
    {
        cout << "Middle element is : " << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();

    printMiddle(s, totalSize);

    s.push(temp);
}

void printMiddle_iterative(stack<int> &s, int &totalSize)
{

    while (s.size() != (totalSize / 2) + 1)
    {
        s.pop();
    }
    s.top();
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.push(50);
    // s.push(60);
    // s.push(70);
    int totalsize = s.size();
    printMiddle(s, totalsize);

    return 0;
}