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

Node* getMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast ->next ->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    while(curr)
    {
        Node* next1 = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = next1;
    }
    return prev;
}

bool isPalindrome(Node* &head)
{
    if(head->next == NULL)
    {
        return true;
    }
    Node* middle = getMid(head);

    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL)
    {
        if(head1 ->data != head2 -> data)
        {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    temp = middle->next;
    middle->next = reverse(temp);
    return true;
    
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertData(head, tail, 1);
    InsertData(head, tail, 2);
    InsertData(head, tail, 2);
    InsertData(head, tail, 1);

    if(isPalindrome(head))
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"Not Palindrome";
    }

    
}