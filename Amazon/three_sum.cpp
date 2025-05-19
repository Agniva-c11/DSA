#include<iostream>
#include<algorithm>
using namespace std;
bool three_sum(int arr[], int n)
{
    for(int i = 0;i<n;i++)
    {
        arr[i] = arr[i] * arr[i];
    }

    sort(arr, arr+n);

    for(int i = n-1;i>1;i--)
    {
        int left = 0, right = i-1;
        while(left<right)
        {
            if(arr[left]+arr[right]==arr[i])
            {
                return true;
            }
            else if(arr[left]+arr[right]<arr[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return false;


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

    if(three_sum(arr, n))
    {
        cout<<"Present";
    }
    else
    {
        cout<<"Absent";
    }
}