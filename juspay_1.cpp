#include<iostream>
using namespace std;
string reverse_str(string s)
{
    int i = 0;
    int j = s.length()-1;
    while(i<=j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s;

}
bool solve(string s)
{
    string rev_s = reverse_str(s);
    if(rev_s == s)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s = "poor";

    if(solve(s))
    {
        cout<<"Length of the string:"<<s.length()<<endl;
    }
    else
    {
        cout<<"ASCII value:"<<int(s[0])<<endl;
    }
}