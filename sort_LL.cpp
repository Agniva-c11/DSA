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
        tail->next = temp;
        tail = temp;
    }
}

Node* getMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow->next;
        fast = fast -> next -> next;
    }
    return slow;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertData(head, tail, 4);
    InsertData(head, tail, 2);
    InsertData(head, tail, 1);
    InsertData(head, tail, 3);

    Node* mid = getMid(head);
    cout<<mid->data<<endl;

    print(head);
}