#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<"Front of queue is:"<<q.front()<<endl;
    cout<<"Back of queue is:"<<q.back()<<endl;

    cout<<"Size of queue:"<<q.size()<<endl;

    q.pop();

    cout<<"Size of queue after popping:"<<q.size()<<endl;

    if(q.empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl;
    }
}