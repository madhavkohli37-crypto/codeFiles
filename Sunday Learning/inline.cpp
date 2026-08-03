#include<bits/stdc++.h>
using namespace std;
inline void F(int n) {//inline is a request to the compiler that may or may not be completed 
    // it will be fulfilld by the compiler if the function is small and is reused multiple times
    // it executes faster with inline and removes the function call overhead and brings the chunk of code to the place it is called
    for(int i=0;i<n;i++) {
        cout<<i<<endl;
    }
    return;
}
int main() {
    F(10);
}