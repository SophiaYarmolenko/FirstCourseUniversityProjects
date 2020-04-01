//fib.hpp
#ifndef FIB_HPP_INCLUDED
#define FIB_HPP_INCLUDED
class fib
{
private:
    int f0=0, f1=1;
public:
    fib();
    int next();
    void reset(int g00, int g11);
    /*int numb1(int n1);
    int numb2(int n2);*/
};
#endif

