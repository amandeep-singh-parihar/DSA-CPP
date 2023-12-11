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
public:
    node *f = NULL;
    node *r = NULL;

    void enqueue(int data)
    {
        node *temp = new node(data);

        if (r == NULL)
        {
            f = r = temp;
            return;
        }

        r->next = temp;
        r = temp;
    }

    void dequeue()
    {
        if (f == NULL)
        {
            return;
        }

        node *temp = f;
        f = f->next;

        if (f == NULL)
        {
            r = NULL;
        }

        delete (temp);
    }

    void display()
    {
        node *p = f;

        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    QUEUE q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Queue Front : " << ((q.f != NULL) ? (q.f)->data : -1) << endl;
    cout << "Queue Rear : " << ((q.r != NULL) ? (q.r)->data : -1);
    cout << "___________________________" << endl;
    q.display();
    return 0;
}