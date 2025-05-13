#include<iostream>
using namespace std;
int main()
{
    int num = 5;
    cout<<num<<endl;

    // Address of operator
    cout<<"Address of Operator:"<<&num<<endl;


    int *p = &num;
    cout<<p<<endl;
    cout<<*p<<endl;
}