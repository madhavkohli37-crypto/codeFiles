#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    int prefix[n][m];
    
    for(int i=0;i<n;i++) {
        prefix[i][0]=a[i][0];
    }
    for(int i=0;i<n;i++) {
        for(int j=1;j<m;j++) {
            prefix[i][j]=prefix[i][j-1]+a[i][j];
        }
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            prefix[i][j]+=prefix[i-1][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<prefix[i][j]<<" ";
        }
        cout<<endl;
    }
}
   
