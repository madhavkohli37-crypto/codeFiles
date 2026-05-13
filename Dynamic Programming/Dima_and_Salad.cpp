#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
#define int long long
int n,k;
const int neg=-1e18;
const int offset=100005;
vector<int>t;
vector<int>c;
int dp[105][200005];
int F(int i,int p) {
  if(dp[i][p+offset]!=-1) {
    return dp[i][p+offset];
  }
  if(i==n) {
    if(p==0) {
      return 0;
    }
    else {
      return neg;
    }
  }
  int op1=t[i]+F(i+1,p+t[i]-k*c[i]);
  int op2=F(i+1,p);
  return (dp[i][p+offset]=max(op1,op2));
}
int32_t main() { 
  cin>>n>>k;
  for(int i=0;i<n;i++) {
    int x;
    cin>>x;
    t.push_back(x);
  }
  for(int i=0;i<n;i++) {
    int x;
    cin>>x;
    c.push_back(x);
  }
  memset(dp,-1,sizeof(dp));
  int ans=F(0,0);
  if(!ans) {
    cout<<-1<<endl;
  }
  else {
    cout<<ans<<endl;
  }
}
