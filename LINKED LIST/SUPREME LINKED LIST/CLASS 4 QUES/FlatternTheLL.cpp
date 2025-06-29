/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* &head1 , Node* &head2){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(head1 && head2){
            if(head1->data > head2->data){
                temp->bottom = head2;
                temp = head2;
                head2=head2->bottom;
            }else{
                temp->bottom = head1;
                temp = head1;
                head1=head1->bottom;
            }
        }
        if(head1){
            temp->bottom = head1;
        }
        if(head2){
            temp->bottom = head2;
        }
        
        if(dummy->bottom){
            dummy->bottom->next = NULL;
        }
        
        return dummy->bottom;
        
    }
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL || root->next==NULL){
            return root;
        }
        
        Node* mergedLL = flatten(root->next);
        root = merge(root,mergedLL);
        return root;
        
    }
};