#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
const int NEG = -1e18;
int dp[105][100005];
int n,tw;
 int w[105];
 int v[105];
void F() {
  for(int i=1;i<=n;i++) {
    for(int wt=tw;wt>=0;wt--) {
      int op1=dp[i-1][wt];
      int op2=NEG;
      if((wt-w[i])>=0) {
        op2=dp[i-1][wt-w[i]]+v[i];
      }
      dp[i][wt]=max(op1,op2);
    }
  }
}
int32_t main() {
  cin>>n>>tw;
  for(int i=1;i<=n;i++) {
    cin>>w[i]>>v[i];
  }
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<=tw;i++) {
    dp[0][i]=0;
  }
  F();
  cout<<dp[n][tw]<<endl;
 
}
