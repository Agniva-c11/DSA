#include<iostream>
#include<vector>
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

void reverse(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr)
    {
        Node* next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    head = prev;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* add_2_LL(Node* &head1, Node* &head2)
{
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while(head1 || head2 || carry != 0)
    {
        int val1 = head1->data;
        int val2 = head2->data;
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        carry = sum / 10;
        InsertData(ansHead, ansTail, digit);
        head1 = head1->next;
        head2 = head2->next;
    }
    return ansHead;
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    InsertData(head1, tail1, 1);
    InsertData(head1, tail1, 1);
    InsertData(head1, tail1, 1);
    InsertData(head2, tail2, 1);
    InsertData(head2, tail2, 1);
    InsertData(head2, tail2, 1);

    print(head1);
    print(head2);

    cout<<"After reversal"<<endl;

    reverse(head1);
    reverse(head2);

    print(head1);
    print(head2);

    cout<<"Addition of two linked lists:"<<endl;
    Node* result = add_2_LL(head1, head2);
    print(result);

    
}