#include<bits/stdc++.h>
using namespace std;
int divi(int a,int b) {
    if(b==0) {
        throw "division by 0";
    }
    return a/b;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
try {
    divi(10,0);
}
// the datatype of this catch will depend only on the value returned from throw.
catch( const char* msg) {
    cout<<msg<<endl;
}
cout<<divi(10,5);

}
/*
operational callstack --> try tries divi(10,0);
it goes to divi function and sees throw "division by 0";
catch catches the message and prints the exception.
*/