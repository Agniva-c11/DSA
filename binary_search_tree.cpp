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
        this->right = NULL;
    }
};

Node* insertBST(Node* &root, int data)
{
    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data>root->data)
    {
        root->right = insertBST(root->right, data);
    }
    else
    {
        root->left = insertBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = insertBST(root, data);
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

Node* minValue(Node* &root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* &root)
{
    Node* temp = root;
    while(temp->right != NULL)
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
    Node* mini = minValue(root);
    cout<<"Minimum value in BST:"<<mini->data<<endl;
    Node* maxi = maxValue(root);
    cout<<"Maximum value in BST:"<<maxi->data<<endl;
}