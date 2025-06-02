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

Node* sortlist(Node* &head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp =head;
    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            zeroCount++;
        }
        else if(temp->data == 1)
        {
            oneCount++;
        }
        else if(temp->data == 2)
        {
            twoCount++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL)
    {
        if(zeroCount!=0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount!=0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount!=0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}

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

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
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
    InsertData(head, tail, 1);
    InsertData(head, tail, 2);
    InsertData(head, tail, 2);
    InsertData(head, tail, 0);
    InsertData(head, tail, 1);
    InsertData(head, tail, 0);
    print(head);

    sortlist(head);
    print(head);

}