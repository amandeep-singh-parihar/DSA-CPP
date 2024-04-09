#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node *root)
{
    cout<<"enter the tree : ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }

    cout<<"enter the data for inserting in the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter the data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root=NULL;
    root=buildTree(root);


    //5 9 15 1 3 -1 -1 -1 2 -2 -1 -1 -1 16 12 -1 -1 -1 13 12 5 3 -1 -1 -1 4 -1 -1 11 9 8 -1 -1 7 -1 -1 10 6 -1 -1 -1
    cout<<endl<<"printing the level order traversal "<<endl;
    levelOrderTraversal(root);

    return 0;
}
