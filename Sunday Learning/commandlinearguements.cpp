#include<bits/stdc++.h>
using namespace std;
int main(int args,char* argvs[]) {//the format is int , char* [] only
    cout<<"Number of Arguements :"<<args<<endl;
    for(int i=0;i<args;i++) {
        cout<<argvs[i]<<endl;
    }
}
input in terminal g++ (filename).cpp -o (name)
./(name) arguement_1 arguement_2 ... arguement_n
output arguements : n+1
./(name)
arguement_1
arguement_2
.
.
arguement_n
in cmd
g++ (filename).cpp -o (name)--> to compile
(filename) direct run 
output 
arguements : n+1
(filename)
arguement_1
arguement_2
.
.
arguement_n
this is because ./(filename) and (filename) are treated as arguements 
so do
cout<<"Number of Arguements :"<<args-1<<endl;