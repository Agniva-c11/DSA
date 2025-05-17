#include<iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    if(n==0 || n==1)
    {
        return true;
    }

    if(arr[0]>arr[1])
    {
        return false;
    }
    else
    {
        bool remainder = isSorted(arr+1, n-1);
        return remainder;
    }
}
int main()
{
    int n = 5;
    int arr[n] = {1, 9, 3, 4, 5};

    bool ans = isSorted(arr, n);
    cout<<ans<<endl;
}