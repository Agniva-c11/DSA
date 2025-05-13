#include<iostream>
using namespace std;
int lengthAftertransformation(string s, int t)
{
    while(t!=0)
    {
        for(char ch:s)
        {
            if(ch == 'z')
            {
                s.replace(ch,1, "ab");
            }
            else
            {
                ch = ch + 1;
            }
        }
        t--;
    }
    return s.size();
}
int main()
{
    string s = "abcyy";
    int t = 2;

    cout<<"Length:"<<lengthAftertransformation(s, t);

}