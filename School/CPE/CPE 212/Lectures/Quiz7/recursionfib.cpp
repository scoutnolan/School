#include <iostream>

using namespace std;

int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    else
    {
        return fib(n-1)+fib(n-2);
    }

    // Implement the algorithm recursively
}

int main ()
{
  int n = 9;
  cout << fib(n) << endl;
  return 0;
}