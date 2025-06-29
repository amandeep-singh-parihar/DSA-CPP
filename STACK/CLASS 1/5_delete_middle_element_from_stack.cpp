// delete middle element from stack
#include <bits/stdc++.h>
using namespace std;

// revision 2

void delete_Middle(stack<int> &s, int tsize)
{
    if (s.size() == 0)
    {
        cout << "stack is empty" << endl;
        return;
    }

    if (s.size() == (tsize / 2) + 1)
    {
        s.pop();
        return;
    }

    int target = s.top();
    s.pop();
    delete_Middle(s, tsize);
    s.push(target);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // s.push(5);

    int size = s.size();

    cout << "Stack contents before deleting the middle element:" << endl;
    stack<int> tempStack = s;
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    delete_Middle(s, size);

    cout << "Stack contents after deleting the middle element:" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}