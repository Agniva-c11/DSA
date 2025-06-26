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
        int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data"<< value << endl;
    }

};

// Insertion
void InsertNode(Node* &tail, int element, int data)
{   
    // Empty list
    if(tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else
    {
        Node* curr = tail;
        while(curr->data != element)
        {
            curr = curr->next;
        }

        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}

void print(Node* &tail)
{
    Node* temp = tail;
    cout << tail -> data << " ";
    while(tail -> next != temp)
    {
        cout<< tail -> data << " ";
        tail = tail -> next;
    }
}

// Deletion
void deleteNode(Node* &tail, int value)
{
    // Empty list
    if(tail == NULL)
    {
        cout << "List is empty";
        return;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr-> data != value)
        {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr; 
    }


}
int main()
{
    Node* tail = NULL;
    InsertNode(tail, 5, 3);
    print(tail);
    InsertNode(tail, 3, 31);
    print(tail);
}