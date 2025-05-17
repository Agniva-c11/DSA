#include<iostream>
using namespace std;
bool checkPalindrome(string s, int i, int j)
{
    if(i>j)
    {
        return true;
    }

    if(s[i]!=s[j])
    {
        return false;
    }
    else
    {
        return checkPalindrome(s, i+1, j-1);
    }
}
int main()
{
    string s = "abba";

    bool isPalindrome = checkPalindrome(s, 0, s.size()-1);
    if(isPalindrome)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}