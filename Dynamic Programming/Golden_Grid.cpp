#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int prefix[1005][1005];
int main() {
    int n,m;
    cin>>n>>m; 
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        prefix[x][y]=1;
    }
    for(int i=1;i<=n;i++) {
        prefix[i][1]=prefix[i][1];
    }
    for(int i=1;i<=n;i++) {
        for(int j=2;j<=n;j++) {
            prefix[i][j]=prefix[i][j-1]+prefix[i][j];
        }
    }
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            prefix[i][j]+=prefix[i-1][j];
        }
    }
    int ans=INT_MIN;
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            int p=prefix[i][j];
            int q=abs(prefix[i][n]-prefix[i][j]);
            int r=abs(prefix[n][j]-prefix[i][j]);
            int s=m-(p+q+r);
            ans=max(ans,min({p,q,r,s}));
        }
    }
    cout<<ans<<endl;
   
}
   
