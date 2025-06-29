#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }

    node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(node *&head)
{
    node *temp = head;
    int l = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        ++l;
    }
    return l;
}

void insertAThead(node *&head, node *&tail, int data)
{
    if (head == nullptr)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    node *newnode = new node(data);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertATtail(node *&head, node *&tail, int data)
{
    if (head == nullptr)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    node *newnode = new node(data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertATanyPostion(node *&head, node *&tail, int data, int index)
{
    int length = getLength(head);

    // If index is out of bounds
    if (index < 1 || index > length + 1)
    {
        cout << "Index out of bounds" << endl;
        return;
    }

    // Inserting at head
    if (index == 1)
    {
        insertAThead(head, tail, data);
        return;
    }

    // Inserting at tail
    if (index == length + 1)
    {
        insertATtail(head, tail, data);
        return;
    }

    // Inserting at any other position
    node *prevNode = head;
    int i = 1;

    // Navigate to the previous node of the desired position
    while (i < index - 1 && prevNode != nullptr)
    {
        prevNode = prevNode->next;
        i++;
    }

    node *currNode = prevNode->next;

    node *newNode = new node(data);

    prevNode->next = newNode;
    newNode->prev = prevNode;

    newNode->next = currNode;
    currNode->prev = newNode;
}

int main()
{
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    // print(first);
    // cout << endl
    //      << "printing length" << endl;
    // cout << getLength(first);

    // cout << endl;
    // insertAThead(first, third, 10101);
    // print(first);

    // cout<<endl;
    // insertATtail(first,third,-1001);
    // cout<<endl;
    // print(first);

    cout << endl;
    cout << endl;
    cout << endl;
    print(first);
    cout << endl;
    insertATanyPostion(first, third, -101010, 2);
    cout << endl;
    print(first);

    return 0;
}