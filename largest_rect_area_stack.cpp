#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
vector<int> nextSmallerElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--)
    {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    for(int i = 0;i<n;i++)
    {
        if(ans[i] == -1)
        {
            ans[i] = n;
        }
    }
    return ans;
}

vector<int> prevSmallerElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0;i<n;i++)
    {
        int curr = arr[i];
        while(s.top()!= -1 && arr[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int maxRectArea(int arr[], int n)
{
    vector<int> next;
    next = nextSmallerElement(arr, n);

    vector<int> prev;
    prev = prevSmallerElement(arr, n);

    int area = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        int l = arr[i];
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int main()
{
    int n = 6;
    int arr[n] = {2, 1, 5, 6, 2, 3};

    int result = maxRectArea(arr, n);
    cout<<"Area of largest rectangle:"<<result<<endl;
}