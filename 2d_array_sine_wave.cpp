#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<vector<int>> arr(n, vector<int> (m));

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Printing in Sine Wave:";

    for(int j = 0;j<m;j++)
    {
        if(j&1)
        {
            for(int i = n-1;i>=0;i--)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        else
        {
            for(int i = 0;i<n;i++)
            {
                cout<<arr[i][j]<<" ";
            }
        }
    }
    
}