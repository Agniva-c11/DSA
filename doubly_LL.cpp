#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int data)
    {
        this -> data = data;
        this -> prev = NULL;
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

// Traversing a linked list
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

// Length of the linked list
int getLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

// Inserting at head
void InsertAtHead(Node* &tail, Node* &head, int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}

// Insert at tail
void InsertAtTail(Node* &tail,Node* &head, int data)
{
    if(tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    
}

// Insert at any position
void InsertAtPosition(Node* &tail, Node* &head, int position, int data)
{
    // Insert at start
    if(position == 1)
    {
        InsertAtHead(tail, head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    // Insert at the end
    if(temp -> next == NULL)
    {
        InsertAtTail(tail, head, data);
        return;
    }

    // Insert at position
    Node* NodetoInsert = new Node(data);
    NodetoInsert->next = temp -> next;
    temp->next->prev = NodetoInsert;
    temp -> next = NodetoInsert;
    NodetoInsert-> prev = temp;
}

// Deletion
void deleteNode(Node* &head, int position)
{
    // Delete at first
    if(position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
         
        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next  = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    // cout << getLength(head)<< endl;

    InsertAtHead(tail, head, 12);
    print(head);
    InsertAtHead(tail,head, 2);
    print(head);
    InsertAtHead(tail, head, 22);
    print(head);

    InsertAtTail(tail,head, 25);
    print(head);

    InsertAtPosition(tail, head, 2, 1000);
    print(head);
    InsertAtPosition(tail, head, 1, 2000000);
    print(head);
    InsertAtPosition(tail, head, 7, 102);
    print(head);

    cout<<"head: "<<head -> data << endl;
    cout<<"tail: "<<tail->data<<endl;

    deleteNode(head, 1);
    print(head);
    deleteNode(head, 3);
    print(head);
}