#include<iostream>
using namespace std;

void fibonacci(int a, int b, int n, int count)
{
    if (count >= n) return; // base condition to stop recursion

    int summ = a + b;
    cout << summ << " ";
    fibonacci(b, summ, n, count + 1);
}

int main()
{
    int a = 0;
    int b = 1;
    int n; // number of terms to print
    cout << "Enter number of Fibonacci terms to print: ";
    cin >> n;

    if (n <= 0) {
        cout << "Enter a positive number.";
        return 0;
    }

    cout << a << " ";
    if (n > 1) cout << b << " ";

    fibonacci(a, b, n, 2); // already printed 2 terms
    return 0;
}
 