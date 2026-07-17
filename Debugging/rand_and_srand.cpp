#include<iostream>
#include<chrono>//header file for time function
#include<cstring>
using namespace std;
int main() {
    srand(time(0));//srand() function is used to change the seed in c++
    // if we do not change the seed then the number generated everytime will be same 
    // cout<<rand()<<endl; --> if we write this wothout using srand() then same number will be
    // generated everytime
    // hence to generate a different number we use srand() function nd we send a seed inside it
    // the seed we use is time because two time can never be same
    // hence we use srand(time(0)) to indicate that current time is treated as 0(in short we use time becaue it will alwasy be unique at every moment)
    cout<<rand()<<endl;// rand() function is used to generate random numbers
}