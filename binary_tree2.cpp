#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
        int data;
        node* left;
        node* right;
    
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{
    cout<<"Enter data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter left:";
    root->left = buildTree(root->left);
    cout<<"Enter right:";
    root->right = buildTree(root->right);

    return root;
}

void levelordertraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
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
    node* root = NULL;
    root = buildTree(root);

    cout<<"Level Order Traversal:"<<endl;
    levelordertraversal(root);
}