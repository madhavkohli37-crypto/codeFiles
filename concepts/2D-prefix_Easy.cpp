#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int a[4][4];
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cin>>a[i][j];
        }
    }
    int prefix[4][4];
    
    for(int i=0;i<4;i++) {
        prefix[i][0]=a[i][0];
    }
    for(int i=0;i<4;i++) {
        for(int j=1;j<4;j++) {
            prefix[i][j]=prefix[i][j-1]+a[i][j];
        }
    }
    for(int i=1;i<4;i++) {
        for(int j=0;j<4;j++) {
            prefix[i][j]+=prefix[i-1][j];
        }
    }
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout<<prefix[i][j]<<" ";
        }
        cout<<endl;
    }
}
   
