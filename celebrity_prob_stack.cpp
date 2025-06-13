#include<iostream>
#include<stack>
using namespace std;
const int n = 3;

bool knows(int mat[n][n], int a, int b)
{
    if(mat[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(int mat[n][n])
{
    stack<int> s;
    for(int i = 0;i<n;i++)
    {
        s.push(i);
    }

    while(s.size()>1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(mat, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    int candidate = s.top();
    for(int i = 0;i<n;i++)
    {
        if(i != candidate && mat[candidate][i] == 1)
        {
            return -1;
        }
    }

    for(int i = 0;i<n;i++)
    {
        if(i != candidate && mat[i][candidate]==0)
        {
            return -1;
        }
    }

    return candidate;

}

int main()
{
    int mat[n][n] = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int result = celebrity(mat);
    cout<<result<<endl;
}