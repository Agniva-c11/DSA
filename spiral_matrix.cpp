#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralorder(const vector<vector<int>>& arr)
{
    int row = arr.size();
    int col = arr[0].size();
    int count = 0;
    int total = row*col;

    vector<int> ans;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count<total)
    {
        // Starting Row
        for(int i = startingCol;i<=endingCol;i++)
        {
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;

        // Ending Column
        for(int i = startingRow;i<=endingRow;i++)
        {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;

        // Ending Row
        for(int i = endingCol;i>=startingCol;i--)
        {
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;

        // Starting Column
        for(int i = endingRow;i>=startingRow;i--)
        {
            ans.push_back(arr[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<int> result;

    vector<vector<int>> arr(n, vector<int> (m));

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    result = spiralorder(arr);
    for(int i =0;i<result.size();i++)
    {
        cout<<result[i];
    }
}