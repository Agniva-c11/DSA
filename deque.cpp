#include<iostream>
#include<queue>
using namespace std;
int main()
{
    deque<int> d;
    d.push_front(22);
    d.push_back(101);
    d.push_back(300);
    d.push_front(32);

    cout<<d.front()<<endl;

    cout<<d.back()<<endl;

    d.pop_front();
    d.pop_back();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    if(d.empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl;
    }
}