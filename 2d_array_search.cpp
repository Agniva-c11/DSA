#include<iostream>
#include<vector>
using namespace std;

bool isPresent(const vector<vector<int>>& arr, int target, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m, target;
    cin >> n >> m >> target;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    if(isPresent(arr, target, n, m))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }
}
