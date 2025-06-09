#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &s, int count, int n)
{
    if(count == n/2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, count+1, n);
    s.push(num);
}

void printStack(stack<int> &s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(9);
    s.push(12);
    s.push(8);
    s.push(4);

    int n = s.size();
    int count = 0;

    solve(s, count, n);

    cout<<"After deleting middle element:"<<endl;
    printStack(s);
}