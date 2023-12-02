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

class QUEUE
{
    node *f;
    node *r;
    int size;

public:
    QUEUE()
    {
        size=0;
        f=r=NULL;
    }

    bool isEmpty()
    {
        return f==r;
    }

    void enqueue(int data)
    {
        node *temp=new node(data);
        if(isEmpty())
        {
            f=r=temp;
        }else{
            r->next=temp;
            r=temp;
        }
        size++;
    }

    int dequeue()
    {
        if(isEmpty())
        {
            return -1;
        }else{
            int data=f->data;
        }
    }

    int getsize()
    {
        return size;
    }
};

int main()
{

    return 0;
}