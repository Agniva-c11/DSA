#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    int n = 4;
    int arr[n] = {3, 5, 1, 2};

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--)
    {
        int curr = arr[i];
        while(s.top()>=curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    for(int i = 0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}