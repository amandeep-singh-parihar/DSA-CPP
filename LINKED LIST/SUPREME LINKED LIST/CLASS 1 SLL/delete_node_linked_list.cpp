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

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void deleteNode(int position ,node* &head,node* &tail)
{
    if(head==nullptr)
    {
        cout<<"Cannot delete"<<endl;
        return;
    }

    if(position==1){
        node* temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
        return;
    }

    node* current=head;
    node* previous=NULL;
    int count=1;
    while(count<position && current!=nullptr)
    {
        previous=current;
        current=current->next;
        count++;
    }
    if(current==nullptr)
    {
        cout<<"position is out of bounds"<<endl;
        return;
    }

    previous->next=current->next;
    current->next=NULL;
    delete current;

    if(previous->next==nullptr)
    {
        tail=previous;
    }
}

void print(node*&head)
{
    node* p=head;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);
    node *fifth = new node(50);
    node *sixth = new node(60);
    node *seventh = new node(101);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    cout<<"Before deleting"<<endl;
    print(first);
    cout<<endl;
    cout<<"After deleting"<<endl;
    deleteNode(7,first,sixth);
    print(first);
    return 0;
}