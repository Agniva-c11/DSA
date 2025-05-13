#include<iostream>
using namespace std;

void print(int *p)
{
    cout<<"Value is:"<<*p<<endl;
}

void update(int *p)
{
    p = p + 1;
    cout<<"Inside Function:"<<p<<endl;

    *p = *p + 1;
}

int main()
{
    int value = 50;
    int *p = &value;

    // print(p);

    cout<<"Before:"<<*p<<endl;
    update(p);
    cout<<"After:"<<*p<<endl;

}