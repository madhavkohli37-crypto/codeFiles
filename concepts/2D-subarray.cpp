#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   int a[10][10];
   for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++) {
        cin>>a[i][j];
    }
   }
   long long prefix[15][15];
   prefix[0][0]=a[0][0];
   for(int i=1;i<10;i++) {
    prefix[0][i]=prefix[0][i-1]+a[0][i];
   }
   for(int i=1;i<10;i++) {
    prefix[i][0]=prefix[i-1][0]+a[i][0];
   }
   for(int i=1;i<10;i++) {
    for(int j=1;j<10;j++) {
        prefix[i][j]=-prefix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]+a[i][j];
    }
   }
   for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++) {
        cout<<prefix[i][j]<<" ";
    }
    cout<<endl;
   }
}
