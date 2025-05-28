#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void InsertData(Node*& head, Node*& tail, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

Node* reverse_k(Node* head, int k) {
    if (head == NULL)
        return NULL;

    Node* temp = head;
    int count = 0;

    // Check if there are at least k nodes
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k)
        return head; // Not enough nodes to reverse, return as-is

    // Reverse k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Recurse on the rest of the list
    if (forward != NULL) {
        head->next = reverse_k(forward, k);
    }

    return prev; // New head of this reversed group
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int k;
    cout << "Enter k: ";
    cin >> k;

    for (int i = 1; i <= 5; i++) {
        InsertData(head, tail, i);
    }

    cout << "Original List: ";
    print(head);

    head = reverse_k(head, k);  // Capture the new head
    cout << "Reversed in groups of " << k << ": ";
    print(head);
}
