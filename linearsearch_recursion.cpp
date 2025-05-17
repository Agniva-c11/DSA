#include<iostream>
using namespace std;
bool LinearSearch(int arr[], int n, int key)
{
    if(n==0)
    {
        return false;
    }

    if(arr[0]==key)
    {
        return true;
    }
    else
    {
        bool remainder = LinearSearch(arr+1, n-1, key);
        return remainder;
    }
}
int main()
{
    int n;
    cout<<"Enter size:";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    int key;
    cin>>key;

    if(LinearSearch( arr, n, key))
    {
        cout<<"Present";
    }
    else
    {
        cout<<"Absent";
    }

}
