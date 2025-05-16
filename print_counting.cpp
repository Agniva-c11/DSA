#include<iostream>
using namespace std;
void print_number(int n)
{
    if(n==0)
    {
        return;
    }

    cout<<n<<endl;
    print_number(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<endl;

    print_number(n);
}