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

Node* newNode(int data) {
    Node* temp = new Node(data);
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

Node* getMid(Node* head) {
    if (head == NULL || head->next == head)
        return head; // 0 or 1 node

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* split(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    return head;

}

int main()
{
    Node* head = newNode(10);
    head -> next = newNode(4);
    head -> next -> next = newNode(9);
    head -> next -> next -> next = newNode(10);
    head -> next -> next -> next -> next = head;

    Node* mid = getMid(head);
    Node* rightHead = mid->next;
    mid->next = NULL;

    Node* left = head;
    Node* right = rightHead;
    cout<<split(left);
    cout<<endl;
    cout<<split(rightHead);
}