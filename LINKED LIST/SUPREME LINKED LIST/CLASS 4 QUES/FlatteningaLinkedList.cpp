// Flattening a Linked List
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

struct node
{
    int data;
    struct node *next;
    struct node *bottom;

    node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

vector<int> SORT(node *root)
{
    vector<int> arr;
    node *temp = root;
    while (temp != NULL)
    {
        node *t2 = temp;
        while (t2 != NULL)
        {
            arr.push_back(t2->data);
            t2 = t2->bottom;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    return arr;
}

node *convert(vector<int> arr)
{
    if (arr.empty())
        return nullptr;

    node *head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        node *newNode = new node(arr[i]);
        temp->bottom = newNode;
        temp = temp->bottom;
    }
    return head;
}

node *flatten(node *root)
{
    return convert(SORT(root));
}

int main()
{
    node *head = new node(5);
    head->bottom = new node(7);
    head->bottom->bottom = new node(8);
    head->bottom->bottom->bottom = new node(30);

    head->next = new node(10);
    head->next->bottom = new node(20);

    node *flattened = flatten(head);

    // Printing the flattened list
    node *temp = flattened;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;

    return 0;
}