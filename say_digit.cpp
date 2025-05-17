// Input = 123
// Output = One Two Three

#include<iostream>
using namespace std;
string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

void say_digit(int n)
{
    if(n==0)
    {
        return;
    }

    say_digit(n/10);

    cout<<arr[n%10]<<" ";
}
int main()
{
    int n;
    cout<<"Enter number:";
    cin>>n;

    if(n==0)
    {
        cout<<"Zero";
    }
    else
    {
        say_digit(n);
        cout<<endl;
    }
}