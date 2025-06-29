// 148. Sort List
// convert the linked list into array and then sort the array and again store the array into linked list
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
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

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *sortList(node *head)
{
    vector<int> arr;
    node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    for (int i = 0; i < arr.size(); ++i)
    {
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

int main()
{
    node *first = new node(4);
    node *second = new node(2);
    node *three = new node(1);
    node *four = new node(3);
    first->next = second;
    second->next = three;
    three->next = four;
    cout << endl;
    print(first);
    cout << endl;
    node *ans = sortList(first);
    print(ans);

    return 0;
}