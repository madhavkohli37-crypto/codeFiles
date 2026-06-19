#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
int dp[105][100005];
int n;
int k;
const int MOD=1000000007;
void solve() {
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            if(j-a[i-1]>0 ) {
                dp[i][j]=(dp[i][j]+MOD-dp[i-1][j-a[i-1]-1])%MOD;
            }
        }
    }
}
int32_t main() {
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=a[0];i++) {
        dp[1][i]=1;
    }
    for(int i=1;i<=n;i++) {
        dp[i][0]=1;
    }
    solve();
    cout<<dp[n][k]%MOD;
}
