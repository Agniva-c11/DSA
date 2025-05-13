#include<iostream>
using namespace std;
int main()
{
    // int arr[10] = {1, 20, 3, 4, 5, 6, 7, 8, 9, 0};
    // cout<<"Address:"<<arr<<endl;
    // cout<<"Address:"<<&arr[0]<<endl;

    // cout<<"first value:"<<*arr<<endl;
    // cout<<"first value:"<<*arr+1<<endl;

    // cout<<"second value:"<<*(arr+1)<<endl;

    // cout<<"Value at 4:"<<arr[4]<<endl;
    // cout<<"Value at 4:"<<*(arr+4)<<endl;

    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout<<"Integer Array:"<<arr<<endl;
    cout<<"Character Array:"<<ch<<endl;

    char *c = &ch[0];
    cout<<c<<endl;    //Prints the entire array
    cout<<*c<<endl;


}
