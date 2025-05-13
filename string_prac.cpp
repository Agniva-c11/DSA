#include<iostream>
using namespace std;
int mintimetotype(string s)
{
    int ans = s.size();
    int cur = 1;
    for(char c:s)
    {
        int pos = c - 96;
        int diff = abs(pos-cur);
        ans = ans + min(diff, 26-diff);
        cur = pos;
    }
    return ans;
}
int main()
{
    string s;
    cout<<"Enter string:";
    cin>>s;

    cout<<mintimetotype(s)<<endl;
}