#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string s)
{
    string result;
    for(char ch:s)
    {
        if(!result.empty() && result.back()==ch)
        {
            result.pop_back();
        }
        else
        {
            result.push_back(ch);
        }
    }
    return result;
}

int main()
{
    string s;
    cout<<"Enter s:";
    getline(cin, s);

    cout<<"Original:"<<s<<endl;
    cout<<"Updated:"<<removeDuplicates(s)<<endl;
}