#include<iostream>
#include<string>
using namespace std;

string remove_substring(string s, string part)
{
    while(s.length()!=0 && s.find(part)<s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;

}

int main()
{
    string s;
    cout<<"Enter s:";
    getline(cin, s);

    string part;
    cout<<"Enter part:";
    getline(cin, part);

    cout<<remove_substring(s, part)<<endl;


}