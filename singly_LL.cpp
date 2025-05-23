#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
} 

void InsertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp-> next;
    } 
    cout<<endl;
}
int main()
{
    // Creating new node
    Node* node1 = new Node(11);
    // cout<< node1 -> data << endl;
    // cout<< node1 -> next << endl;

    // Pointing head to new node
    Node* head = node1;

    // Pointing tail to new node
    Node* tail = node1;

    print(head);
    InsertAtTail(tail, 12);
    print(head);
    InsertAtTail(tail, 13);
    print(head);
}