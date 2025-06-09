#include<iostream>
#include<stack>
using namespace std;
void add_last(stack<int> &st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    add_last(st, x);
    st.push(num);
}

void printStack(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int> st;
    int x = 9;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    printStack(st);
    add_last(st, x);
    printStack(st);

}