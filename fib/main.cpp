//#include <iostream>

//using namespace std;
int f1 = 0;
int f0 = 1;
int fib()
{
    int f = f1;
    f1=f0+f1;
    f0=f;
    return f1;
}

int main()
{
    int fib1 = fib();
    fib1 = fib();
    fib1 = fib();

    return 0;
}
