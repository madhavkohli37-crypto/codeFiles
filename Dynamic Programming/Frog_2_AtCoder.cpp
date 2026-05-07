#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
int dp[100000 + 5];
int F(int i,vector<int>&h,int k) {
  if(dp[i]!=-1) {
    return dp[i];
  }
 int op=0;
 int mini=INT_MAX;
 for(int j=i+1;((j<h.size()) and ((j-i)<=k));j++) {
   op=abs(h[i]-h[j])+F(j,h,k);
   if(op<mini) {
     mini=op;
   }
 }
  dp[i]=mini;
  return dp[i];
}
int main() {
  int n;
  cin>>n;
  int k;
  cin>>k;
  vector<int>h(n,0);
  for(int i=0;i<n;i++) {
    cin>>h[i];
  }
  memset(dp,-1,sizeof(dp));
  dp[n-2]=abs(h[n-2]-h[n-1]);
  dp[n]=0;
  dp[n-1]=0;
  cout<<F(0,h,k);
}
