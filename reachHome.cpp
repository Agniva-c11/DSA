#include<iostream>
using namespace std;
void reachHome(int src, int dest)
{
    cout<<"src: "<<src<<" "<<"dest: "<<dest<<endl;
    if(src==dest)
    {
        return;
    }
    
    src++;
    reachHome(src, dest);
}
int main()
{
    int src = 1;
    int dest = 10;

    reachHome(src, dest);
}