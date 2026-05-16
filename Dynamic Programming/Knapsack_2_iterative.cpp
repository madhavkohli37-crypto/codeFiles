#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
const int POS = 1e18;
int ans=-1e18;
int N=0;
int dp[105][100005];
int n,tw;
 int w[105];
 int v[105];
void F() {
  for(int i=1;i<=n;i++) {
    for(int val=N;val>=0;val--) {
      int op1=dp[i-1][val];
      int op2=POS;
      if((val-v[i])>=0) {
        op2=dp[i-1][val-v[i]]+w[i];
      }
      dp[i][val]=min(op1,op2);
      if(dp[i][val]<=tw) {
        if(ans<val) {
          ans=val;
        }
      }
    }
  }
}
int32_t main() {
  cin>>n>>tw;
  for(int i=1;i<=n;i++) {
    cin>>w[i]>>v[i];
    N+=v[i];
  }
  for(int i=0;i<=N;i++) {
    dp[0][i]=POS;
  }
  dp[0][0]=0;
  F();
  cout<<ans<<endl;
}
