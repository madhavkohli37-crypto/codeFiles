#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int n;
 int a[100005];
 int b[100005];
 int c[100005];
 int dp[100005][3];
int F() {
  for(int i=2;i<=n;i++) {
    dp[i][0]=a[i-1]+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1]=b[i-1]+max(dp[i-1][0],dp[i-1][2]);
    dp[i][2]=c[i-1]+max(dp[i-1][0],dp[i-1][1]);
  }
  return max({dp[n][0],dp[n][1],dp[n][2]});
}
int32_t main() {
  cin>>n;
 
  for(int i=0;i<n;i++) {
    cin>>a[i]>>b[i]>>c[i];
  }
  memset(dp,-1,sizeof(dp));
  dp[1][0]=a[0];
  dp[1][1]=b[0];
  dp[1][2]=c[0];
  
  cout<<F();
}
