#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
const int POS = 1e18;
int N=0;
int dp[105][100005]{{0}};
int n,tw;
 int w[105];
 int v[105];
int F(int i,int val) {
  if(dp[i][val]!=-1) {
    return dp[i][val];
  }
    if(i==0) {
      if(val==0) {
        return dp[i][val]=0;
      }
      else {
        return dp[i][val]=POS;
      }
    }
    int op1=F(i-1,val);
    int op2=POS;
    if(val-v[i]>=0) {
    op2=w[i]+F(i-1,val-v[i]);
    }
    return (dp[i][val]=min(op1,op2));
}
int32_t main() {
  cin>>n>>tw;
  for(int i=1;i<=n;i++) {
    cin>>w[i]>>v[i];
    N+=v[i];
  }
  memset(dp,-1,sizeof(dp));
  dp[0][0]=0;
  for(int val=N;val>=0;val--) {
    if(F(n,val)<=tw) {
      cout<<val<<endl;
      break;
    }
  }
}
