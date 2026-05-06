#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[100000 + 5];
int F(int i,vector<int>&h) {
  if(dp[i]!=-1) {
    return dp[i];
  }
  int op1 = abs(h[i]-h[i+2])+F(i+2,h);
  int op2 = abs(h[i]-h[i+1])+F(i+1,h);
  dp[i]=min(op1,op2);
  return dp[i];
}
int main() {
  int n;
  cin>>n;
  vector<int>h(n,0);
  for(int i=0;i<n;i++) {
    cin>>h[i];
  }
  memset(dp,-1,sizeof(dp));
  dp[n-2]=abs(h[n-2]-h[n-1]);
  dp[n]=0;
  dp[n-1]=0;
  cout<<F(0,h);
}
