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
            this -> next = NULL;
        }
        cout<< "The memory is free for node with data "<< value << endl;
    }

};

void InsertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int data)
{
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &tail, Node* &head, int position, int data)
{
    if(position == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int cnt =1;

    while(cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }

    Node* Nodetoinsert = new Node(data);
    Nodetoinsert->next = temp->next;
    temp -> next = Nodetoinsert;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void deleteNode(int position, Node* &head)
{
    // deleting first node or start node
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;

    }
    else
    {
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}

int main()
{
    Node* node1 = new Node(11);
    // cout << node1 -> data<< endl;
    // cout << node1 -> next<<endl;

    Node* head = node1;
    Node* tail = node1;
    InsertAtTail(tail, 12);
    print(head);
    InsertAtTail(tail, 13);
    print(head);

    InsertAtPosition(tail, head, 1, 22);
    print(head);

    cout << "head:" << head -> data << endl;
    cout << "tail:" << tail -> data << endl;

    deleteNode(1, head);
    print(head);

}