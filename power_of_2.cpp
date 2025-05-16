#include<iostream>
using namespace std;
int power_of_2(int n)
{
    if(n==0)
    {
        return 1;
    }

    return 2 * power_of_2(n-1);
}
int main()
{
    int n;
    cin>>n;

    int ans = power_of_2(n);
    cout<<ans<<endl;
}