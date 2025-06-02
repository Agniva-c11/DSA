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

void insertData(Node* &head, Node* &tail, int data)
{
    Node* temp = new Node(data);
    if(head ==NULL)
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
    while(temp != NULL)
    {
        cout << temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* mergeSortedLists(Node* head1, Node* head2) {
    // Dummy node to help with the result list
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    // Traverse both lists
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // If there are remaining nodes in any list
    if (head1 != NULL) tail->next = head1;
    if (head2 != NULL) tail->next = head2;

    Node* result = dummy->next;
    delete dummy; // free dummy node
    return result;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertData(head, tail, 1);
    insertData(head, tail, 2);
    insertData(head, tail, 3);
    print(head);

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertData(head2, tail2, 4);
    insertData(head2, tail2, 5);
    insertData(head2, tail2, 6);
    print(head2);

    Node* result = mergeSortedLists(head, head2);
    print(result);
}