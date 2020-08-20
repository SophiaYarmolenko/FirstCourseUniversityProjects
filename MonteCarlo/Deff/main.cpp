#include <iostream>
using namespace std;

int f(int & a)
{
    return a--;
}
int g()
{
    int a=0;
#define a (--a)
    int b = f(a)-a;
#undef a
    return b;
}
int s()
{
    int a=0;
#define a (a--)
    int b = (a)-(a);
#undef a
    return b;
}
int main() {
    int b;
    b = g();
    cout << b << endl;
    b = s();
    cout << b << endl;
}
