#include<iostream>
using namespace std;
void reverse_string(string& s, int i, int j)
{
    if(i>j)
    {
        return;
    }

    swap(s[i], s[j]);
    i++;
    j--;

    reverse_string(s, i, j);
}
int main()
{
    string s = "Shreye";
    reverse_string(s, 0, s.size()-1);
    cout<<s<<endl;
}