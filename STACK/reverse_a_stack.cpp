#include<bits/stdc++.h>
using namespace std;

void insertATbottom(stack<int>& s,int element)
{
    if(s.empty())
    {
        s.push(element);
        return;
    }

    int num=s.top();
    s.pop();
    insertATbottom(s,element);
    s.push(num);


}

void reverseSTACK(stack<int>& mystack)
{
    if(mystack.empty())
    {
        return ;
    }

    int num=mystack.top();
    mystack.pop();
    reverseSTACK(mystack);
    insertATbottom(mystack,num);
}

int main()
{
    stack<int> mystack;

    // Push some elements onto the stack.
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);

    // Print the original stack.
    cout << "Original Stack: ";
    while (!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }

    // Push the elements back onto the stack.
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);

    // Reverse the stack.
    reverseSTACK(mystack);

    // Print the reversed stack.
    cout << "\nReversed Stack: ";
    while (!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }

    return 0;
}