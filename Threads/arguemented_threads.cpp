#include <iostream>
#include <thread>
using namespace std;

void f(int x)
{
    cout << "x = " << x << endl;
}

int main()
{
    thread t(f, 10);//send arguements like this (function_name,arg1,arg2,...,argn)

    t.join();

    return 0;
}