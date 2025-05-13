#include<iostream>
#include<vector>
using namespace std;

void row_sum(const vector<vector<int>> &arr, int n, int m)
{
    for(int i = 0;i<n;i++)
    {
        int sum = 0;
        for(int j = 0;j<m;j++)
        {
            sum = sum + arr[i][j];
        }
        cout<<sum<<" ";
    }
}
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

    row_sum(arr, n, m);
}