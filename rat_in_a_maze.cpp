#include<iostream>
using namespace std;
int main()
{
    int n = 4;
    int arr[n][n];

    for(int i = 0;i<n;i++)                      //up = (x-1, y)
    {                                           //down = (x+1, y)
        for(int j = 0;j<n;j++)                  //left = (x, y-1)
        {                                       //right = (x, y+1)                
            cin>>arr[i][j];
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}