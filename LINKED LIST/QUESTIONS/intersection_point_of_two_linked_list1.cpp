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

node *intersection_point_of_two_linked_list(node *&head1, node *&head2)
{
    node *d1 = head1;
    node *d2 = head2;
    // traversing the first list
    int count1 = 1;
    while (d1 != NULL)
    {
        count1++;
        d1 = d1->next;
    }

    // traversing the second list
    int count2 = 1;
    while (d2 != NULL)
    {
        count2++;
        d2 = d2->next;
    }

    //again pointing the heads
    d1 = head1;
    d2 = head2;

    if (count1 > count2)
    {
        int diff = count1 - count2;
        while (diff--)
        {
            d1 = d1->next;
        }
    }
    else
    {
        int diff = count2 - count1;
        while (diff--)
        {
            d2 = d2->next;
        }
    }

    while (d1 != d2)
    {
        d1 = d1->next;
        d2 = d2->next;
    }

    return d1;
}


int main()
{
    node *l1 = new node(1);
    node *head1 = l1;
    head1->next = new node(2);
    head1->next->next = new node(8);
    head1->next->next->next = new node(7);
    head1->next->next->next->next = new node(6);

    node *l2 = new node(2);
    node *head2 = l2;
    head2->next = new node(8);
    head2->next->next = new node(1);
    head2->next->next->next = new node(3);
    head2->next->next->next->next = new node(8);
    head2->next->next->next->next->next = new node(7);
    head2->next->next->next->next->next->next = new node(6);

    head2->next->next->next->next->next->next->next = head1->next->next;

    node *ans = intersection_point_of_two_linked_list(head1, head2);

    if (ans) {
        cout << "Intersection Point: " << ans->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }


    return 0;
}