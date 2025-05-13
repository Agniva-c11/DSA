#include<iostream>
#include<string>
using namespace std;

char toLowercase(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(string s)
{
    for(int j = 0;j<s.length();j++)
    {
        s[j] = toLowercase(s[j]);
    }

    int start = 0;
    int end = s.length()-1;
    while(start<end)
    {
        if(s[start]!=s[end])
        {
            return 0;
        }
        else
        {
            start++;
            end--;
        }
    }
    return 1;
}
int main()
{
    string s;
    cout<<"Enter s:";
    getline(cin, s);

    if(isPalindrome(s))
    {
        cout<<"Palindrome"<<endl;
    }
    else
    {
        cout<<"Not palindrome"<<endl;
    }

    

}   