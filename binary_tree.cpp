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
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Creating a binary tree
node* buildTree(node* root)
{
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for left:"<<endl;
    root -> left = buildTree(root->left);
    cout<<"Enter data for right:"<<endl;
    root -> right = buildTree(root->right);

    return root;
}

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp -> left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp -> right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root)
{
    queue<node* > q;
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
            if(temp -> left)
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

void inorderTraversal(node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorderTraversal(root -> left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    
}

void preordertraveral(node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preordertraveral(root->left);
    preordertraveral(root->right);
   
}

void postordertraversal(node* root)
{
    if(root == NULL)
    {
        return;
    }

    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
   
}
int main()
{
    node* root = NULL;

    // root = buildTree(root);

    // cout<<"Level Order traversal:"<<endl;
    // levelOrderTraversal(root);

    // cout<<"Inorder traversal is:"<<endl;
    // inorderTraversal(root);

    // cout<<"Pre Order traversal is:"<<endl;
    // preordertraveral(root);

    // cout<<"Post order traversal:"<<endl;
    // postordertraversal(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
}