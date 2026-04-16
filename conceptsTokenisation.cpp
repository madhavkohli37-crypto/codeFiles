#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int32_t main() {
    char a[100];
    cin.getline(a,100);
    char *token = strtok(a," ");
    while(token!=nullptr) {
        cout<<token<<endl;
        token=strtok(NULL," ");
    }
    // input:-
    // My         name is Madhav Kohli 
    // Output :-
//       My
//       name
//       is
//       Madhav
//       Kohli
 // input:-
    // My name is Madhav Kohli 
    // Output :-
//       My
//       name
//       is
//       Madhav
//       Kohli

}
