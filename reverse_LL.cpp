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
    if(head== NULL)
    {
        head= temp;
        tail = temp;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
}

void reverse_LL(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node* forward = curr -> next;
        curr->next = prev;
        prev = curr;
        curr=forward;
    }
    head = prev;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data<<" ";
        temp = temp -> next;
    }
    cout << endl;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0;i<5;i++)
    {
        InsertData(head, tail, i);
    }

    print(head);
    cout<<"head: "<<head -> data <<endl;
    cout <<"tail: "<<tail -> data<<endl;

    reverse_LL(head);
    print(head);
    cout<<"head: "<<head -> data <<endl;
    cout <<"tail: "<<tail -> data<<endl;



}