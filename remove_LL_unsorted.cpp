#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    // Destructor
    ~Node()
    {
        int val = this -> data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for value with data "<< val << endl;
    }
};

void InsertData(Node* &head, Node* &tail, int data)
{
    Node* temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp!= NULL)
    {
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;

}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
}