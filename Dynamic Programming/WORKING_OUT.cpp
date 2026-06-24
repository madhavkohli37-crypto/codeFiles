#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int grid[1000][1000];
int dp1[1000][1000];
int dp2[1000][1000];
int dp3[1000][1000];
int dp4[1000][1000];
int32_t main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    dp1[0][0]=grid[0][0];
    for(int i=1;i<n;i++) {
        dp1[i][0]=dp1[i-1][0]+grid[i][0];
    }
    for(int i=1;i<m;i++) {
        dp1[0][i]=dp1[0][i-1]+grid[0][i];
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+grid[i][j];
        }
    }
    dp2[n-1][m-1]=grid[n-1][m-1];
    for(int i=n-2;i>=0;i--) {
        dp2[i][m-1]=dp2[i+1][m-1]+grid[i][m-1];
    }
    for(int i=m-2;i>=0;i--) {
        dp2[n-1][i]=dp2[n-1][i+1]+grid[n-1][i];
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=m-2;j>=0;j--) {
            dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+grid[i][j];
        }
    }
    dp3[n-1][0]=grid[n-1][0];
    for(int i=n-2;i>=0;i--) {
        dp3[i][0]=dp3[i+1][0]+grid[i][0];
    }
    for(int i=1;i<m;i++) {
        dp3[n-1][i]=dp3[n-1][i-1]+grid[n-1][i];
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=1;j<m;j++) {
            dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+grid[i][j];
        }
    }
    dp4[0][m-1]=grid[0][m-1];
     for(int i=m-2;i>=0;i--) {
        dp4[0][i]=dp4[0][i+1]+grid[0][i];
    }
    for(int i=1;i<n;i++) {
        dp4[i][m-1]=dp4[i-1][m-1]+grid[i][m-1];
    }
    for(int i=1;i<n;i++) {
        for(int j=m-2;j>=0;j--) {
            dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+grid[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<m-1;j++) {
            int op1=dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1];
            int op2=dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j];
            int value=max(op1,op2);
            ans=max(ans,value);
        }
    }
    cout<<ans<<endl;
    
}

   
