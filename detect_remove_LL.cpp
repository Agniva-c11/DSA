#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

// Insertion in circular linked list
void InsertNode(Node*& tail, int element, int data) {
    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    } else {
        Node* curr = tail;

        // Find the node with 'element' data
        do {
            if (curr->data == element) {
                break;
            }
            curr = curr->next;
        } while (curr != tail);

        // Element found, insert after it
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;

        // Update tail if inserting after the current tail
        if (curr == tail) {
            tail = temp;
        }
    }
}

// Detect loop
bool detectloop(Node* head)
{
    if(head == NULL)
    {
        return false;
    }

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL)
    {
        if(visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

// Floyd Cycle
Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast)
        {
            cout <<"Loop at:"<<slow-> data<<endl;
            return slow;
        }
    }
    return 0;

}

// starting node of loop
Node* getStartingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

// remove loop
void removeloop(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    Node* startloop = getStartingNode(head);
    Node* temp = startloop;
    while(temp -> next != startloop)
    {
        temp = temp -> next;
    }

    temp -> next = NULL;
}

// Print circular linked list
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    InsertNode(tail, 5, 3);   // Since list is empty, 'element' doesn't matter
    print(tail);

    InsertNode(tail, 3, 31);
    print(tail);

    InsertNode(tail, 31, 5);
    print(tail);

    InsertNode(tail, 5, 7);
    print(tail);

    cout <<"Loop present: "<< detectloop(tail)<< endl;
    cout <<"Floyd Detect Loop:"<<floydDetectLoop(tail)<<endl;
    Node* loop = getStartingNode(tail);
    cout <<"Loop:"<<loop -> data;

    removeloop(tail);
    print(tail);

    return 0;
}
