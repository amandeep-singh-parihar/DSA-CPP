/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseLL(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void printLL(Node* head){
        Node* p = head;
        while(p){
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    Node* addOne(Node* head) {
        // Your Code here
        // printLL(head);
        Node* newLL = reverseLL(head);
        
        // cout<<"(*****"<<endl;
        // printLL(newLL);
        // cout<<"******)"<<endl;
        
        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;
        Node* l1 = newLL;
        Node* one = new Node(1);
        Node* l2 = one;
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum+=l1->data;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->data;
                l2 = l2->next;
            }
            sum+=carry;
            carry = sum/10;
            Node* sumnode = new Node(sum%10);
            temp->next = sumnode;
            temp = temp->next;
        }
        return reverseLL(dummy->next);
        // return head of list after adding one
    }
};