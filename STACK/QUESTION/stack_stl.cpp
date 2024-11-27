#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creating of stack
    stack<int> s;

    // push
    s.push(2);
    s.push(3);

    // pop
    s.pop();

    cout << "printing the top element : " << s.top() << endl;

    // s.pop();

    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not emepty" << endl;
    }

    cout << "size of stack is : " << s.size() << endl;
    return 0;
}