#include <iostream>
#include <string>
using namespace std;

// Corrected function with 2D array as parameter
string findpath(int arr[][4], int n)
{
    string ans;
    int srcx = 0;
    int srcy = 0;

    int visited[4][4];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            visited[i][j] = 0;
        }
    }
}

int main()
{
    int n = 4;
    int arr[4][4];

    // Input the 2D array
    for (int i = 0; i < n; i++)                      
    {                                           
        for (int j = 0; j < n; j++)                  
        {                                                       
            cin >> arr[i][j];
        }
    }

    // Call the function and print the result
    string result = findpath(arr, n);
    cout << result << endl;

    return 0;
}
