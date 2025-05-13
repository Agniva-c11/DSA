#include<iostream>
#include<cmath>
using namespace std;

bool isPower2(int n)
{
    if(n<=0)
    {
        return false;
    }

    int logvalue = log2(n);

    return pow(2, logvalue) == n;
}

int main()
{
    int n;
    cin>>n;

    if(isPower2(n))
    {
        cout<<"It is power of 2";
    }
    else
    {
        cout<<"It is not power of 2";
    }
}