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

bool check_palindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<=e)
    {
        if(arr[s]!=arr[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool isPalindrome(Node* &head)
{
    vector<int> arr;
    Node* temp = head;
    while(temp!= NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return check_palindrome(arr);
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int n = 2;
    InsertData(head, tail, 1);
    InsertData(head, tail, 2);
    InsertData(head, tail, 3);

    bool result = isPalindrome(head);

    if(result)
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"Not Palindrome";
    }
}