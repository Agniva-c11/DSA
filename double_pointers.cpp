#include<iostream>
using namespace std;
void update(int** p)
{
    **p = **p+1;
    cout<<**p<<endl;
}
int main()
{
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    // cout<<"Value of i:"<<i<<endl;
    // cout<<"Address of i in p:"<<p<<endl;
    // cout<<"Value of i in p:"<<*p<<endl;
    // cout<<"Address of p in p2:"<<p2<<endl;
    // cout<<"Value of p in p2:"<<*p2<<endl;
    // cout<<"Value of p in p2:"<<**p2<<endl;

    // cout<<"Address of i:"<<&i<<endl;
    // cout<<"Address stored in p of i:"<<p<<endl;
    // cout<<"Address of i stored in p stored in p2:"<<*p2<<endl;
    // cout<<"Before:"<<**p2<<endl;
    // cout<<"After:";
    // update(p2);

    int first = 8;
    int second = 18;
    int *ptr = &second;
    *ptr = 9;
    cout<<first<<"  "<<second<<endl;
}