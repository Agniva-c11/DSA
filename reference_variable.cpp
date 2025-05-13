#include<iostream>
using namespace std;
void update(int& j)
{
    j++;
}
int main()
{
    /*
    int i = 5;

    int &j = i;     //Reference Variable

    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;
    */

    int i = 5;
    cout<<"Before:"<<i<<endl;
    update(i);
    cout<<"After:"<<i<<endl;
}