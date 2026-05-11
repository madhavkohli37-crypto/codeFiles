#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int dp[105][100005];
int n,tw;
 int w[105];
 int v[105];
int F(int i,int r) {
  if(r<0) {
    return INT_MIN;
  }
  if(dp[i][r]!=-1) {
    return dp[i][r];
  }
  if(i==n) {
    dp[i][r]=0;
    return 0;
  }
  int op1=v[i]+F(i+1,r-w[i]);
  int op2=F(i+1,r);
  dp[i][r]=max(op1,op2);
  return max(op1,op2);
}
int32_t main() {
  cin>>n>>tw;
  for(int i=0;i<n;i++) {
    cin>>w[i]>>v[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<F(0,tw)<<endl;
 
}
