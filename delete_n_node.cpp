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

Node* reverse(Node* &head)
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
    return head;
    
}

void delete_n_node(Node* &head, int position)
{
    Node* curr = head;
    Node* prev = NULL;

    int cnt = 0;
    while(cnt<=position)
    {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
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
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int n = 2;
    InsertData(head, tail, 1);
    InsertData(head, tail, 2);
    InsertData(head, tail, 3);
    InsertData(head, tail, 4);
    InsertData(head, tail, 5);
    print(head);

    reverse(head);

    delete_n_node(head, n);
    reverse(head);
    print(head);

}