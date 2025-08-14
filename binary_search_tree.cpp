#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this ->right = NULL;
    }
};
Node* createBST(Node* &root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data > root->data)
    {
        createBST(root->right, data);
    }
    else
    {
        createBST(root->left, data);
    }
    return root;
}
void takeinput(Node* & root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        createBST(root, data);
        cin>>data;
    }
}
void levelordertraversal(Node* &root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
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

Node* minval(Node* &root)
{
    Node* temp = root;
    while(temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxval(Node* &root)
{
    Node* temp = root;
    while(temp->right)
    {
        temp = temp->right;
    }
    return temp;
}
int main()
{
    Node* root = NULL;
    takeinput(root);
    levelordertraversal(root);
    cout<<"Min value is:"<<minval(root)->data<<endl;
    cout<<"Max value is:"<<maxval(root)->data<<endl;

}