// stack implementation using linked list

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    node *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(int element)
    {
        node *temp = new node(element);
        temp->next = head;
        size++;
        head = temp;
    }

    void pop()
    {
        node *temp;
        if (head == NULL)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    bool isEmpty()
    {
        // if(head==NULL)
        // {
        //     return 1;
        // }else{
        //     return 0;
        // }
        return head == NULL;
    }

    int peek()
    {
        node *temp;
        if (head != NULL)
        {
            return head->data;
        }
        else
        {
            cout << "stack is empty" << endl;
        }
    }
};

int main()
{
    Stack s;

    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    cout << "top element is : " << s.peek() << endl;
    s.pop();
    cout << "top element is : " << s.peek() << endl;
    s.pop();
    s.pop();
    s.pop();
    if (s.isEmpty())
    {
        cout << "stack is empty " << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

    return 0;
}